#include "ScreenManager.h"
#include <iostream>
#include <cstring>

ScreenManager::ScreenManager(BoundedBuffer* queue) : queue(queue) {}

void ScreenManager::display() {
    int doneCount = 0;
    while (doneCount < 3) {
        char* message = queue->remove();
        if (std::strcmp(message, "DONE") == 0) {
            doneCount++;
            delete[] message;
        }
        else {
            std::cout << message << std::endl;
            delete[] message;
        }
    }
    std::cout << "DONE" << std::endl;
}

void* ScreenManager::start(void* arg) {
    ScreenManager* screenManager = static_cast<ScreenManager*>(arg);
    screenManager->display();
    return nullptr;
}
