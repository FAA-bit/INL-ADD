#pragma once
#include <string>

enum class EventType {
    TEMP,
    BUTTON,
    MOTION
};

struct Event {
    int timestamp;   // increases for every event
    int sensorId;    // which sensor it comes from
    EventType type;  // TEMP, BUTTON, MOTION
    int value;       // sensor reading or button state
};
int nextTimestamp();

// Implementation of nextTimestamp
static int globalTimestamp = 0;
// Call this whenever you create a new event
int nextTimestamp() {
    return globalTimestamp++;
}