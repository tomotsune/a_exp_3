#pragma once
#include<iostream>
using namespace std;

template<typename T>
class CirLinkList
{
private:
    struct CirNode
    {
        T val;
        CirNode* next;
        explicit CirNode(T x) :val(x), next(nullptr) {}
    };
    CirNode* head;
    int length{};
public:
    CirLinkList();
    void insert(T val, const int& pos);
    void remove(const T& val);
    void removeByPos(const int& pos);
    int getLength();
    int find(T val);
    void print();

    CirNode *getHead() const;

    ~CirLinkList();
};

template<typename T>
inline CirLinkList<T>::CirLinkList()
{
    head = nullptr;
    length == 0;
}

template<typename T>
inline void CirLinkList<T>::insert(T val, const int& pos)
{
    if (pos < 0) {
        cout << "pos must be greater than zero" << endl;
        return;
    }
    int index{ 1 };//walking stick of temp
    auto temp{ head };
    auto* cirNode = new CirNode{ val };
    if (pos == 0) {
        cirNode->next = temp;
        head = cirNode;
        length++;
        return;
    }
    //将temp置于要插入的节点之前.
    while (temp != head && index < pos) {
        temp = temp->next;
        ++index;
    }
    //插入位置不当
    if (temp == head) {
        cout << "Insert failed!" << endl;
    }
    //交接后续结点.
    cirNode->next = temp->next;
    temp->next = cirNode;
    ++length;
}

template<typename T>
inline void CirLinkList<T>::remove(const T& val)
{
    removeByPos(find(val));
}

template<typename T>
inline int CirLinkList<T>::getLength()
{
    return length;
}


template<typename T>
inline int CirLinkList<T>::find(T val)
{
    auto temp{head};
    int index{};
    while (temp != head) {
        if (temp->val == val) {
            return index;
        }
        temp = temp->next;
        ++index;
    }
    return -1;
}

template<typename T>
inline void CirLinkList<T>::print()
{
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    auto temp{ head };
    cout<<temp->val<<" ";
    temp=temp->next;
    while (temp!=head)
    {
        cout << temp->val<<" ";
        temp = temp->next;
    }
    cout << endl;
}

template<typename T>
inline CirLinkList<T>::~CirLinkList()
{
    CirNode* temp;
    for (int  i = 0; i < length; i++)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}

template<typename T>
typename CirLinkList<T>::CirNode *CirLinkList<T>::getHead() const {
    return head;
}

template<typename T>
void CirLinkList<T>::removeByPos(const int &pos) {
    if (pos>length) {
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
