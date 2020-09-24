//
// Created by tomot on 2020/9/24.
//

#ifndef A_EXP_3_SINGLECIRCULARLINKEDLIST_H
#define A_EXP_3_SINGLECIRCULARLINKEDLIST_H
template <typename T>
struct Node{
    T val;
    Node* next;

};

template<typename T>
class SingleCircularLinkedList {
    Node<T> head;
    int length;

};


#endif //A_EXP_3_SINGLECIRCULARLINKEDLIST_H
