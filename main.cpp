#include <iostream>
#include "link.h"
int main() {
    Link<int> DL1;
    DL1.push_end(1);
    DL1.push_end(2);
    DL1.find(2);
    DL1.push_end(4);
    DL1.print();
    return 0;
}
