#pragma once
#include "Event.h"
#include <cstdlib>
#include <ctime>

inline Event generateRandomEvent() {
    static bool seeded = false;
    if (!seeded) {
        srand((unsigned)time(nullptr));
        seeded = true;
    }

    Event e = {};
    e.timestamp = nextTimestamp();
    e.sensorId = rand() % 10;

    int t = rand() % 6;
    switch (t) {
    case 0: e.type = EventType::TEMP; break;
    case 1: e.type = EventType::BUTTON; break;
	case 2: e.type = EventType::TEMP; break;
    case 3: e.type = EventType::MOTION; break;
    case 4: e.type = EventType::BUTTON; break;
    case 5: e.type = EventType::TEMP; break;
    }
	// Exempel TEMP: 0-45, BUTTON: 0-1, MOTION: 0-1
    if (e.type == EventType::TEMP)
        e.value = rand() % 46;
    else
        e.value = rand() % 2;

    return e;
}
