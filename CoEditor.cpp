#include "CoEditor.h"
#include <iostream>
#include <cstring>
#include <unistd.h>

CoEditor::CoEditor(BoundedBuffer* inputQueue, BoundedBuffer* outputQueue)
        : inputQueue(inputQueue), outputQueue(outputQueue) {}

void CoEditor::edit() {
    while (true) {
        char* message = inputQueue->remove();
        if (std::strcmp(message, "DONE") == 0) {
            outputQueue->insert(message);
            break;
        }
        usleep(100000); // Simulate editing delay
        outputQueue->insert(message);
    }
}

void* CoEditor::start(void* arg) {
    CoEditor* coEditor = static_cast<CoEditor*>(arg);
    coEditor->edit();
    return nullptr;
}
