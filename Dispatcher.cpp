#include "Dispatcher.h"
#include <cstring>

Dispatcher::Dispatcher(std::vector<BoundedBuffer*> producerQueues, BoundedBuffer* sportsQueue, BoundedBuffer* newsQueue, BoundedBuffer* weatherQueue)
        : producerQueues(producerQueues), sportsQueue(sportsQueue), newsQueue(newsQueue), weatherQueue(weatherQueue), allDone(false) {}

void Dispatcher::dispatch() {
    const char* sportsType = "SPORTS";
    const char* newsType = "NEWS";
    const char* weatherType = "WEATHER";
    int producerCount = producerQueues.size();
    int doneCount = 0;
    std::vector<bool> availProducers(producerCount, true);
    while (doneCount < producerCount) {
        for (int i = 0; i < producerCount; i++) {
            if(availProducers[i]) {
                char* message = producerQueues[i]->remove();
                if(message == nullptr) {
                    continue;
                }
                if (std::strcmp(message, "DONE") == 0) {
                    ++doneCount;
                    delete[] message;
                    availProducers[i] = false;
                    continue;
                }
                if (std::strstr(message, sportsType)) {
                    sportsQueue->insert(message);
                } else if (std::strstr(message, newsType)) {
                    newsQueue->insert(message);
                } else if (std::strstr(message, weatherType)) {
                    weatherQueue->insert(message);
                }
            }
        }
    }
    char* doneMessageS = new char[5];
    char* doneMessageN = new char[5];
    char* doneMessageW = new char[5];
    std::strcpy(doneMessageS, "DONE");
    std::strcpy(doneMessageN, "DONE");
    std::strcpy(doneMessageW, "DONE");
    sportsQueue->insert(doneMessageS);
    newsQueue->insert(doneMessageN);
    weatherQueue->insert(doneMessageW);
}

void* Dispatcher::start(void* arg) {
    Dispatcher* dispatcher = static_cast<Dispatcher*>(arg);
    dispatcher->dispatch();
    return nullptr;
}
