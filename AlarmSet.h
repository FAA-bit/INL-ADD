#pragma once
#include <vector>
#include <iostream>
#include "Event.h"

class AlarmSet {
public:
    AlarmSet(int threshold = 50);

    void update(const Event& e);     // called when event is processed
    void printAlarms() const;        // show active alarms
    void setThreshold(int t);

private:
    int threshold;
    std::vector<int> active;         // list of sensorIds in alarm

    bool contains(int sensorId) const;
    void add(int sensorId);
    void remove(int sensorId);
};
