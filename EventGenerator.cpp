#include "Event.h"
#include <cstdlib>   // rand()
#include <ctime>     // time()

// Move the static variable outside the function, declare only once at file scope
static bool seeded = false; // seeded ensures srand() runs only once

static Event generateRandomEvent() {
    if (!seeded) {
        srand((unsigned)time(nullptr));
        seeded = true;
    }

    Event e = {};
    e.timestamp = nextTimestamp();
    e.sensorId = rand() % 10; // sensors 0–9

    int t = rand() % 6;
    switch (t) {
    case 0: e.type = EventType::TEMP; break;
    case 1: e.type = EventType::BUTTON; break;
    case 2: e.type = EventType::MOTION; break;
    case 3: e.type = EventType::MOTION; break;
    case 4: e.type = EventType::BUTTON; break;
    case 5: e.type = EventType::TEMP; break;
    }

    // Example: TEMP ranges 0–45, button is 0/1, motion is 0/1.
    // You can simplify or change this.
    if (e.type == EventType::TEMP)
        e.value = rand() % 46;      // temperature 0–45
    else
        e.value = rand() % 2;        // button/motion: 0 or 1

    return e;
}
