//
//  WordMap.cpp
//  STL Vector and Map
//
//  Created by Indira Bobburi on 11/7/17.
//  Copyright © 2017 sjsu. All rights reserved.
//

#include <iostream>
#include <map>
#include "WordMap.h"

using namespace std;

WordMap::WordMap()
{
}

WordMap::~WordMap()
{
    data.clear();
}

Word *WordMap::insert(const string text)
{
    std::pair<wordMap::iterator,bool> ret;
    ret = data.insert(std::pair<string, Word>(text, Word(text)));
    
    if(ret.second == false) //text already exists
    {
        ret.first->second.increment_count();
    }
    
    return &(ret.first->second);
}

Word *WordMap::search(const string text)
{
    wordMap::iterator it;
    it = data.find(text);
    
    if(it != data.end())
        return &(it->second);
    else
        return nullptr;
}

const long WordMap::get_size()
{
    return data.size();
}

wordMap& WordMap::get_data()
{
    return data;
}
