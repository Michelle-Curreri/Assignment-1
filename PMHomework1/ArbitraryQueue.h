#include <iostream>
#include <algorithm>
#include <string>
#ifndef PMHOMEWORK1_ARBITRARYQUEUE_H
#define PMHOMEWORK1_ARBITRARYQUEUE_H
#include "Node.h"

using namespace std;

template<typename Object>
class ArbitraryQueue {  //  a class to make queues
private:
    Node<Object> *head, *tail;

public:
    ArbitraryQueue();
    void Push(Object);
    void Enqueue(Object);
    Object Pop();
    Object Dequeue();
    Object Traverse(int);
    void printList();
};


#endif //PMHOMEWORK1_ARBITRARYQUEUE_H
