#include "AlarmSet.h"

AlarmSet::AlarmSet(int threshold)
    : threshold(threshold) {
}

bool AlarmSet::contains(int sensorId) const {
    for (int id : active)
        if (id == sensorId)
            return true;
    return false;
}

void AlarmSet::add(int sensorId) {
    if (!contains(sensorId))
        active.push_back(sensorId);
}

void AlarmSet::remove(int sensorId) {
    for (size_t i = 0; i < active.size(); i++) {
        if (active[i] == sensorId) {
            active.erase(active.begin() + i);
            return;
        }
    }
}

void AlarmSet::update(const Event& e) {
    // Only TEMP events matter
    if (e.type != EventType::TEMP)
        return;

    if (e.value > threshold) {
        add(e.sensorId);
    }
    else {
        remove(e.sensorId);
    }
}

void AlarmSet::printAlarms() const {
    if (active.empty()) {
        std::cout << "No active alarms.\n";
        return;
    }

    std::cout << "Active alarms (sensorId): ";
    for (int id : active)
        std::cout << id << " ";
    std::cout << "\n";
}

void AlarmSet::setThreshold(int t) {
    threshold = t;
}
