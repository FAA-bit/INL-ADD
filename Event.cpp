#include "Event.h"

static int globalTimestamp = 0;

int nextTimestamp() {
    return globalTimestamp++;
}
