#include "EventQueue.h"

EventQueue::EventQueue(int capacity)
    : cap(capacity), head(0), tail(0), count(0)
{
    buffer = new Event[cap];
}

EventQueue::~EventQueue() {
    delete[] buffer;
}

bool EventQueue::isEmpty() const {
    return count == 0;
}

bool EventQueue::isFull() const {
    return count == cap;
}

bool EventQueue::enqueue(const Event& e) {
    if (isFull())
        return false;

    buffer[tail] = e;
    tail = (tail + 1) % cap;
    count++;
    return true;
}

bool EventQueue::dequeue(Event& out) {
    if (isEmpty())
        return false;

    out = buffer[head];
    head = (head + 1) % cap;
    count--;
    return true;
}
