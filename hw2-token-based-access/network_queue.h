// Copyright 2019 Marco Wang <m.aesophor@gmail.com>

// This class is just a representation of a queue of a network node,
// and is suitable for simulation use only.

#ifndef NETWORK_QUEUE_H_
#define NETWORK_QUEUE_H_

class NetworkQueue {
public:
    NetworkQueue();
    virtual ~NetworkQueue() = default;

private:
    int next_arrival_;
    int next_departure_;
    int size_;
};

#endif
