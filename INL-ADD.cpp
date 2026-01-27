// INL-ADD.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Inlämningsuppgift: Algoritmer, datastrukturer och design patterns.

/*
- Event.h - Event.cpp - Den är för att definiera en struktur för en händelse med tidsstämpel, sensorId, typ och värde.
- EventLog.h - EventLog.cpp: De är för att lagra och hantera en samling av händelser i en dynamisk array.
- EventQueue.h - EventQueue.cpp: De är för att skapa och hantera en kö av händelser med hjälp av en cirkulär buffert.
- EventGenerator.h - Den är för att generera slumpmässiga händelser för teständamål.
- EventLoop.h - EventLoop.cpp: De är för att hantera huvudloopen som producerar och konsumerar händelser från kön och lagrar dem i loggen.
- InsertionSort.h - Den är för att sortera händelser i EventLog baserat på deras tidsstämpel med hjälp av insättningssortering.
- Search.h - Den är för att söka igenom EventLog för att hitta och skriva ut alla händelser som matchar ett angivet sensorId.
- AlarmSet.h - AlarmSet.cpp: De är för att hantera ett system för larm baserat på sensorvärden och en tröskel.
*/

// Main.cpp 
#include <iostream>
#include <sstream>
#include <string>
#include "Event.h"
#include "EventGenerator.h"
#include "EventQueue.h"
#include "EventLog.h"
#include "EventLoop.h"
#include "InsertionSort.h"
#include "Search.h"
#include "AlarmSet.h"

static void printLog(const EventLog& log) {
    int n = log.size();
    for (int i = 0; i < n; i++) {
        Event e = log.get(i);
        std::cout << "[" << i << "] timestamp=" << e.timestamp
            << ", sensorId=" << e.sensorId
            << ", value=" << e.value << "\n";
    }
}

int main() {
    EventQueue queue(10);     // choose any capacity
	EventLog log(10);         // choose any initial capacity
    AlarmSet alarms(40);      // choose any threshold
    EventLoop loop(queue, log, alarms);

    std::cout << "Embedded Event Logger - Commands: help\n";

    std::string line;
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, line);

        std::stringstream ss(line);
        std::string cmd;
        ss >> cmd; 

        if (cmd == "exit") {
            break;
        }
        else if (cmd == "help") {
            std::cout << "Commands:\n"
                << "  tick <n>         - run event loop n cycles\n"
                << "  print            - print event log\n"
                << "  Insertion sort   - sort log by timestamp using insertion sort\n"
                << "  find <sensorId>  - search events by sensor\n"
				<< "  alarms           - print active alarms\n"
				<< "  set-threshold <t>- set alarm threshold\n"
                << "  help             - show commands\n"
                << "  exit             - quit program\n";
        }
		else if (cmd == "tick") { // run event loop n cycles
            int n;
            ss >> n;
            loop.tick(n);
        }
		else if (cmd == "print") { // print event log
            printLog(log);
        }
		else if (cmd == "Insertion Sort") { // sort log by timestamp using insertion sort
			insertionSort(log);
			std::string method = "Insertion Sort";
            std::cout << "Insertion Sorted using: " << method << "\n";
        }
		else if (cmd == "find") { // search events by sensor
            int id;
            ss >> id;
            findEventsBySensor(log, id);
        }
		else if (cmd == "alarms") { // print active alarms
            alarms.printAlarms();
        }
		else if (cmd == "set-threshold") { // set alarm threshold
            int t;
            ss >> t;
            alarms.setThreshold(t);
            std::cout << "Threshold set to " << t << "\n";
        }
        else {
            std::cout << "Unknown command. Type 'help' for list.\n";
        }
    }

    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
