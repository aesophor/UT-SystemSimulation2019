#include "network.h"

#include <iostream>
#include <functional>

#include "event/event.h"
#include "network_events.h"

Network::Network(EventManager* event_manager, int node_count)
    : master_clock_(0),
      current_node_(0),
      node_count_(node_count),
      event_manager_(event_manager),
      nodes_(new Network::Node[node_count]) {

    event_manager_->AddEventHandler(EventType::ARRIVAL, [&](const Event& e) {
        std::cout << "Arrival Event fired!" << std::endl;
    });
}

Network::~Network() {
    delete[] nodes_;
}

void Network::Run(int row_count) {
    event_manager_->FireEvent(ArrivalEvent());
    event_manager_->FireEvent(ArrivalEvent());
    event_manager_->FireEvent(ArrivalEvent());
}
