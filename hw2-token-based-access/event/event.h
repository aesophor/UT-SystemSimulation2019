// Copyright 2019 Marco Wang <m.aesophor@gmail.com>

#ifndef EVENT_H_
#define EVENT_H_

enum class EventType {
    ARRIVAL,
    DEPARTURE
};


class Event {
public:
    EventType GetEventType() const;

protected:
    Event(EventType type);
    virtual ~Event() = default;

private:
    const EventType type_;
};

#endif
