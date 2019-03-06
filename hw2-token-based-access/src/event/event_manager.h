// Copyright 2019 Marco Wang <m.aesophor@gmail.com>

#ifndef EVENT_MANAGER_H_
#define EVENT_MANAGER_H_

#include <vector>
#include <unordered_map>
#include <functional>

#include "event.h"

typedef std::function<void(const Event& e)> EventHandler;

class EventManager {
public:
    EventManager();
    virtual ~EventManager() = default;

    void AddEventHandler(EventType type, const EventHandler& handler);
    void FireEvent(const Event& e) const;
    
private:
    std::unordered_map<EventType, std::vector<EventHandler>> handlers_;
};

#endif
