#pragma once

#include<iostream>

using namespace std;

template<typename T>
class CirLinkList {
private:
    struct CirNode {
        T val;
        CirNode *next;

        explicit CirNode(T x) : val(x), next(nullptr) {}
    };

    CirNode *head;
    CirNode *tail;
    int length{};
    CirNode* getNode(const int& pos);
public:

    CirLinkList();

    void insert(const T &val, const int &pos);

    void push_end(const T &val);


    void remove(const T &val);

    void removeByPos(const int &pos);

    int getLength();


    int find(const T& val)const;

    void print();

    const CirNode  *getHead() const;



    ~CirLinkList();
};

template<typename T>
inline CirLinkList<T>::CirLinkList() {
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
        auto node = new CirNode(val);
        node->next = head;
        head = node;
        tail->next = head;
    } else {
        //返回插入位置前面一个的位置指针
        auto priorNode=getNode(pos-1);
        auto node=new CirNode(val);
        node->next=priorNode.next;
        priorNode->next=node;
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
inline int CirLinkList<T>::find(const T& val)const {
    auto temp{head};
    int index{};
    while (index<length) {
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
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout << endl;
}

template<typename T>
inline CirLinkList<T>::~CirLinkList() {
    CirNode *temp;
    for (int i = 0; i < length; i++) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

template<typename T>
const typename CirLinkList<T>::CirNode *CirLinkList<T>::getHead() const {
    return head;
}

template<typename T>
void CirLinkList<T>::removeByPos(const int &pos) {
    if (pos > length-1) {
        cout << "delete failed";
        return;
    }

    if (0 == pos) {
        tail->next->next=head->next;
        auto temp{head};
        head=head->next;
        delete temp;
        --length;
        return;
    }
    auto priorNode = getNode(pos-1);
    auto removeNode{priorNode->next};
    priorNode->next = priorNode->next->next;
    delete removeNode;
    --length;
}

template<typename T>
void CirLinkList<T>::push_end(const T &val) {
    {
        auto pNode = new CirNode(val);
        if (head == nullptr)   //链表为空时
        {
            head = pNode;
            tail = pNode;
            tail->next = head;
        } else {
            tail->next = pNode;
            tail = pNode;
            tail->next = head;
        }
        ++length;
    }
}

template<typename T>
typename CirLinkList<T>::CirNode *CirLinkList<T>::getNode(const int &pos) {
    auto temp{head};
    int index{};
    while (index!=pos) {
        temp = temp->next;
        ++index;
    }
    return temp;
}


