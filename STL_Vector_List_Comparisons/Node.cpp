//
//  Node.cpp
//  STL_vector_list
//
//  Created by Indira Bobburi on 10/24/17.
//  Copyright © 2017 sjsu. All rights reserved.
//

#include "Node.h"
#include <iostream>

using namespace std;

long Node::constructor_count;
long Node::copy_count;
long Node::destructor_count;

Node::Node(const long the_value)
{
    value = the_value;
    constructor_count++;
}

Node::Node(const Node& other)
{
    value = other.get_value();
    copy_count++;
}

Node::~Node()
{
    destructor_count++;
}

long Node::get_value() const
{
    return value;
}

long Node::get_constructor_count()
{
    return constructor_count;
}

long Node::get_copy_count()
{
    return copy_count;
}

long Node::get_destructor_count()
{
    return destructor_count;
}


void Node::reset()
{
    constructor_count = 0;
    copy_count = 0;
    destructor_count = 0;
}

bool Node::operator ==(const Node& other) const
{
    return (value == other.get_value());
}

bool Node::operator  >(const Node& other) const
{
    return (value > other.get_value());
}
