// Copyright 2019 Marco Wang <m.aesophor@gmail.com>

#include "event_manager.h"

EventManager::EventManager() {
    handlers_[EventType::ARRIVAL];
    handlers_[EventType::DEPARTURE];
}


void EventManager::AddEventHandler(EventType type, const EventHandler& handler) {
    handlers_[type].push_back(handler);
}

void EventManager::FireEvent(const Event& e) const {
    for (auto handler : handlers_.at(e.event_type())) {
        handler(e);
    }
}
