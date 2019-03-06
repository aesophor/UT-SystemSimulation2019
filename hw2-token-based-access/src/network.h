// Copyright 2019 Marco Wang <m.aesophor@gmail.com>

#ifndef NETWORK_H_
#define NETWORK_H_

#include <vector>
#include <iostream>

#include "event/event_manager.h"

#define None -1
#define Timeout -2

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
        const int kDepartInterval = 6;
        int next_arrival;
        int next_departure;
        int size;
    };

    struct Token {
        static const int kPassInterval = 15;
        int node_no = 0; // which node holds the token
        int timeout = None; // when mc reaches timeout, the node passes the token
        int next_pass_time = 1; // the time that token will actually be passed
    };

    void NextEvent();
    EventManager* event_manager_;
    
    int master_clock_;
    std::vector<Node> nodes_;
    Network::Token token_;
    
    friend std::ostream& operator<< (std::ostream& os, const Network& n);
};

#endif
