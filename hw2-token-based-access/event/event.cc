// Copyright 2019 Marco Wang <m.aesophor@gmail.com>

#include "event.h"

Event::Event(EventType type) : type_(type) {}


EventType Event::GetEventType() const {
    return type_;
}
