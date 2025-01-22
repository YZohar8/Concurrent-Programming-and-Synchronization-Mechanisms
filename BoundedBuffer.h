#ifndef BOUNDED_BUFFER_H
#define BOUNDED_BUFFER_H

#include <queue>
#include <semaphore.h>
#include <pthread.h>

class BoundedBuffer {
private:
    std::queue<char*> buffer;
    int maxSize;
    sem_t full;
    sem_t empty;
    pthread_mutex_t mutex;
    bool isDone;

public:
    BoundedBuffer(int size);
    ~BoundedBuffer();
    void insert(char* s);
    char* remove();
    void signalDone();
};

#endif
