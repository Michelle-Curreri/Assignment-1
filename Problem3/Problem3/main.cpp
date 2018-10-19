#include <iostream>
#include "Sort.h"

using namespace std;

int main() {
    Sort a;
    a.Push(9);
    a.Push(2);
    a.Push(3);
    a.Push(4);
    a.Push(5);
    a.printStack();
    a.InsertionSort();
    int h = a.Pop();
    cout << endl << h << endl;
    a.printStack();
    a.Push(1);
    a.printStack();
    a.InsertionSort();
    int pastp = a.PastPeek();
    cout << pastp << endl;
    return 0;
}

