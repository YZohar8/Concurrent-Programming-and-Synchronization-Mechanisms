#ifndef DISPATCHER_H
#define DISPATCHER_H

#include <vector>
#include "BoundedBuffer.h"

class Dispatcher {
private:
    std::vector<BoundedBuffer*> producerQueues;
    BoundedBuffer* sportsQueue;
    BoundedBuffer* newsQueue;
    BoundedBuffer* weatherQueue;
    bool allDone;

public:
    Dispatcher(std::vector<BoundedBuffer*> producerQueues, BoundedBuffer* sportsQueue, BoundedBuffer* newsQueue, BoundedBuffer* weatherQueue);
    void dispatch();
    static void* start(void* arg);
};

#endif
