//
//  Node.cpp
//  SortingAlgorithms
//
//  Created by Indira Bobburi on 11/11/17.
//  Copyright © 2017 sjsu. All rights reserved.
//

#include "Node.h"
#include "Element.h"

Node::Node(Element ele) : element(ele)
{
}

Element& Node::getData()
{
    return element;
}

Node* Node::getNext() const
{
    return next;
}
