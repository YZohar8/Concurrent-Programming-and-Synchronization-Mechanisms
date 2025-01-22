#ifndef PRODUCER_H
#define PRODUCER_H

#include <string>
#include "BoundedBuffer.h"

class Producer {
private:
    int id;
    int numProducts;
    BoundedBuffer* queue;

public:
    Producer(int id, int numProducts, BoundedBuffer* queue);
    void produce();
    static void* start(void* arg);
};

#endif
