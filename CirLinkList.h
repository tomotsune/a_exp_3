#pragma once

#include<iostream>
#include "Node.h"

using namespace std;

template<typename T>
class CirLinkList {
private:

    Node<T> *head;
    Node<T> *tail;
    int length{};

    Node<T> *getNode(const int &pos);

public:
    CirLinkList();

    CirLinkList(CirLinkList<char> *pList);

    void insert(const T &val, const int &pos);

    void push_end(const T &val);

    void push_end( Node<T> *node);

    void remove(const T &val);


    void removeByPos(const int &pos);

    int getLength();


    int find(const T &val) const;

    void print();

    const Node<T> *getHead() const;

    ~CirLinkList();
};

template<typename T>
inline CirLinkList<T>::CirLinkList(CirLinkList<char> *pList) {
    head = nullptr;
    length == 0;
}

template<typename T>
inline void CirLinkList<T>::insert(const T &val, const int &pos) {
    if (pos < 0 || pos > length) {
        std::cout << "out of range." << std::endl;
        return;
    }
    if (pos == length)       //在尾部插入元素
        push_end(val);
    else if (pos == 0)      //在头部插入元素
    {
        auto node = new Node<T>(val);
        node->next = head;
        head = node;
        tail->next = head;
    } else {
        //返回插入位置前面一个的位置指针
        auto priorNode = getNode(pos - 1);
        auto node = new Node<T>(val);
        node->next = priorNode.next;
        priorNode->next = node;
    }
    ++length;
}

template<typename T>
inline void CirLinkList<T>::remove(const T &val) {
    removeByPos(find(val));
}

template<typename T>
inline int CirLinkList<T>::getLength() {
    return length;
}


template<typename T>
inline int CirLinkList<T>::find(const T &val) const {
    auto temp{head};
    int index{};
    while (index < length) {
        if (temp->val == val) {
            return index;
        }
        temp = temp->next;
        ++index;
    }
    return -1;
}

template<typename T>
inline void CirLinkList<T>::print() {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    auto temp{head};
    for (int i = 0; i < length; ++i) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

template<typename T>
inline CirLinkList<T>::~CirLinkList() {
    Node<T> *temp;
    for (int i = 0; i < length; i++) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

template<typename T>
const Node<T> *CirLinkList<T>::getHead() const {
    return head;
}

template<typename T>
void CirLinkList<T>::removeByPos(const int &pos) {
    if (pos > length - 1) {
        cout << "delete failed";
        return;
    }

    if (0 == pos) {
        tail->next->next = head->next;
        auto temp{head};
        head = head->next;
        delete temp;
        --length;
        return;
    }
    auto priorNode = getNode(pos - 1);
    auto removeNode{priorNode->next};
    priorNode->next = priorNode->next->next;
    delete removeNode;
    --length;
}

template<typename T>
void CirLinkList<T>::push_end(const T &val) {

    auto pNode = new Node<T>(val);
    push_end(pNode);

}

template<typename T>
Node<T> *CirLinkList<T>::getNode(const int &pos) {
    auto temp{head};
    int index{};
    while (index != pos) {
        temp = temp->next;
        ++index;
    }
    return temp;
}


template<typename T>
void CirLinkList<T>::push_end( Node<T> *node) {
    if (head == nullptr)   //链表为空时
    {
        head = node;
        tail = node;
        tail->next = head;
    } else {
        tail->next = node;
        tail = node;
        tail->next = head;
    }
    ++length;
}

template<typename T>
CirLinkList<T>::CirLinkList():head{nullptr},tail(nullptr),length(0){

}


