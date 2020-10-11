//
//1. 双向链表.
//
//Created by 胡海彬(tomo) on 2020/9/22.
//
#include <iostream>
#include "DuLinkList.h"
#include "SgLinkList.h"

void question_3();

void question_1();

void question_2();

int main() {
    // question_1();
    //question_2();
     question_3();


    return 0;
}

void question_1() {

    //创建单向循环链表.
    CirLinkList<int> list(nullptr);
    list.push_end(1);
    list.push_end(2);
    list.push_end(3);

    //获取指向链表第二个元素的 s 指针.
    auto s = list.getHead()->next;

    cout << "Q1: remove the previous node of S from circle-list-link" << endl;
    cout << "Original list: ";
    list.print();

    //删除 S 的前驱结点.
    /*list.removeByPos(list.find(s->val) - 1);*/
    list.removePrior(s);
    cout << "After removing: ";
    list.print();
}

void question_2() {

    //创建单链表.
    SgLinkList<char> list;
    list.insert('1', 0);
    list.insert('a', 1);
    list.insert('b', 2);
    list.insert('&', 3);

    cout << "Q2: I'm going to shard by type of char" << endl;

    //切分
    list.spite();
}

void question_3() {

    //创建双向链表.
    DuLinkList<int> DL1;
    DL1.push_end(1);
    DL1.push_end(2);
    DL1.push_end(3);
    DL1.push_end(4);
    DL1.push_end(5);
    DL1.push_end(6);
    cout << "Q3: sorting by freq" << endl;
    cout << "original: " << DL1 << endl;

    //访问双向链表结点.
    DL1.find(2);
    DL1.find(2);
    DL1.find(3);
    DL1.find(3);
    DL1.find(3);

    //根据频率排序
  //  DL1.sort();
    cout << "After accessing '2' twice, '3' thrice: " << DL1 << endl;
};