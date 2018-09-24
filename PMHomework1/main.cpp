#include <iostream>
#include "ArbitraryQueue.h"
#include <string>
using namespace std;

int main() {
    ArbitraryQueue<int> a;
    a.Push(1);
    a.Enqueue(2);
    a.Push(5);
    a.Push(3);
    a.printList();
    int pop = a.Pop();
    cout << "\n" << pop << endl;
    a.printList();
    int t = a.Traverse(1);
    cout << "\n" << t << endl;
    int dequeue = a.Dequeue();
    cout << dequeue << endl;
    a.printList();
    return 0;
}