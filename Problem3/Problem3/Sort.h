#include <iostream>
#include <array>


#ifndef PROBLEM3_SORT_H
#define PROBLEM3_SORT_H

using namespace std;

class Sort {

    struct Stack {
        Stack *next;
        int unsorted;
        int sorted;
    };
private:
    int *sort;
    int tail;
    int head;
    int size;
    int capacity;
    int past;

public:
    Sort();
    void InsertionSort();
    void Push(int);
    int Pop();
    int Peek();
    int PastPeek();
    void printStack();
    bool Full();
    bool Empty();
};


#endif //PROBLEM3_SORT_H
