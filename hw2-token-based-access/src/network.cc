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
using std::ostream;

Network::Node::Node(int arrival_interval, int next_arrival)
    : kArrivalInterval(arrival_interval),
      next_arrival(next_arrival),
      next_departure(None),
      size(0) {}

Network::Network(EventManager* event_manager)
    : event_manager_(event_manager),
      master_clock_(0) {

    event_manager_->AddEventHandler(EventType::ARRIVAL, [&](const Event& e) {
        const ArrivalEvent* ev = dynamic_cast<const ArrivalEvent*>(&e);

        Network::Node& node = nodes_[ev->kNodeId()];
        node.size++;

        node.next_arrival += node.kArrivalInterval;
    });

    event_manager_->AddEventHandler(EventType::DEPARTURE, [&](const Event& e) {
        const DepartureEvent* ev = dynamic_cast<const DepartureEvent*>(&e);

        Network::Node& node = nodes_[ev->kNodeId()];
        node.size--;

        if (node.size > 0 && master_clock_ < token_.timeout) {
            node.next_departure += node.kDepartInterval;
        } else {
            node.next_departure = None;
            token_.timeout = None;
            token_.next_pass_time = master_clock_ + 1;
        }
    });

    event_manager_->AddEventHandler(EventType::TOKEN_TIMEOUT, [&](const Event& e) {
        // Check if there's ongoing transmission.
        // We should wait until the ongoing transmission is done.
        if (nodes_[token_.node_no].next_departure == None) {
            token_.timeout = None;
            token_.next_pass_time = master_clock_ + 1;
        } else {
            token_.timeout = Timeout;
        }
    });

    event_manager_->AddEventHandler(EventType::PASS_TOKEN, [&](const Event& e) {
        token_.node_no = (token_.node_no + 1) % nodes_.size();
        Network::Node& active_node = nodes_[token_.node_no];

        if (active_node.size > 0) {
            token_.timeout = master_clock_ + Network::Token::kPassInterval;
            token_.next_pass_time = None;
            active_node.next_departure = master_clock_ + active_node.kDepartInterval;
        } else {
            token_.next_pass_time = master_clock_ + 1;
        }
    });
}


void Network::Run(int row_count) {
    for (int i = 0; i < row_count; i++) {
        cout << *this << endl;
        NextEvent();
    }
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
        return t < 0; }), times.end());

    // Update master clock.
    master_clock_ = util::min(times);

    // Iterate through the event time units and fire the corresponding event(s).
    // First we fire the arrival and departure events (if any)
    for (size_t i = 0; i < nodes_.size(); i++) {
        if (nodes_[i].next_arrival == master_clock_) {
            event_manager_->FireEvent(ArrivalEvent(i));
        } else if (nodes_[i].next_departure == master_clock_) {
            event_manager_->FireEvent(DepartureEvent(i));
        }
    }

    // Secondly we fire the token related events (if any)
    if (token_.timeout == master_clock_ && nodes_[token_.node_no].next_departure != None) {
        event_manager_->FireEvent(TokenTimeoutEvent());
    } else if (token_.next_pass_time == master_clock_) {
        event_manager_->FireEvent(PassTokenEvent());
    }
}


ostream& operator<< (ostream& os, const Network& network) {
    // If the master clock is 0, print the title row first.
    if (network.master_clock_ == 0) {
        os << "MC\t";

        for (size_t i = 0; i < network.nodes_.size(); i++) {
            os << "Arr" << i + 1 << "\t"
                << "Dep" << i + 1 << "\t"
                << "Size" << i + 1 << "\t";
        }

        os << "Node no\tTimeout\tNext pass" << endl;
    }
    
    os << network.master_clock_ << "\t";

    for (size_t i = 0; i < network.nodes_.size(); i++) {
        const Network::Node& node = network.nodes_[i];
        os << node.next_arrival << "\t";
        if (node.next_departure == None) {
            os << " ";
        } else {
            os << node.next_departure;
        }
        os << "\t" << node.size << "\t";
    }

    os << network.token_.node_no + 1 << "\t";

    if (network.token_.timeout == None) {
        os << " ";
    } else if (network.token_.timeout == Timeout) {
        os << "*";
    } else {
        os << network.token_.timeout;
    }
    os << "\t";

    if (network.token_.next_pass_time == None) {
        return os << " ";
    } else {
        return os << network.token_.next_pass_time;
    }
}
