//
//  BinaryNode.h
//  BST and AVL trees
//
//  Created by Indira Bobburi on 11/23/17.
//  Copyright © 2017 sjsu. All rights reserved.
//

#ifndef BINARY_NODE_H
#define BINARY_NODE_H

class BinaryNode
{
public:
    /**
     * Constructor.
     * @param data the data item.
     */
    BinaryNode(const long data);
    
    /**
     * Constructor.
     * @param data the data item.
     * @param left the left link.
     * @param right the right link.
     */
    BinaryNode(const long data, BinaryNode *left, BinaryNode *right);
    
    /**
     * Destructor.
     */
    virtual ~BinaryNode();
    
    long data;
    int height;  // node height
    
    BinaryNode *left;
    BinaryNode *right;
};

#endif // BINARY_NODE_H
