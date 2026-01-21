#pragma once
#include "Event.h"

class EventLog {
public:
	EventLog(int capacity = 10);     // konstructor
    ~EventLog();                     // destructor

    int size() const;
    void append(const Event& e);
    Event get(int index) const;
    void set(int index, const Event& e);

    Event* data();                   // used by sorting functions
    int capacity() const;            // optional, but useful

private:
    Event* events;   // dynamic array
    int count;       // how many events currently stored
    int cap;         // max capacity before growing

    void grow();     // internal function to increase capacity
};

