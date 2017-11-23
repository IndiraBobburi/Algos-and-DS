//
//  WordVector.cpp
//  STL Vector and Map
//
//  Created by Indira Bobburi on 11/7/17.
//  Copyright © 2017 sjsu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include "WordVector.h"

/***** Complete this file. *****/

using namespace std;

WordVector::WordVector()
{
}

WordVector::~WordVector()
{
    data.clear();
}

/*Extra credits code with binary search*/
Word *WordVector::insert(const string text)
{
    if(data.size() == 0)
        return &(*data.insert(data.begin(), Word(text)));
    
    int low = 0;
    int high = get_size();
    int mid;
    while(low <= high)
    {
        mid = (low+high)/2;
        
        if(high == low)
            break;
        
        string str = data.at(mid).get_text();
        
        if(str == text)
        {
            data.at(mid).increment_count();
            return &data.at(mid);
        }
        else if(str < text)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    
    return &(*data.insert(data.begin()+mid, Word(text)));
}

Word *WordVector::search(const string text)
{
    int low = 0;
    int high = get_size();
    int mid;
    
    while(low <= high)
    {
        mid = (low+high)/2;
        
        string str = data.at(mid).get_text();
        
        if(str == text)
        {
            return &data.at(mid);
        }
        else if(str < text)
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }
    
    return nullptr;
}

const long WordVector::get_size()
{
    return data.size();
}

vector<Word> WordVector::get_data() const
{
    return data;
}
