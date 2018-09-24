#include "ArbitraryQueueArray.h"

template <typename Object>
ArbitraryQueueArray<Object>::ArbitraryQueueArray() {  //  ArbitraryQueueArray constructor
    size = 10;  //  setting original array size to be 10
    queue = new Object[size];  //  creating a new array, queue, of type Object, with size
    head = -1;  //  setting original head value to be -1, since queue is empty
    tail = -1;  //  setting original tail value to be -1, since queue is empty
}

template <typename Object>
void ArbitraryQueueArray<Object>::Push(Object x) {  //  a function to insert at the head of the queue
    if(Full()) {  //  if the queue is full
        cout << "The queue is full." << endl;  //  printing out that the queue is full
    }
    if (Empty()) {  //  if the queue is empty
        head = tail = 0;  //  setting the new head and tail value to be 0 - making the input the first value in the array/queue
    }
    else {  //  any other scenario
        tail = (tail + 1)%capacity;  //  extend queue size
    }
    for (int i = tail; i >= 1; i--){  //  a loop to search through the queue
        queue[i] = queue[i-1];  //  shifting the queue values to the right
    }
    queue[head] = x;  //  setting the new head value to be the inputted value
}

template <typename Object>
void ArbitraryQueueArray<Object>::Enqueue(Object x) {  //  a function to insert at the tail of the queue
    if(Full()) {  //  if the queue is full
        cout << "The queue is full." << endl;  //  printing out that the queue is full
    }
    if (Empty()) {  //  if the queue is empty
        head = tail = 0;  //  setting the new head and tail value to be 0 - making the input the first value in the array/queue
    }
    else {  //  any other scenario
        tail = (tail + 1)%capacity;  //  extend queue size
    }
    queue[tail] = x;  //  setting the new tail value to be the inputted value
}

template <typename Object>
Object ArbitraryQueueArray<Object>::Pop() {  //  a function to return and remove the head of the queue
    Object x = queue[head];  //  setting the object equal to the head's value
    for (int i = 0; i < tail; i++) {  //  a loop to search through the queue
        queue[i] = queue[i+1];  //  shifting the queue values to the left
    }
    tail --;  //  decreasing tail
    return x;  //  returning the popped value
}

template <typename Object>
Object ArbitraryQueueArray<Object>::Dequeue() {  //  a function to return and remove the tail of the queue
    Object x = queue[tail--];  //  setting object equal to the tail's value, then decreasing tail
    return x;  //  returning the dequeued value
}

template <typename Object>
Object ArbitraryQueueArray<Object>::Traverse(int position) {
    Object x = queue[position];  //  saving the object in the inputted position
    return x;  //  returning the desired object
}

template <typename Object>
bool ArbitraryQueueArray<Object>::Full() {  //  a function to determine if the queue is full
    bool condition;
    if ((tail + 1)%capacity == head) {  //  if the array is full
        condition = true;  //  saving the condition as true
    }
    else {  //  any other scenario
        condition = false;  //  saving the condition as false
    }
    return condition;
}

template <typename Object>
bool ArbitraryQueueArray<Object>::Empty() {
    bool condition;
    if (head == -1 && tail == -1){
        condition = true;
    }
    else {
        condition = false;
    }
    return condition;
}

template <typename Object>
void ArbitraryQueueArray<Object>::printArray() {  //  a function to print all of the objects in the queue
    for (int i = 0; i <= tail; i++) {  //  a loop to search through the whole queue
        cout << queue[i] << "  ";  //  printing each object
    }
}


template class ArbitraryQueueArray<int>;
template class ArbitraryQueueArray<char>;
template class ArbitraryQueueArray<string>;
template class ArbitraryQueueArray<double>;
