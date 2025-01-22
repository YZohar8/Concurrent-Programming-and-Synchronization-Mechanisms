#include "Producer.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <cstring>

Producer::Producer(int id, int numProducts, BoundedBuffer* queue)
        : id(id), numProducts(numProducts), queue(queue) {
    std::srand(std::time(0));
}

void Producer::produce() {
    const char* types[] = {"SPORTS", "NEWS", "WEATHER"};
    int typeCounter[] = {0 , 0, 0};
    for (int j = 0; j < numProducts; ++j) {
        int typeIndex = std::rand() % 3;
        std::string message = "Producer " + std::to_string(id) + " " + types[typeIndex] + " " + std::to_string(typeCounter[typeIndex]);
        char* msg = new char[message.length() + 1];
        typeCounter[typeIndex]++;
        std::strcpy(msg, message.c_str());
        queue->insert(msg);
        usleep(100000); // Simulate some delay
    }
    char* doneMessage = new char[5];
    std::strcpy(doneMessage, "DONE");
    queue->signalDone();
    queue->insert(doneMessage);
}

void* Producer::start(void* arg) {
    Producer* producer = static_cast<Producer*>(arg);
    producer->produce();
    return nullptr;
}
