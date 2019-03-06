// Copyright 2019 Marco Wang <m.aesophor@gmail.com>

#include "event.h"

Event::Event(EventType type) : event_type_(type) {}


EventType Event::event_type() const {
    return event_type_;
}
