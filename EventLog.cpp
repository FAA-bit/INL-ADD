#include "EventLog.h"
#include <stdexcept>

EventLog::EventLog(int capacity)
    : count(0), cap(capacity)
{
    events = new Event[cap];
}

EventLog::~EventLog() {
    delete[] events;
}

int EventLog::size() const {
    return count;
}

Event EventLog::get(int index) const {
    if (index < 0 || index >= count)
        throw std::out_of_range("Index out of range");
    return events[index];
}

void EventLog::set(int index, const Event& e) {
    if (index < 0 || index >= count)
        throw std::out_of_range("Index out of range");
    events[index] = e;
}

void EventLog::append(const Event& e) {
    if (count == cap) {
        grow();
    }
    events[count++] = e;
}

Event* EventLog::data() {
    return events;
}

int EventLog::capacity() const {
    return cap;
}

void EventLog::grow() {
    int newCap = cap * 2;
    Event* newArr = new Event[newCap];

    for (int i = 0; i < count; i++) {
        newArr[i] = events[i];
    }

    delete[] events;
    events = newArr;
    cap = newCap;
}
