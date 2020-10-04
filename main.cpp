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
int main() {
   // question_3();
    question_1();


    return 0;
}
void question_1(){
    CirLinkList<int> list;
    list.insert(1,0);
    list.insert(2,1);
    list.insert(3,2);
    auto s = list.getHead()->next;

    cout<<"Q2: remove the previous node of S from circle-list-link"<<endl;
    cout<<"Original list: ";list.print();

    list.removeByPos(list.find(s->val));
    cout<<"After removing: ";list.print();
}
void question_3(){
        DuLinkList<int> DL1;
        DL1.push_end(1);
        DL1.push_end(2);
        DL1.push_end(3);
        DL1.push_end(4);
        DL1.push_end(5);
        DL1.push_end(6);
        cout<<"original: "<<DL1<<endl;

        DL1.find(2);
        DL1.find(2);
        DL1.find(3);
        DL1.find(3);
        DL1.find(3);
        DL1.sort();
        cout<<"After accessing '2' twice, '3' thrice: "<<DL1<<endl;
};