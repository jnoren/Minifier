//
//  Minifier.cpp
//  Homework4
//
//  Created by Jack Noren on 10/25/14.
//  Copyright (c) 2014 Jack Noren. All rights reserved.
//

#include "Minifier.h"
#include "Queue.h" 
#include <iostream> 

using namespace std;


Minifier:: Minifier()

{   //cont
    isCode = true;  // we know were starting in code // everthing else we are not sure until we get to it
    isFirstSlash = false; 
    isQuote = false;
    isSingleLineComment = false;
    isMultiCommentLine = false;
    isStartMultiLineComment = false;
}
void Minifier::printFile()
{
    while(!minifiedCode.isEmpty())
    {   //as were dequeuing were getting seperate characters (kinda like popping stack)
        // keeps printing until its empty
        cout<< minifiedCode.dequeue();
        
    }
    
}
// just checking if there is multi space / redundent space and replacing with a single space (basic)

void Minifier:: removingWhiteSpace()
{
    char print;
    // just deleting space
    bool isPreviousASpace = false;
    
    int size = minifiedCode.size();
    for(int i = 0; i < size; i++)
    {
        print = minifiedCode.dequeue();
        // checking to see if new line
        if(print ==' ' || print == '\n' || print =='\t')
        {
            // is checking to see if previous was a space or (whitespace)  // TT F 
            if(isPreviousASpace == false)
            {
                //if not a whitespace it printout a single space
                if(i != 0)
                    cout << ' ';
                
            }
            // this will only print it out if this becomes true
            isPreviousASpace = true;
            
        }
        else
        {
            isPreviousASpace = false;
             // this will print
            cout<< print;
        }
    
    }
}


void Minifier:: add(char currentChar)
{
    // on the very first run this will for sure go through but can change after
    if(isCode)
    {
        //just checking if the first comment has a "/" in it // might be a comment
        if (currentChar == '/')
        {   // check to see if slash before that (if this is true we are offically in a comment
            if(isFirstSlash)
            {
                // at this point the currentChar is / and the last character / and this means that this is a single line comment.
                
                isCode = false;
                
                //this is just reset to false
                
                isFirstSlash = false;
                
                //this is just a single line comment
                
                isSingleLineComment = true;
                
            }
            
            else
            {
                // is the first char '/' and the last char does not have that then there is
                // no special case for this
                isFirstSlash = true;
                
            }
        }
    // could be multi line comment, or math equation.. checking
    else if(currentChar =='*')
    {
        //if  the currentChar case character has * is now checked for
        
        if(isFirstSlash)
        {
            
            // if this happens then this just means this it is a multi line comment not math equation
            isCode = false;
            isFirstSlash = false;
            isMultiCommentLine= true;
            
        }
        else
        {
            // pushing it back
            minifiedCode.enqueue('*');
        }
    }
        
    
    else if(currentChar == '"')
    {
        // is a currentChar
        isQuote = true;
        isSingleLineComment = false;
        isMultiCommentLine = false;
        isCode = false;
        // it makes sure to enque all things in a string or even a quote
        minifiedCode.enqueue(currentChar);
    }
    // this is every other case that comes
        else
        {
            if(isFirstSlash)
            {
                minifiedCode.enqueue('/');
                
                isFirstSlash = false;
            }
            
            minifiedCode.enqueue(currentChar);
        }
        
    }

    else if(isSingleLineComment)
    {
        //if the current char becomes a new line then it will be go back to being normal code
        if(currentChar == '\n')
        {
            isCode = true;
            isFirstSlash = false;
            isSingleLineComment = false;
        }
    }

    // if the muiltcomment part is true then it will be executed
    else if (isMultiCommentLine)
    {
        if(currentChar =='*')
        {
            isStartMultiLineComment = true;
        }
        // this will be check if the current character is a /
        else if(currentChar =='/')
        {
            if(isStartMultiLineComment)
            {
                // this will change the actual part back to normal code
                isStartMultiLineComment = false;
                isStartMultiLineComment = false;
                isCode = true;
            }
        }
        else
        {
            // if this is set then it will be executed
            if(isStartMultiLineComment)
            {
                //if the currentChar is checked to be a /
                if(currentChar =='/')
                {
                    isStartMultiLineComment = false;
                    isStartMultiLineComment = false;
                    isCode = true;
                }
                else
                {
                    // if none of these are true it means that there is just a false alarm * in the
                    // multline comment inStarMultiComment flag is reset
                    isStartMultiLineComment = false;
                }
            }
        }
    }

    // if this is reached is then
    else
    {
        if(currentChar =='"')
        {
            // this will end the quote and the enque the
            isCode = true;
            isQuote = false;
            minifiedCode.enqueue(currentChar);
        }
        else
        {
            
            minifiedCode.enqueue(currentChar);
            
        }
    }
}




