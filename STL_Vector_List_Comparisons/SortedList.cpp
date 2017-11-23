//
//  SortedList.cpp
//  STL_vector_list
//
//  Created by Indira Bobburi on 10/24/17.
//  Copyright © 2017 sjsu. All rights reserved.
//

#include "SortedList.h"
#include <iostream>
#include <iterator>

using namespace std;

SortedList::SortedList()
{
    Node::reset();
}

SortedList::~SortedList()
{
    Node::reset();
}

int SortedList::size() const
{
    return data.size();
}

bool SortedList::check()
{
    if (data.size() == 0) return true;
    
    list<Node>::iterator it = data.begin();
    list<Node>::iterator prev = it;
    
    it++;
    
    // Ensure that each node is greater than the previous node.
    while ((it != data.end()) && (*it > *prev))
    {
        prev = it;
        it++;
    }
    
    return it == data.end();  // Good if reached the end.
}

void SortedList::prepend(const long value)
{
    Node node = Node(value);
    data.push_front(node);
}

void SortedList::append(const long value)
{
    Node node = Node(value);
    data.push_back(node);
}

void SortedList::remove(const int index)
{
    list<Node>::iterator it = data.begin();
    advance(it, index);
    if(index < data.size())
        data.erase(it);
}

void SortedList::insert(const long value)
{
    std::list<Node>::iterator it;
    
    //find iterator position to insert
    for(it = data.begin(); it != data.end(); it++)
    {
        if((*it).get_value() > value)
            break;
    }
    
    Node node(value);
    data.insert(it, node);
}

Node SortedList::at(const int index)
{
    if (data.size() > index)
    {
        std::list<Node>::iterator it = data.begin();
        std::advance(it, index);
        return *it;
    }
    return NULL;
}

