#ifndef ARRIVAL_EVENT_H_
#define ARRIVAL_EVENT_H_

#include "event/event.h"

class ArrivalEvent : public Event {
public:
    ArrivalEvent() : Event(EventType::ARRIVAL) {}
    virtual ~ArrivalEvent() = default;
};

class DepartureEvent : public Event {
public:
    DepartureEvent() : Event(EventType::DEPARTURE) {}
    virtual ~DepartureEvent() = default;
};

#endif
