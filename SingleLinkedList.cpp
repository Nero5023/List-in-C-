//
//  SingleLinkedList.cpp
//  List
//
//  Created by Nero Zuo on 15/10/9.
//  Copyright © 2015年 Nero. All rights reserved.
//

#include <iostream>
using namespace std;
template <class T>
class SingledLindedList {
    
    typedef struct ListNode {
        T data;
        struct ListNode *next;
    }ListNode;
    
    ListNode *head;
    ListNode *tail;
    int count;
    
    ListNode *traverseToIndex(int index) const {
        ListNode *node = head;
        int i = 0;
        while (node != NULL) {
            if (i == index) {
                break;
            }
            node = node->next;
            i++;
        }
        if (node == NULL) {
            cout << "Out of range";
        }
        return node;
        
    }
    
public:
    SingledLindedList() {
        ListNode *node = new ListNode;
        head = node;
        head->next = NULL;
        tail = node;
        count = 0;
    }
    
    SingledLindedList(T inputArray[], int n) {
        ListNode *node = new ListNode;
        head = node;
        head->next = NULL;
        tail = node;
        count = 0;
        
        for (int i = 0; i < n; i ++) {
            ListNode *node = new ListNode;
            node->data = inputArray[i];
            node->next = NULL;
            tail->next = node;
            tail = node;
            count++;
        }
    }
    
    void push_back(T newData) {
        ListNode *node = new ListNode;
        node->data = newData;
        node->next = NULL;
        tail->next = node;
        tail = node;
        count++;
    }
    
    void insertAtIndex(T newData, int index) {
        ListNode *node = traverseToIndex(index - 1);
        if (node == NULL) {
            return;
        }
        
        ListNode *newNode = new ListNode;
        newNode->data = newData;
        newNode->next = node->next;
        node->next = newNode;
        count++;
        if (newNode->next == NULL) {
            tail = newNode;
        }
    }
    
    T deleteAtIndex(int index) {
        ListNode *node = traverseToIndex(index - 1);
        if (node->next == NULL) {
            cout << "Out of range";
            return NULL;
        }
        ListNode *deleteNode = node->next;
        node->next = deleteNode->next;
        T deleteData = deleteNode->data;
        if (deleteNode->next == NULL) {
            tail = node;
        }
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
        while (node->next != NULL) {
            node = node->next;
            cout << node->data << " ";
        }
        cout << endl;
    }
    
    ~SingledLindedList() {
        ListNode *p;
        ListNode *pn;
        p = head;
        pn = head->next;
        while (pn != NULL) {
            delete p;
            p = pn;
            pn = pn->next;
        }
        delete p;
    }

};

