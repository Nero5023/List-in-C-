//
//  DoubleLinkedList.cpp
//  List
//
//  Created by Nero Zuo on 15/10/9.
//  Copyright © 2015年 Nero. All rights reserved.
//

//#include <iostream>
//using namespace std;
//template <class T>
//class DoubleLindedList {
//    
//    typedef struct ListNode {
//        T data;
//        struct ListNode *successor;//后继
//        struct ListNode *prescrsor;//前驱
//    }ListNode;
//    
//    ListNode *head;
//    ListNode *tail;
//    int count;
//    
//    ListNode *traverseToIndex(int index) const {
//        ListNode *node = head;
//        int i = 0;
//        while (node != NULL) {
//            if (i == index) {
//                break;
//            }
//            node = node->successor;
//            i++;
//        }
//        if (node == NULL) {
//            cout << "Out of range";
//        }
//        return node;
//        
//    }
//public:
//    DoubleLindedList() {
//        ListNode *node = new ListNode;
//        node->successor = NULL;
//        node->prescrsor = NULL;
//        head = node;
//        tail = node;
//        count =0;
//    }
//    
//    void pushBack(T data) {
//        ListNode *node = new ListNode;
//        node->successor = NULL;
//        node->prescrsor = tail;
//        node->data = data;
//        tail->successor = node;
//        tail = node;
//        count++;
//    }
//    
//    void insertAtIndex(T newData, int index) {
//        ListNode *node = traverseToIndex(index - 1);
//        if (node == NULL) {
//            return;
//        }
//        
//        ListNode *newNode = new ListNode;
//        newNode->data = newData;
//        newNode->successor = node->successor;
//        newNode->prescrsor = node;
//        if (node->successor == NULL) {
//            node->successor = newNode;
//        }else {
//            node->successor->prescrsor = newNode;
//            node->successor = newNode;
//        }
//        count++;
//        if (newNode->successor == NULL) {
//            tail = newNode;
//        }
//    }
//    
//    T deleteAtIndex(int index) {
//        ListNode *node = traverseToIndex(index - 1);
//        if (node->successor == NULL) {
//            cout << "Out of range";
//            return NULL;
//        }
//        ListNode *deleteNode = node->successor;
//        if (deleteNode->successor != NULL) {
//            deleteNode->successor->prescrsor = node;
//        }
//        node->successor = deleteNode->successor;
//        T deleteData = deleteNode->data;
//        if (deleteNode->successor == NULL) {
//            tail = node;
//        }
//        delete deleteNode;
//        count--;
//        return deleteData;
//    }
//    
//    T dataAtIndex(int index) const {
//        ListNode *node = traverseToIndex(index);
//        if (node == NULL) {
//            return NULL;
//        }
//        return node->data;
//    }
//    
//    void print() const {
//        ListNode *node = head;
//        while (node->successor != NULL) {
//            node = node->successor;
//            cout << node->data << endl;
//        }
//    }
//    
//    ~DoubleLindedList() {
//        ListNode *p;
//        ListNode *pn;
//        p = head;
//        pn = head->successor;
//        while (pn != NULL) {
//            delete p;
//            p = pn;
//            pn = pn->successor;
//        }
//        delete p;
//    }
//
//    
//};


#include <iostream>
using namespace std;
template <class T>
class DoubleLindedList {
    
    typedef struct ListNode {
        T data;
        struct ListNode *successor;//后继
        struct ListNode *prescrsor;//前驱
    }ListNode;
    
    ListNode *head;
    ListNode *tail;
    int count;
    
    ListNode *traverseToIndex(int index) const {
        ListNode *node = head;
        int i = 0;
        while (node->successor != NULL) {
            if (i == index) {
                break;
            }
            node = node->successor;
            i++;
        }
        if (node->successor == NULL) {
            cout << "Out of range";
        }
        return node;
        
    }
public:
    DoubleLindedList() {
        ListNode *headNode = new ListNode;
        ListNode *tailNode = new ListNode;
        headNode->successor = tailNode;
        headNode->prescrsor = NULL;
        tailNode->prescrsor = headNode;
        tailNode->successor = NULL;
        head = headNode;
        tail = tailNode;
        count =0;
    }
    
    DoubleLindedList(T inputArray[], int n) {
        ListNode *headNode = new ListNode;
        ListNode *tailNode = new ListNode;
        headNode->successor = tailNode;
        headNode->prescrsor = NULL;
        tailNode->prescrsor = headNode;
        tailNode->successor = NULL;
        head = headNode;
        tail = tailNode;
        count =0;
        
        for (int i = 0 ; i < n; i++) {
            ListNode *node = new ListNode;
            node->successor = tail;
            node->prescrsor = tail->prescrsor;
            node->data = inputArray[i];
            tail->prescrsor = node;
            node->prescrsor->successor = node;
            count++;
        }
    }
    
    void pushBack(T data) {
        ListNode *node = new ListNode;
        node->successor = tail;
        node->prescrsor = tail->prescrsor;
        node->data = data;
        tail->prescrsor = node;
        node->prescrsor->successor = node;
        count++;
    }
    
    void insertAtIndex(T newData, int index) {
        if (index > count + 1) {
            cout << "Out of range" << endl;
            return;
        }
        
        
        ListNode *node = traverseToIndex(index - 1);
        if (node == NULL) {
            return;
        }
        
        ListNode *newNode = new ListNode;
        newNode->data = newData;
        newNode->successor = node->successor;
        newNode->prescrsor = node;

        node->successor->prescrsor = newNode;
        node->successor = newNode;
        
        count++;
    }
    
    T deleteAtIndex(int index) {
        ListNode *node = traverseToIndex(index - 1);
        if (node->successor == NULL) {
            cout << "Out of range";
            return NULL;
        }
        ListNode *deleteNode = node->successor;
        
        node->successor = deleteNode->successor;
        deleteNode->successor->prescrsor = node;
        T deleteData = deleteNode->data;
        delete deleteNode;
        count--;
        return deleteData;
    }
    
    T dataAtIndex(int index) const {
        ListNode *node = traverseToIndex(index);
        if (node == NULL) {
            return NULL;
        }
        return node->data;
    }
    
    void print() const {
        ListNode *node = head;
        while (node->successor->successor != NULL) {
            node = node->successor;
            cout << node->data << " ";
        }
        cout << endl;
    }
    
    ~DoubleLindedList() {
        ListNode *p;
        ListNode *pn;
        p = head;
        pn = head->successor;
        while (pn != NULL) {
            delete p;
            p = pn;
            pn = pn->successor;
        }
        delete p;
    }
    
    
};

