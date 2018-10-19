#include "Sort.h"

Sort::Sort() {
    size = 10;  //  creating default stack size of 10
    sort = new int[size];  //  creating default stack
    head = -1;  //  empty stack
    tail = -1;  //  empty stack
}

void Sort::InsertionSort() {  //  a function to sort the stack using the insertion sort method
    int i, j, temp;  //  initializing variables
    past = sort[head];  //  saving the current head (for the PastPeek function)
    for (i = 1; i <= head; i++) {  //  a loop to search through the stack
        j = i;  //  setting j equal to i
        while (j > 0 && sort[j - 1] > sort[j]) {
            temp = sort[j];
            sort[j] = sort[j - 1];
            sort[j - 1] = temp;
            j--;  //  decreasing j by 1
            cout << sort[j+1] << " was swapped with " << sort[j] << endl;  //  printing out the action that occurred
            printStack();  //  printing out the entire new stack
        }
    }
    cout << "Sort finished!" << endl;  //  printing out that the sort was finished
}

void Sort::Push(int x) {  //  a function to insert at the head of the stack
    if (Full()) {  //  if the stack is full
        cout << "The stack is full." << endl;  //  printing out that the stack is full
    }
    if (Empty()) {  //  if the stack is empty
        head = tail = 0;  //  the first element of the stack becomes both the head and the tail
    } else {  //  any other scenario
        head = (head + 1) % capacity;  //  increasing the stack size
    }
    sort[head] = x;  //  the new head becomes the input
}

int Sort::Pop() {  //  a function to pop the head value
    int x = sort[head];  //  saving int x as the head of the array
    head --;  //  subtracting the index of the head by 1
    return x;  //  returning the popped value
}

int Sort::Peek() {
    int x = sort[head];  //  setting x equal to the current head of the stack
    return x;  //  returning the current head of the stack
}

int Sort::PastPeek() {
    int x = past;  //  setting x equal to the past head of the stack
    return x;  // returning the past head of the stack
}

void Sort::printStack() {  //  a function to print the stack
    for (int i = 0; i <= head; i++) {  //  a loop to search through the stack
        cout << sort[i] << "  ";  //  printing out each element in the stack
    }
    cout << endl;  //  skipping to the next line
}

bool Sort::Full() {  //  a function to determine if the stack is full
    bool condition;
    if ((head + 1)%capacity == tail) {
        condition = true;
    }
    else {
        condition = false;
    }
    return condition;
}

bool Sort::Empty() {  //  a function to determine if the stack is empty
    bool condition;
    if (head == -1 && tail == -1){
        condition = true;
    }
    else {
        condition = false;
    }
    return condition;
}
