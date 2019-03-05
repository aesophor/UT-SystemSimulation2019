#include "event_manager.h"

EventManager::EventManager() {
    handlers_[EventType::ARRIVAL];
    handlers_[EventType::DEPARTURE];
}


void EventManager::AddEventHandler(EventType type, void (*handler)(const Event&)) {
    handlers_.at(type).push_back(handler);
}

void EventManager::FireEvent(const Event& e) const {
    for (auto handler : handlers_.at(e.GetEventType())) {
        handler(e);
    }
}
