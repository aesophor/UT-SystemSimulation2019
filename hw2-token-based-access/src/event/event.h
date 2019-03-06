// Copyright 2019 Marco Wang <m.aesophor@gmail.com>

#ifndef EVENT_H_
#define EVENT_H_

enum class EventType {
    ARRIVAL,
    DEPARTURE
};


class Event {
public:
    virtual EventType event_type() const;

protected:
    Event(EventType type);
    virtual ~Event() = default;

private:
    const EventType event_type_;
};

#endif
