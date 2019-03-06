#ifndef NETWORK_EVENTS_H_
#define NETWORK_EVENTS_H_

#include "event/event.h"

class ArrivalEvent : public Event {
public:
    ArrivalEvent(int node_id) : Event(EventType::ARRIVAL), kNodeId(node_id) {}
    virtual ~ArrivalEvent() = default;
private:
    const int kNodeId;
};

class DepartureEvent : public Event {
public:
    DepartureEvent(int node_id) : Event(EventType::DEPARTURE), kNodeId(node_id) {}
    virtual ~DepartureEvent() = default;
private:
    const int kNodeId;
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
