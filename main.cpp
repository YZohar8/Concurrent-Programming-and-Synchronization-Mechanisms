#include <iostream>
#include <fstream>
#include <vector>
#include <pthread.h>
#include "BoundedBuffer.h"
#include "Producer.h"
#include "Dispatcher.h"
#include "CoEditor.h"
#include "ScreenManager.h"
#include <limits>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <config file>" << std::endl;
        return 1;
    }

    std::ifstream configFile(argv[1]);
    if (!configFile) {
        std::cerr << "Error: Could not open configuration file " << argv[1] << std::endl;
        return 1;
    }

    int numProducers = 0;
    std::vector<int> numProducts;
    std::vector<int> queueSizes;
    int coEditorQueueSize = 100;

    std::string line;
    while (std::getline(configFile, line)) {
        if (line.find("PRODUCER") != std::string::npos) {
            ++numProducers;
            int products;
            int queueSize;
            configFile >> products;
            configFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the line
            configFile.ignore(std::numeric_limits<std::streamsize>::max(), '='); // Ignore up to '='
            configFile >> queueSize;
            configFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the line
            numProducts.push_back(products);
            queueSizes.push_back(queueSize);
        }
    }
    configFile.close();

    std::vector<BoundedBuffer*> producerQueues;
    for (int i = 0; i < numProducers; ++i) {
        producerQueues.push_back(new BoundedBuffer(queueSizes[i]));
    }
    BoundedBuffer* sportsQueue = new BoundedBuffer(coEditorQueueSize);
    BoundedBuffer* newsQueue = new BoundedBuffer(coEditorQueueSize);
    BoundedBuffer* weatherQueue = new BoundedBuffer(coEditorQueueSize);
    BoundedBuffer* screenQueue = new BoundedBuffer(coEditorQueueSize);

    std::vector<Producer*> producers;
    for (int i = 0; i < numProducers; ++i) {
        producers.push_back(new Producer(i + 1, numProducts[i], producerQueues[i]));
    }
    Dispatcher dispatcher(producerQueues, sportsQueue, newsQueue, weatherQueue);
    CoEditor sportsEditor(sportsQueue, screenQueue);
    CoEditor newsEditor(newsQueue, screenQueue);
    CoEditor weatherEditor(weatherQueue, screenQueue);
    ScreenManager screenManager(screenQueue);

    std::vector<pthread_t> producerThreads(numProducers);
    pthread_t dispatcherThread;
    pthread_t sportsEditorThread, newsEditorThread, weatherEditorThread;
    pthread_t screenManagerThread;

    for (int i = 0; i < numProducers; ++i) {
        pthread_create(&producerThreads[i], NULL, Producer::start, producers[i]);
    }
    pthread_create(&dispatcherThread, NULL, Dispatcher::start, &dispatcher);
    pthread_create(&sportsEditorThread, NULL, CoEditor::start, &sportsEditor);
    pthread_create(&newsEditorThread, NULL, CoEditor::start, &newsEditor);
    pthread_create(&weatherEditorThread, NULL, CoEditor::start, &weatherEditor);
    pthread_create(&screenManagerThread, NULL, ScreenManager::start, &screenManager);

    for (int i = 0; i < numProducers; ++i) {
        pthread_join(producerThreads[i], NULL);
    }
    pthread_join(dispatcherThread, NULL);
    pthread_join(sportsEditorThread, NULL);
    pthread_join(newsEditorThread, NULL);
    pthread_join(weatherEditorThread, NULL);
    pthread_join(screenManagerThread, NULL);

    for (auto queue : producerQueues) {
        delete queue;
    }
    delete sportsQueue;
    delete newsQueue;
    delete weatherQueue;
    delete screenQueue;

    for (auto producer : producers) {
        delete producer;
    }

    return 0;
}
