//
//  main.cpp
//  Homework4
//
//  Created by Jack Noren on 10/24/14.
//  Copyright (c) 2014 Jack Noren. All rights reserved.
//

#include <iostream>
#include <fstream> 
#include <string> 
#include "Minifier.h" 
#include "Queue.h"
#include "ModLinkedList.h"

using namespace std;
int main()
{
    
   Minifier A;
   
    string pathToFile  ="/Users/Jack/Dev/Untitled.txt";
    
    ifstream infile;
    
    infile.open(pathToFile);
    
    char letter;
    
    if(infile.good())
    {
        
        // just putting this in a while loop to print
        while(infile.good())
        {
            infile.get(letter);
            
            if(infile.good())
            {
               A.add(letter);
                
            }
        }
    }
    else
    {
        cout << "Count not open" <<pathToFile<< "\n";
    }
    
    // Here we print the final copy with no space but one in between 
    A.removingWhiteSpace();
    
};
