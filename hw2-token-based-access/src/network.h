// Copyright 2019 Marco Wang <m.aesophor@gmail.com>

#ifndef NETWORK_H_
#define NETWORK_H_

#include "event/event_manager.h"

#define None -1

class Network {
public:
    Network(EventManager* event_manager, int node_count);
    virtual ~Network();
    void Run(int row_count);

private:
    struct Node {
        int next_arrival_;
        int next_departure_;
        int size_;
    };

    struct Token {
        int node_no = 0; // which node holds the token
        int timeout = None; // when mc reaches timeout, the node passes the token
        int next_arrival_node = None; // the next owner of the token
    };

    int master_clock_;
    int current_node_; // node id of the token owner
    int node_count_;

    EventManager* event_manager_;
    Node* nodes_; // dynamically allocated in constructor init list
};

#endif
