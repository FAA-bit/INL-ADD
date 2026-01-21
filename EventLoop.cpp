#include "EventLoop.h"
#include <iostream>

EventLoop::EventLoop(EventQueue& q, EventLog& l, AlarmSet& a)
    : queue(q), log(l), alarms(a)
{}

void EventLoop::tick(int n) {
    for (int i = 0; i < n; i++) {

        // --- Producer: generate new event ---
        Event e = generateRandomEvent();
        bool pushed = queue.enqueue(e);

        if (!pushed) {
            std::cout << "[WARNING] Queue full, event dropped (timestamp = "
                << e.timestamp << ")\n";
        }

        // --- Consumer: process one event ---
        Event out;
        bool popped = queue.dequeue(out);

        if (popped) {
            log.append(out);
            alarms.update(out);
        }
    }
}
