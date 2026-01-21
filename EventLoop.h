#pragma once
#include "EventQueue.h"
#include "EventLog.h"
#include "EventGenerator.cpp"
#include "AlarmSet.h"

class EventLoop {
public:
	EventLoop(EventQueue& queue, EventLog& log, AlarmSet& alarms); // konstruktor

    // Run N cycles
    void tick(int n);
/*
 tick(n) simulerar n cykler
I varje cykel:
- Skapa händelse
- Lägg i kö → om kön är full → händelsen tas bort = Enqueue
- Ta bort en händelse från kön = Dequeue
- Lagra den i loggen
*/

private:
    EventQueue& queue;
    EventLog& log;
    AlarmSet& alarms;
};

