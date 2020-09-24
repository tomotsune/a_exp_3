#pragma once
#include<iostream>
#include "CirLinkList.h"
using namespace std;

template<typename T>
class SgLinkList
{
private:
    struct SgNode
    {
        T val;
        SgNode* next;
        explicit SgNode(T x) :val(x), next(nullptr) {}
    };
    SgNode* head;
    int length{};
public:
    SgLinkList();
    void insertHead(T var);
    void insert(T val, const int& pos);
    void remove(T val);
    int getLength();
    void reverse();
    int find(T val);
    void print();
    ~SgLinkList();
};

template<typename T>
inline SgLinkList<T>::SgLinkList()
{
    head = nullptr;
    length == 0;
}

template<typename T>
inline void SgLinkList<T>::insertHead(T var)
{
    insert(var, 0);
}

template<typename T>
inline void SgLinkList<T>::insert(T val, const int& pos)
{
    if (pos < 0) {
        cout << "pos must be greater than zero" << endl;
        return;
    }
    int index{ 1 };//walking stick of temp
    auto temp{ head };
    auto* sgNode = new SgNode{ val };
    if (pos == 0) {
        sgNode->next = temp;
        head = sgNode;
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
    sgNode->next = temp->next;
    temp->next = sgNode;
    ++length;
}

template<typename T>
inline void SgLinkList<T>::remove(T val)
{
    int pos = find(val);
    if (-1 == pos) {
        cout << "delete failed";
        return;
    }
    if (0==pos) {
        head = head->next;
        --length;
        return;
    }
    int index{ 1 };
    auto temp{head};
    while (index < pos) {
        temp = temp->next;
    }
    auto removeNode{ temp->next };
    temp->next == temp->next->next;
    delete removeNode;
    --length;
}

template<typename T>
inline int SgLinkList<T>::getLength()
{
    return length;
}

template<typename T>
inline void SgLinkList<T>::reverse()
{
    if (head == nullptr) {
        return;
    }
    SgNode* curNode{ head }, * nextNode{ head->next }, * temp;
    while (nextNode!=nullptr)
    {
        temp = nextNode->next;
        nextNode->next = curNode;
        curNode = nextNode;
        nextNode = temp;
    }
    head->next = nullptr ;
    head = curNode;
}

template<typename T>
inline int SgLinkList<T>::find(T val)
{
    SgNode* temp = head;
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
inline void SgLinkList<T>::print()
{
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    auto temp{ head };
    while (temp!=nullptr)
    {
        cout << temp->val << endl;
        temp = temp->next;
    }
    cout << endl;
}

template<typename T>
inline SgLinkList<T>::~SgLinkList()
{
    SgNode* temp;
    for (int  i = 0; i < length; i++)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}
