// Copyright 2019 Marco Wang <m.aesophor@gmail.com>

#ifndef NETWORK_H_
#define NETWORK_H_

#include <vector>

#include "event/event_manager.h"

#define None -1

class Network {
public:
    Network(EventManager* event_manager);
    virtual ~Network() = default;
    void Run(int row_count);

    void AddNode(int arrival_interval, int next_arrival);

private:
    struct Node {
        Node(int arrival_interval, int next_arrival);
        const int kArrivalInterval;
        int next_arrival;
        int next_departure;
        int size;
    };

    struct Token {
        int node_no = 0; // which node holds the token
        int timeout = None; // when mc reaches timeout, the node passes the token
        int next_pass_time = 1; // the time that token will actually be passed
        bool has_ongoing_transmission = false;
    };

    void NextEvent();
    void PrintRow() const;

    void OnPacketArrival(int node_id);
    void OnPacketDeparture(int node_id);
    void OnTokenTimeout();
    void OnPassToken();

    static const int kPacketDepartInterval = 6;

    int master_clock_;
    int current_node_; // node id of the token owner

    EventManager* event_manager_;
    std::vector<Node> nodes_;
    Network::Token token_;
};

#endif
