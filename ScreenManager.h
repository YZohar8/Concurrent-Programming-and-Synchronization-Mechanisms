#ifndef SCREEN_MANAGER_H
#define SCREEN_MANAGER_H

#include "BoundedBuffer.h"

class ScreenManager {
private:
    BoundedBuffer* queue;

public:
    ScreenManager(BoundedBuffer* queue);
    void display();
    static void* start(void* arg);
};

#endif
