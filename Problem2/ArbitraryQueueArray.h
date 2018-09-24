#ifndef PROBLEM2_ARBITRARYQUEUEARRAY_H
#define PROBLEM2_ARBITRARYQUEUEARRAY_H

#include <iostream>
#include <algorithm>
#include <string>
#include <array>

using namespace std;

template <typename Object>
class ArbitraryQueueArray {  //  a class to make queues
private:
    int head;
    int tail;
    int size;
    int capacity;
    Object *queue;

public:
    ArbitraryQueueArray();
    void Push(Object);
    void Enqueue(Object);
    Object Pop();
    Object Dequeue();
    Object Traverse(int);
    bool Full();
    bool Empty();
    void printArray();
};


#endif //PROBLEM2_ARBITRARYQUEUEARRAY_H
