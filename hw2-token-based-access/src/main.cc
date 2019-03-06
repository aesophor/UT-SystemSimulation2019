// Copyright 2019 Marco Wang <m.aesophor@gmail.com>

#include <iostream>
#include <stdexcept>

#include "event/event_manager.h"
#include "network.h"

using std::cout;
using std::endl;

int main(int argc, char* args[]) {
    try {
        EventManager event_manager = EventManager();

        Network network = Network(&event_manager);
        network.AddNode(10, 2);
        network.AddNode(15, 4);
        network.AddNode(20, 6);
        network.Run(35);
    } catch (const std::exception& ex) {
        cout << ex.what() << endl;
    }
}
