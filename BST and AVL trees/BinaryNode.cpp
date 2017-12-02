//
//  BinaryNode.cpp
//  BST and AVL trees
//
//  Created by Indira Bobburi on 11/23/17.
//  Copyright © 2017 sjsu. All rights reserved.
//

#include "BinaryNode.h"

BinaryNode::BinaryNode(const long data)
: data(data), height(0), left(nullptr), right(nullptr)
{
}

BinaryNode::BinaryNode(const long data, BinaryNode *left, BinaryNode *right)
: data(data), height(0), left(left), right(right)
{
    int temp = 0;
    if(left != nullptr)
        temp = left->height;
    
    if(temp > height)
        height = temp+1;
    
    if(right != nullptr)
        temp = right->height;
    
    if(temp >= height)
        height = temp+1;
}

BinaryNode::~BinaryNode()
{
}
