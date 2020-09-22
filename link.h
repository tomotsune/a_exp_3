//
//1. 双向链表模板.
//2. 根据范围频率进行排序.
//3. 冒泡排序, 只交换数据.
//
//Created by 胡海彬(tomo) on 2020/9/22.
//
#pragma once

#include<iostream>

using namespace std;

template<typename T>
struct Node {
    T val;
    Node *next;
    Node *prior;
    int freq{};//频率. 每次插入结点后据此排序.

    explicit Node(const T &x) : val(x), next(nullptr), prior(nullptr) {}

    Node(const Node &rhs) {
        freq = rhs.freq;
        val = rhs.val;
    }

    bool operator<(const Node &rhs) const {
        return freq < rhs.freq;
    }

    void operator=(const Node &rhs) {
        freq = rhs.freq;
        val = rhs.val;
    }
};

template<typename T>
class Link {
private:
    Node<T> *head;
    int length{};

public:
    Link();

    void insert(T val, const int &pos);

    void push_end(const T &val);

    void remove(T val);

    int getLength();

    int find(T val);

    void print();

    void sort();

    friend ostream &operator<<(ostream &os, const Link &link) {
        if (link.head == nullptr) {
            os << "List is empty" << endl;
        }
        auto temp{link.head};
        while (temp != nullptr) {
            os << temp->val << " ";
            temp = temp->next;
        }
        return os;
    }

    ~Link();
};

template<typename T>
inline Link<T>::Link() {
    head = nullptr;
    length == 0;
}

template<typename T>
inline void Link<T>::insert(T val, const int &pos) {
    if (pos < 0) {
        cout << "pos must be greater than zero" << endl;
        return;
    }
    int index{1};//walking stick of temp
    Node<T> *temp{head};
    auto *node = new Node<T>{val};
    if (pos == 0) {
        node->next = temp;
        head = node;
        ++length;
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
    //此时temp的位置在pos之前, 以下步骤根据链表类型有所差异
#if (0)
    //单链表操作.
    node->next = temp->next;
    temp->next = node;
#endif
#if (1)
    //双向链表操作.
    node->next = temp->next;
    if (pos != length)
        temp->next->prior = node;
    temp->next = node;
    node->prior = temp;
#endif
    ++length;
}

template<typename T>
inline void Link<T>::remove(T val) {
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
    //temp指向待删结点的直接前驱.
    //以下步骤根据链表类型有所差异.
    temp->next = temp->next->next;
    //双向链表需要增加以下步骤(链接前驱结点):
#if(1)
    temp->next->next->prior = temp->next;
#endif
    delete removeNode;
    --length;
}

template<typename T>
inline int Link<T>::getLength() {
    return length;
}


template<typename T>
inline int Link<T>::find(T val) {
    Node<T> *temp = head;
    int index{};
    while (temp != nullptr) {
        if (temp->val == val) {
            temp->freq = temp->freq + 1;
            return index;
        }
        temp = temp->next;
        ++index;
    }
    return -1;
}

template<typename T>
inline void Link<T>::print() {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    auto temp{head};
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

template<typename T>
inline Link<T>::~Link() {
    Node<T> *temp;
    for (int i = 0; i < length; i++) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

//冒泡排序, 直接交换数据.
template<typename T>
void Link<T>::sort() {
    if (length == 1)return;
    for (auto p = head; p->next != nullptr; p = p->next) {
        for (auto q = p->next; q != nullptr; q = q->next) {
            if (*p < *q) {
                auto temp{*q};
                *q = *p;
                *p = temp;
            }
        }
    }
}

template<typename T>
void Link<T>::push_end(const T &val) {
    insert(val, length);
}
