#pragma once
#include<iostream>
using namespace std;
template<typename T>
struct Node
{
    T val;
    Node* next;
    Node* prior;
    explicit Node(T x) :val(x), next(nullptr) {}
};
template<typename T>
class DoubleLink
{
private:
    Node<T>* head;
    int length{};
public:
    DoubleLink();
    void insertHead(T var);
    void insert(T val, const int& pos);
    void remove(T val);
    int getLength();
    void reverse();
    int find(T val);
    void print();
    ~DoubleLink();
};

template<typename T>
inline DoubleLink<T>::DoubleLink()
{
    head = nullptr;
    length == 0;
}

template<typename T>
inline void DoubleLink<T>::insertHead(T var)
{
    insert(var, 0);
}

template<typename T>
inline void DoubleLink<T>::insert(T val, const int& pos)
{
    if (pos < 0) {
        cout << "pos must be greater than zero" << endl;
        return;
    }
    int index{ 1 };//walking stick of temp
    Node<T>* temp{ head };
    auto* node = new Node<T>{ val };
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
    //连接前面的结点.
    node->prior=temp->prior;
    temp->prior=node;
    ++length;
}

template<typename T>
inline void DoubleLink<T>::remove(T val)
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
    Node<T>* temp = head;
    while (index < pos) {
        temp = temp->next;
    }
    Node<T>* removeNode{ temp->next };
    temp->next = temp->next->next;
    //交接前面结点.
    temp->prior = temp->prior->prior;
    delete removeNode;
    --length;
}

template<typename T>
inline int DoubleLink<T>::getLength()
{
    return length;
}

template<typename T>
inline void DoubleLink<T>::reverse()
{
    if (head == nullptr) {
        return;
    }
    Node<T>* curNode{ head }, * nextNode{ head->next }, * temp;
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
inline int DoubleLink<T>::find(T val)
{
    Node<T>* temp = head;
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
inline void DoubleLink<T>::print()
{
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    Node<T>* temp{ head };
    while (temp!=nullptr)
    {
        cout << temp->val << endl;
        temp = temp->next;
    }
    cout << endl;
}

template<typename T>
inline DoubleLink<T>::~DoubleLink()
{
    Node<T>* temp;
    for (int  i = 0; i < length; i++)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}
