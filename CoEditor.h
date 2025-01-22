#ifndef COEDITOR_H
#define COEDITOR_H

#include "BoundedBuffer.h"

class CoEditor {
private:
    BoundedBuffer* inputQueue;
    BoundedBuffer* outputQueue;

public:
    CoEditor(BoundedBuffer* inputQueue, BoundedBuffer* outputQueue);
    void edit();
    static void* start(void* arg);
};

#endif
