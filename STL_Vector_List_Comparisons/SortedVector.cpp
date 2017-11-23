//
//  SortedVector.cpp
//  STL_vector_list
//
//  Created by Indira Bobburi on 10/24/17.
//  Copyright © 2017 sjsu. All rights reserved.
//

#include <iostream>
#include <iterator>
#include "SortedVector.h"

using namespace std;

SortedVector::SortedVector()
{
    Node::reset();
}

SortedVector::~SortedVector()
{
    Node::reset();
    vector<Node*>::iterator it;
    for(it = data.begin(); it != data.end(); it++)
    {
        delete (*it);
    }
}

int SortedVector::size() const { return data.size(); }

bool SortedVector::check() const
{
    if (data.size() == 0) return true;
    
    vector<Node*>::const_iterator it = data.begin();
    vector<Node*>::const_iterator prev = it;
    
    it++;
    
    // Ensure that each node is greater than the previous node.
    while ((it != data.end()) && (*(*it) > *(*prev)))
    {
        prev = it;
        it++;
    }
    
    return it == data.end();  // Good if reached the end.
}

void SortedVector::prepend(const long value)
{
    Node* node = new Node(value);
    data.insert(data.begin(), node);
}

void SortedVector::append(const long value)
{
    Node* node = new Node(value);
    data.push_back(node);
}

void SortedVector::remove(const int index)
{
    Node* node = at(index);
    if(index < data.size())
        data.erase(data.begin()+index);
    delete node;
}

void SortedVector::insert(const long value)
{
    
    vector<Node*>::iterator it;
    for(it = data.begin(); it != data.end(); it++)
    {
        if((*it)->get_value() > value)
            break;
    }
    Node *node = new Node(value);
    data.insert(it, node);
}

Node* SortedVector::at(const int index) const
{
    return data.at(index);
}

