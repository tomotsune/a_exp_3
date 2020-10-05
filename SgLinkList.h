#pragma once

#include<iostream>
#include<cctype>
#include "CirLinkList.h"
#include "Node.h"
#include <vector>

using namespace std;

template<typename T>
class SgLinkList {
private:
    Node<T> *head;
    int length{};
public:

    Node<T> *getNode(const int &pos);

    SgLinkList();

    void insertHead(T var);

    void insert(const T &val, const int &pos);

    void remove(T val);

    int getLength();

    void reverse();

    int find(T val);

    void print();

    ~SgLinkList();

    void spite();

};

template<typename T>
inline SgLinkList<T>::SgLinkList() {
    head = nullptr;
    length == 0;
}

template<typename T>
inline void SgLinkList<T>::insertHead(T var) {
    insert(var, 0);
}

template<typename T>
inline void SgLinkList<T>::insert(const T &val, const int &pos) {
    if (pos < 0) {
        cout << "pos must be greater than zero" << endl;
        return;
    }
    int index{1};//walking stick of temp
    auto temp{head};
    auto node = new Node<T>{val};
    if (pos == 0) {
        node->next = temp;
        head = node;
        length++;
        return;
    }
    //将temp置于要插入的节点之前.
    while (temp != nullptr && index < pos) {
        temp = temp->next;
        ++index;
    }
    //插入位置不当
    if (temp == nullptr) {
        cout << "Insert failed!" << endl;
    }
    //交接后续结点.
    node->next = temp->next;
    temp->next = node;
    ++length;
}

template<typename T>
inline void SgLinkList<T>::remove(T val) {
    int pos = find(val);
    if (-1 == pos) {
        cout << "delete failed";
        return;
    }
    if (0 == pos) {
        head = head->next;
        --length;
        return;
    }
    int index{1};
    auto temp{head};
    while (index < pos) {
        temp = temp->next;
    }
    auto removeNode{temp->next};
    temp->next == temp->next->next;
    delete removeNode;
    --length;
}

template<typename T>
inline int SgLinkList<T>::getLength() {
    return length;
}

template<typename T>
inline void SgLinkList<T>::reverse() {
    if (head == nullptr) {
        return;
    }
    Node<T> *curNode{head}, *nextNode{head->next}, *temp;
    while (nextNode != nullptr) {
        temp = nextNode->next;
        nextNode->next = curNode;
        curNode = nextNode;
        nextNode = temp;
    }
    head->next = nullptr;
    head = curNode;
}

template<typename T>
inline int SgLinkList<T>::find(T val) {
    Node<T> *temp = head;
    int index{};
    while (temp != nullptr) {
        if (temp->val == val) {
            return index;
        }
        temp = temp->next;
        ++index;
    }
    return -1;
}

template<typename T>
inline void SgLinkList<T>::print() {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    auto temp{head};
    while (temp != nullptr) {
        cout << temp->val << endl;
        temp = temp->next;
    }
    cout << endl;
}

template<typename T>
inline SgLinkList<T>::~SgLinkList() {
    Node<T> *temp;
    for (int i = 0; i < length; i++) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

template<typename T>

void SgLinkList<T>::spite() {
/*    auto alpha{new CirLinkList<char>};
    auto digit{new CirLinkList<char>};
    auto punct{new CirLinkList<char>};*/

    CirLinkList<char> alpha;
    CirLinkList<char> digit;
    CirLinkList<char> punct;
   auto temp{head};
    while (temp != nullptr) {
        auto next = temp->next;
        if (isalpha(temp->val)) {
            alpha.push_end(temp);
        } else if (isdigit(temp->val)) {
            digit.push_end(temp);
        } else {
            punct.push_end(temp);
        }
        temp = next;

    }
    cout<<"alpha: ";alpha.print();
    cout<<"digit: ";digit.print();
    cout<<"punct: ";punct.print();
}

template<typename T>
Node<T> *SgLinkList<T>::getNode(const int &pos) {
    auto temp{head};
    int index{};
    while (index != pos) {
        temp = temp->next;
        ++index;
    }
    return temp;
}
