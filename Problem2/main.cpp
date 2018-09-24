#include <iostream>
#include "ArbitraryQueueArray.h"

int main() {
    ArbitraryQueueArray<int> a;
    a.Push(4);
    a.Enqueue(7);
    a.Push(8);
    a.printArray();
    int pop = a.Pop();
    cout << "\n" << pop << endl << endl;
    int dequeue = a.Dequeue();
    cout << dequeue << endl << endl;
    a.Enqueue(14);
    a.Push(16);
    a.printArray();
    int t = a.Traverse(1);
    cout << "\n" << t << endl;
    return 0;
}