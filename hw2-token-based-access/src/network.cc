#include "network.h"

#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

#include "event/event.h"
#include "network_events.h"
#include "util.h"

using std::cout;
using std::endl;
using std::vector;

Network::Node::Node(int arrival_interval, int next_arrival)
    : kArrivalInterval(arrival_interval),
      next_arrival(next_arrival),
      next_departure(None),
      size(0) {}

Network::Network(EventManager* event_manager)
    : master_clock_(0),
      event_manager_(event_manager) {

 //   event_manager_->AddEventHandler(EventType::ARRIVAL, [&](const Event& e) {
//
//    });
}


void Network::Run(int row_count) {
    cout << "MC\t";
    for (size_t i = 0; i < nodes_.size(); i++) {
        cout << "Arr" << i + 1 << "\t"
            << "Dep" << i + 1 << "\t"
            << "Size" << i + 1 << "\t";
    }
    cout << "Node no\tTimeout\tNext pass" << endl;
    PrintRow();

    for (int i = 0; i < row_count; i++) {
        NextEvent();
    }
}

void Network::PrintRow() const {
    cout << master_clock_ << "\t";

    for (size_t i = 0; i < nodes_.size(); i++) {
        cout << nodes_[i].next_arrival << "\t"
            << nodes_[i].next_departure << "\t"
            << nodes_[i].size << "\t";
    }

    cout << token_.node_no + 1 << "\t"
        << token_.timeout << "\t"
        << token_.next_pass_time << endl;
}

void Network::AddNode(int arrival_interval, int next_arrival) {
    nodes_.push_back(Network::Node(arrival_interval, next_arrival));
}


void Network::NextEvent() {
    vector<int> times; // next event time candidates
    for (auto& node : nodes_) {
        times.push_back(node.next_arrival);
        times.push_back(node.next_departure);
    }
    times.push_back(token_.timeout);
    times.push_back(token_.next_pass_time);

    // Remove the candidates whose value is None (-1).
    times.erase(std::remove_if(times.begin(), times.end(), [](int t) {
        return t == None; }), times.end());

    // Update master clock.
    master_clock_ = util::min(times);

    // Iterate through the event time units and fire the corresponding event(s).
    // First we fire the arrival and departure events (if any)
    for (size_t i = 0; i < nodes_.size(); i++) {
        if (nodes_[i].next_arrival == master_clock_) {
            //event_manager_->FireEvent(ArrivalEvent(i));
            OnPacketArrival(i);
        } else if (nodes_[i].next_departure == master_clock_) {
            //event_manager_->FireEvent(DepartureEvent(i));
            OnPacketDeparture(i);
        }
    }

    
    // Secondly we fire the token related events (if any)
    if (token_.timeout == master_clock_ && nodes_[token_.node_no].next_departure != None) {
        //event_manager_->FireEvent(TokenTimeoutEvent());
        OnTokenTimeout();
    } else if (token_.next_pass_time == master_clock_) {
        //event_manager_->FireEvent(PassTokenEvent());
        OnPassToken();
    }

    PrintRow();
}

void Network::OnPacketArrival(int node_id) {
    Network::Node& node = nodes_[node_id];
    node.size++;

    node.next_arrival += node.kArrivalInterval;
}

void Network::OnPacketDeparture(int node_id) {
    Network::Node& node = nodes_[node_id];
    node.size--;

    if (node.size > 0 && master_clock_ < token_.timeout) {
        node.next_departure += kPacketDepartInterval;
    } else {
        node.next_departure = None;
        token_.timeout = None;
        token_.next_pass_time = master_clock_ + 1;
    }
}

void Network::OnTokenTimeout() {
    // Check if there's ongoing transmission.
    // We should wait until the ongoing transmission is done.
    if (!token_.has_ongoing_transmission) {
        token_.timeout = None;
        token_.next_pass_time = master_clock_ + 1;
    }
}

void Network::OnPassToken() {
    token_.node_no = (token_.node_no + 1) % nodes_.size();
    Network::Node& active_node = nodes_[token_.node_no];

    if (active_node.size > 0) {
        token_.timeout = master_clock_ + 15; // remove this hardcoded shit later
        token_.next_pass_time = None;
        active_node.next_departure = master_clock_ + kPacketDepartInterval;
    } else {
        token_.next_pass_time = master_clock_ + 1;
    }
}
