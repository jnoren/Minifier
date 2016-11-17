//
//  Minifier.h
//  Homework4
//
//  Created by Jack Noren on 10/25/14.
//  Copyright (c) 2014 Jack Noren. All rights reserved.
//

#pragma once

#include "Queue.h"

class Minifier
{
    
public:
    
    Minifier();
    void add(char currentChar);
    void printFile();
    void removingWhiteSpace();
    
    
    
private:
    Queue <char> minifiedCode;
    bool isCode;
    bool isFirstSlash;
    bool isQuote;
    bool isSingleLineComment;
    bool isMultiCommentLine;
    bool isStartMultiLineComment;
    
    
};



