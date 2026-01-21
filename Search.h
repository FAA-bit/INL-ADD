#pragma once
#include "Event.h"
#include "EventLog.h"
#include <iostream>

// Denna funktion söker igenom EventLog för att hitta och skriva ut alla händelser som matchar det angivna sensorId.
void findEventsBySensor(const EventLog& log, int sensorId); 

// Implementation of findEventsBySensor
void findEventsBySensor(const EventLog& log, int sensorId) {
    int n = log.size();
    bool found = false;

    for (int i = 0; i < n; i++) {
        Event e = log.get(i);

        if (e.sensorId == sensorId) {
            found = true;

            std::cout << "Event [timestamp=" << e.timestamp
                << ", sensorId=" << e.sensorId
                << ", value=" << e.value
                << "]\n";
        }
    }

    if (!found) {
        std::cout << "No events found for sensor " << sensorId << "\n";
    }
}