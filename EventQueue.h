#pragma once
#include "Event.h"

class EventQueue {
public:
    EventQueue(int capacity);
    ~EventQueue();

    bool isEmpty() const;
    bool isFull() const;

    bool enqueue(const Event& e);
    bool dequeue(Event& out);  // writes result into 'out'

private:
    Event* buffer;
    int cap;
    int head;   // index of next item to remove
    int tail;   // index of next position to insert
    int count;  // number of elements in queue
};
/* 
- How it works:
You use three integers:
head = index of the next element to remove
tail = index where the next new element will be inserted
count = number of items currently stored
And modulo (% cap) arithmetic to wrap around the indices when they reach the end of the array.
When you enqueue (add) an element:
 - Example:  If cap = 5 and tail moves: 0 → 1 → 2 → 3 → 4 → 0 again
.*/
