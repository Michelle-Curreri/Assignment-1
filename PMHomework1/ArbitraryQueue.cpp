#include "ArbitraryQueue.h"

template <typename Object>
ArbitraryQueue<Object>::ArbitraryQueue() {  //  ArbitraryQueue constructor
    head = NULL;  //  setting the original head to NULL, since the queue is empty
    tail = NULL;  //  setting the original  tail to NULL, since the queue is empty
}

template <typename Object>
void ArbitraryQueue<Object>::Push(Object x) {  //  a function to insert at the head of the queue
    Node<Object> *temp = new Node<Object>; //  creating a pointer, temp, of the Node structure
    if (head == NULL) {  //  if the head position is empty
        head = new Node<Object>;
        temp -> value = x;  //  pointing temp to value and setting to be the inputted value
        temp -> next = NULL;  //  pointing temp to next value and setting to be NULL
        head = temp;  //  setting the new head to be the inputted value
        tail = temp;  //  setting the new tail to be the inputted value, since it is the only value in the list
    }
    else if (head != NULL) {  //  if the head position is not empty
        temp -> value = x;  //  pointing temp to value and setting to be the inputted value
        temp-> next = head;  //  pointing temp to next and setting to be the original head value
        head = temp;  //  setting the new head to be the inputted value
    }
}
template <typename Object>
void ArbitraryQueue<Object>::Enqueue(Object x) {  //  a function to insert at the tail of the queue
    Node<Object> *temp = new Node<Object>;
    if (head == NULL) {
        head = new Node<Object>;
        temp -> value = x;  //  setting temp's value to be equal to the input
        temp -> next = NULL;  //  setting temp's next value to equal to NULL
        head = temp;  //  setting the new head to be the inputted value
        tail = temp;  //  setting the new tail to be the inputted value, since it is the only value in the list
    }
    else if (head != NULL) {
        temp -> value = x;  //  setting temp's value to be equal to the input
        temp -> next = NULL;  // setting temp's next value to be NULL
        tail -> next = temp;  //  setting the tail's next value to be equal to the input
        tail = temp;  //  setting the new tail to be equal to the input
    }
}
template <typename Object>
Object ArbitraryQueue<Object>::Pop() {  //  removing the head value and returning it
    if (head != NULL) {  //  if the head value is not NULL, and therefore, there is a value in the queue
        Node<Object> *temp = new Node<Object>;  //  creating a pointer, temp, of the Node structure
        Object x = head -> value;  //  setting the object equal to the head's value
        temp = head;  //  setting temp to be the original head value
        head = head -> next;  //  shifting the head value to the left
        delete temp;  //  delete the original head value
        return x;  //  returning the popped value
    }
    else {  //  any other scenario
        cout << "The queue is empty - nothing to pop." << endl;  //  print out that the queue is empty
    }
}
template <typename Object>
Object ArbitraryQueue<Object>::Dequeue() {  //  removing the tail value and returning it
    Node<Object> *temp = new Node<Object>;  //  creating a pointer, temp, of the Node structure
    Object x = tail -> value;  //  setting the object equal to the tail's value
    if(head == NULL) {  //  if the head value is NULL
        cout << "The queue is empty." << endl;  //  printing out that the queue is empty
    }
    if(head -> next == NULL)  //  if the head's next value is NULL
    {
        delete head;  // deleting the head/tail value
        head = NULL;  //  setting the new head value to be NULL
    }
    temp = head;  //  setting temp equal to the head value;
    while (temp->next && temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;  //  deleting the previous tail value
    temp->next = NULL;  //  setting the previous tail value to be NULL
    return x;  // returning the original tail value
}

template <typename Object>
Object ArbitraryQueue<Object>::Traverse(int position) {
    Node<Object> *curr = new Node<Object>;  //  creating a pointer, curr, of the Node structure to represent the current placement
    Node<Object> *prev = new Node<Object>;  //  creating a pointer, prev, of the Node structure to represent the previous placement
    curr = head;  //  setting the current placement to be the head position
    Object x = curr -> value;
    for (int i = 0; i < position; i++) {  //  a loop to find the desired position
        prev = curr;  //  setting the previous position to be the original current position
        curr = curr -> next;  //  setting the current position to be the next position
        x = curr -> value;  //  setting x equal to the current position's value
    }
    return x;
}

template <typename Object>
void ArbitraryQueue<Object>::printList() {  //  a function to print out all of the values in the queue
    Node<Object> *temp = new Node<Object>;
    temp = head;  //  set temp equal to the head value
    if (temp == NULL) {  //  if the head value is NULL
        cout << "The queue is empty" << endl;  //  say that the queue is empty
    }
    else {  //  any other scenario
        while (temp != NULL) {  //  while temp doesn't equal NULL
            cout << temp -> value << "  ";  //  print out the temp's value
            temp = temp -> next;  //  set temp equal to point to the next value
        }  //  eventually, this loop will print out all of the values in the queue
    }
}

template class ArbitraryQueue<int>;
template class ArbitraryQueue<char>;
template class ArbitraryQueue<string>;
template class ArbitraryQueue<double>;







