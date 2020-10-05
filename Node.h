//
// Created by tomot on 2020/10/4.
//

#ifndef A_EXP_3_NODE_H
#define A_EXP_3_NODE_H
#include "CirLinkList.h"
template<typename T>
class Node {
public:
    T val;
    explicit Node(const T& x) :val(x), next(nullptr) {}
    Node* next;

};




#endif //A_EXP_3_NODE_H
