//
//1. 双向链表.
//
//Created by 胡海彬(tomo) on 2020/9/22.
//
#include <iostream>
#include "DuLinkList.h"
#include "SgLinkList.h"
int main() {
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

    return 0;
}
