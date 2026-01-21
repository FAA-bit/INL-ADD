#pragma once
#include "Event.h"
#include "EventLog.h"

void insertionSort(EventLog& log) {
	int n = log.size();
	Event* arr = log.data();
	for (int i = 1; i < n; i++) {
		Event key = arr[i];
		int j = i - 1;
		// Move elements of arr[0..i-1], that are greater than key,
		// to one position ahead of their current position
		while (j >= 0 && arr[j].timestamp > key.timestamp) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}
