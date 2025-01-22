CC = g++
CFLAGS = -pthread -std=c++11 -g

all: ex4.out

ex4.out: main.o BoundedBuffer.o Producer.o Dispatcher.o CoEditor.o ScreenManager.o
	$(CC) $(CFLAGS) -o ex4.out main.o BoundedBuffer.o Producer.o Dispatcher.o CoEditor.o ScreenManager.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

BoundedBuffer.o: BoundedBuffer.cpp BoundedBuffer.h
	$(CC) $(CFLAGS) -c BoundedBuffer.cpp

Producer.o: Producer.cpp Producer.h
	$(CC) $(CFLAGS) -c Producer.cpp

Dispatcher.o: Dispatcher.cpp Dispatcher.h
	$(CC) $(CFLAGS) -c Dispatcher.cpp

CoEditor.o: CoEditor.cpp CoEditor.h
	$(CC) $(CFLAGS) -c CoEditor.cpp

ScreenManager.o: ScreenManager.cpp ScreenManager.h
	$(CC) $(CFLAGS) -c ScreenManager.cpp

clean:
	rm -f *.o ex4.out
