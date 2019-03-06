// Copyright 2019 Marco Wang <m.aesophor@gmail.com>

#include <iostream>

#include "event/event_manager.h"
#include "network.h"

int main(int argc, char* args[]) {
    EventManager event_manager = EventManager();

    Network network = Network(&event_manager, 3); // 3 network nodes
    network.Run(10);
}
