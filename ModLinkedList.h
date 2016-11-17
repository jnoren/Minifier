//
//  LinkedList.h
//  Homework4
//
//  Created by Jack Noren on 10/24/14.
//  Copyright (c) 2014 Jack Noren. All rights reserved.
//



#pragma once

#include <iostream>
#include <cmath>
#include "ModLinkedListException.h"

using namespace std;
template <class T>

class ModLinkedList

{
 
// I have modified the current LinkedList that I was using for 
public:
    
    ModLinkedList();
    ~ModLinkedList();
    void insertAtRear(const T& elem);
    int size();
    bool isEmpty();
    T removeFromFront();
    
    
private:
    
    int numOfElements;
    struct Node
    {
        T data;
        Node* p_left;
        Node* p_right;
        
    };
    
    Node* p_head;
    Node* p_tail;
    
    
    
};




template <class T>
ModLinkedList<T>::ModLinkedList()
{
    numOfElements = 0;
    p_head = 0;
    p_tail = 0;
    
}

template<class T>
ModLinkedList<T>:: ~ModLinkedList()
{
    Node* p_temp = p_head;
    while(p_temp != 0)
    {
        p_head = p_head -> p_right;
        
        delete p_temp;
        
        p_temp = p_head;
        
        numOfElements --;
    }
}



template <class T>
T ModLinkedList<T>:: removeFromFront()
{
    T retVal;
    
    Node* p_temp;
    // p_head->data= elem;
    
    
    if(numOfElements <=0)
    {
        ModLinkedListException ex;
        throw ex;
    }
   
    else if(numOfElements>1)
    {
        p_temp = p_head;
        
        retVal = p_head -> data;
        
        p_head = p_head ->p_right;
        
        p_head -> p_left = 0;
        
        delete p_temp;
        
        numOfElements--;
    }
    else
    {
        p_temp = p_head;
        retVal = p_head -> data;
        p_head = 0;
        delete p_temp;
        numOfElements--;
    }
    
    return retVal;
    
}




template <class T>
void ModLinkedList<T>:: insertAtRear(const T &elem)
{
    
    Node* p_newNode = new Node;
    //newNode's data is actually taken its right (address to the next one) and making
    p_newNode->data= elem;
    p_newNode->p_right= 0;
    p_newNode->p_left= p_tail;
    
    if(numOfElements==0)
    {
        p_head= p_newNode;
        
    }
    else
    {
        p_tail-> p_right= p_newNode;
    }
    p_tail = p_newNode;
    
    numOfElements++;
}


template <class T>
bool ModLinkedList<T>::isEmpty()
{
    return numOfElements<=0;
}

template <class T>
int ModLinkedList<T>:: size()
{
    return numOfElements; 
}

