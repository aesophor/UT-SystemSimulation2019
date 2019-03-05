// Copyright 2019 Marco Wang <m.aesophor@gmail.com>

#ifndef EVENT_MANAGER_H_
#define EVENT_MANAGER_H_

#include <vector>
#include <unordered_map>

#include "event.h"

class EventManager {
public:
    EventManager();
    virtual ~EventManager() = default;

    void AddEventHandler(EventType type, void (*handler)(const Event&));
    void FireEvent(const Event& e) const;
    
private:
    std::unordered_map<EventType, std::vector<void (*)(const Event&)>> handlers_;
};

#endif
