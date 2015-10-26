//
//  SequenceList.cpp
//  List
//
//  Created by Nero Zuo on 15/10/16.
//  Copyright © 2015年 Nero. All rights reserved.
//

#include <iostream>
#define ArraySize 10
using namespace::std;
template <class T>
class SequenceList {
    int magnification;
//    T (*array)[ArraySize];
    T *array;
    int currentSize;
    int getMaxSize() {
        return currentSize * magnification;
    }
public:
    SequenceList() {
        magnification = 1;
        currentSize = 0;
        array = new T[ArraySize];
    }
    
    SequenceList(T inputArray[], int n) {
        currentSize = n;
        magnification = n/10 + 1;
        array = new T[ArraySize*magnification];
        for (int i = 0; i < n; i++) {
            array[i] = inputArray[i];
        }
    }
    void insertAtIndex(T data, int index){
        if (index < 0 || index > currentSize) {
            cout << "Out of Range" <<endl;
            return;
        }
        if (currentSize == getMaxSize()) {
            enlargeArray();
        }
        for (int i = currentSize; i > index; i--) {
            array[i] = array[i-1];
        }
        array[index] = data;
        currentSize++;
    }
    
    void print() {
        for (int i = 0; i < currentSize ; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
    
    T deleteAtIndex(int index) {
        if (index < 0 || index >= currentSize) {
            cout << "Out of Rane" << endl;
            return NULL;
        }
        if (index == currentSize - 1) {
            currentSize--;
            return array[index];
        }
        currentSize --;
        T data = array[index];
        for (int i = index ; i < currentSize; i ++) {
            array[i] = array[i + 1];
        }
        return data;
    }
    
    T dataAtIndex(int index) {
        if (index < 0 || index >= currentSize) {
            cout << "Out of Rane" << endl;
            return NULL;
        }
        return array[index];
    }
    
    void enlargeArray() {
        magnification++;
        T *temp = array;
        T *newArray = new T[ArraySize*magnification];
        for (int i = 0; i < currentSize; i++) {
            newArray[i] = array[i];
        }
        array = newArray;
        delete [] temp;
    }
    
};
