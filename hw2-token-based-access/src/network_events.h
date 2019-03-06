#ifndef NETWORK_EVENTS_H_
#define NETWORK_EVENTS_H_

#include "event/event.h"

class ArrivalEvent : public Event {
public:
    ArrivalEvent(int node_id) : Event(EventType::ARRIVAL), kNodeId_(node_id) {}
    virtual ~ArrivalEvent() = default;
    int kNodeId() const { return kNodeId_; }
private:
    int kNodeId_;
};

class DepartureEvent : public Event {
public:
    DepartureEvent(int node_id) : Event(EventType::DEPARTURE), kNodeId_(node_id) {}
    virtual ~DepartureEvent() = default;
    int kNodeId() const { return kNodeId_; }
private:
    int kNodeId_;
};

class TokenTimeoutEvent : public Event {
public:
    TokenTimeoutEvent() : Event(EventType::TOKEN_TIMEOUT) {}
    virtual ~TokenTimeoutEvent() = default;
};

class PassTokenEvent : public Event {
public:
    PassTokenEvent() : Event(EventType::PASS_TOKEN) {}
    virtual ~PassTokenEvent() = default;
};

#endif
