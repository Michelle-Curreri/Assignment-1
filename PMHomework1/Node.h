#include <iostream>

#ifndef PMHOMEWORK1_NODE_H
#define PMHOMEWORK1_NODE_H

template <typename Object>
struct Node {  //  a structure named Node
    Node () {
        next = nullptr;  //  setting original next to be NULL
    }
    Object value;
    Node<Object> *next;
    Node<Object> *size;
    Node<Object> *newSize;
};


#endif //PMHOMEWORK1_NODE_H
