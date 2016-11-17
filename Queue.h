//
//  Header.h
//  Homework4
//
//  Created by Jack Noren on 10/24/14.
//  Copyright (c) 2014 Jack Noren. All rights reserved.
//

#pragma once 
#include "ModLinkedList.h" 

template <class T>
class Queue
{
public:
    
    void enqueue(const T& elem); //just inserting at the rear / Linked List
    T dequeue();       // removing from the front / linkedList
    bool isEmpty(); // check if empty
    int size(); // checking the size
    
    
    
private:
    ModLinkedList <T> list;
    
    
};



template <class T>
void Queue <T>:: enqueue(const T& elem)
{
    // im piggy backing my linked list basically
    list.insertAtRear(elem);
}



template <class T>
T Queue <T>:: dequeue()
{
    // this is just using my linkedlist to removing this element from the front of the acutal queue
    return list.removeFromFront();
}

template <class T>
bool Queue <T>:: isEmpty()
{
    // checking queue    is it empty?
    return list.isEmpty();
}

template <class T>
int Queue <T>:: size()
{
    // this is just going to return the size of the queue
    return list.size();
}

