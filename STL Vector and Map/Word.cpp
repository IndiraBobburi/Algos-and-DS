//
//  Word.cpp
//  STL Vector and Map
//
//  Created by Indira Bobburi on 11/7/17.
//  Copyright © 2017 sjsu. All rights reserved.
//

#include <string>
#include "Word.h"
using namespace std;

Word::Word() : text(""), count(0)
{
}

Word::Word(string text) : text(text), count(1)
{
}

Word::~Word() {}

int Word::get_count() const
{
    return count;
}

string Word::get_text() const
{
    return text;
}

bool Word::operator !=(const Word& other)
{
    return (text != other.text);
}

int Word::compare_text(const string val)
{
    return text.compare(val);
}

void Word::increment_count()
{
    count++;
}
