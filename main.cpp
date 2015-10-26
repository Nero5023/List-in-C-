//
//  main.cpp
//  List
//
//  Created by Nero Zuo on 15/10/9.
//  Copyright © 2015年 Nero. All rights reserved.
//

#include <iostream>
#include "SingleLinkedList.cpp"
#include "DoubleLinkedList.cpp"
#include "SequenceList.cpp"

int main(int argc, const char * argv[]) {


    
//    DoubleLindedList<int> dList;
//    dList.pushBack(11);
//    dList.pushBack(12);
//    dList.pushBack(13);
//    dList.pushBack(14);
//    dList.print();
//    dList.insertAtIndex(10, 5);
//    dList.print();
//    dList.insertAtIndex(10, 1);
//    dList.print();
//    int x = dList.dataAtIndex(5);
//    printf("%d",x);
    
//    int arrray[] = {1,2,3,4,5};
//    SequenceList<int> seqList(arrray, 5);
//    seqList.print();
//    seqList.insertAtIndex(10, 0);
//    seqList.print();
//    seqList.insertAtIndex(11, 6);
//    seqList.print();
//    seqList.insertAtIndex(12, 8);
//    seqList.print();
//    seqList.deleteAtIndex(2);
//    seqList.print();
//    cout << seqList.dataAtIndex(2) << endl;
//    seqList.deleteAtIndex(2);
    
//    int array[] = {1,2,3,4,5};
//    SingledLindedList<int> list(array, 5);
//    list.push_back(6);
//    list.print();
//    list.insertAtIndex(10, 1);
//    list.print();
//    list.insertAtIndex(11, 8);
//    list.print();
//    list.deleteAtIndex(4);
//    list.print();
//    cout << list.dataAtIndex(2) << endl;
    
    int array[] = {1,2,3,4,5};
    DoubleLindedList<int> dList(array, 5);
    dList.insertAtIndex(10, 1);
    dList.print();
    dList.insertAtIndex(11, 7);
    dList.print();
    dList.insertAtIndex(12, 9);
    dList.deleteAtIndex(2);
    dList.print();
    cout << dList.dataAtIndex(2) << endl;
    
    
    
}
