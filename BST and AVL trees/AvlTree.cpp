//
//  AvlTree.cpp
//  BST and AVL trees
//
//  Created by Indira Bobburi on 11/23/17.
//  Copyright © 2017 sjsu. All rights reserved.
//
#include <iostream>
#include "AvlTree.h"

using namespace std;

AvlTree::AvlTree()
: BinarySearchTree()
{
}

AvlTree::~AvlTree()
{
}

int AvlTree::height(const BinaryNode *ptr) const
{
    BinarySearchTree::probe_count++;
    return ptr == nullptr ? -1 : ptr->height;
}

void AvlTree::insert(const long data, BinaryNode* &ptr)
{
    BinarySearchTree::insert(data, ptr);
    rebalance(ptr);
}

void AvlTree::remove(const long data, BinaryNode* &ptr)
{
    BinarySearchTree::remove(data, ptr);
    rebalance(ptr);
}

BinaryNode *AvlTree::rebalance(BinaryNode* &ptr)
{
    //    cout << "=== Rebalance called on "
    //         << (ptr != nullptr ? to_string(ptr->data) : "null")
    //         << endl;
    BinarySearchTree::probe_count++;
    if(ptr == nullptr) return ptr;
    
    if( height(ptr->left) - height(ptr->right) > 1 )
    {
        BinarySearchTree::comparison_count++;
        if(height(ptr->left->left) > height(ptr->left->right))
        {
            ptr = singleRightRotation(ptr);
            //cout << "    --- Single right rotation at " << ptr->data << endl;
        }
        else
        {
            ptr = doubleLeftRightRotation(ptr);
            //cout << "    --- Double left right rotation at " << ptr->data << endl;
        }
    }
    else if(height(ptr->right) - height(ptr->left) > 1)
    {
        BinarySearchTree::comparison_count++;
        if(height(ptr->right->left) > height(ptr->right->right))
        {
            ptr = doubleRightLeftRotation(ptr);
            //cout << "    --- Double right left rotation at " << ptr->data << endl;
        }
        else
        {
            ptr = singleLeftRotation(ptr);
            //cout << "    --- Single left rotation at " << ptr->data << endl;
        }
    }
    
    BinarySearchTree::probe_count += 2;
    
    // Recompute the node's height.
    ptr->height = 1 + max(height(ptr->left), height(ptr->right));
    
    BinarySearchTree::comparison_count++;
    
    /*if (checkBalance(ptr) < 0)
    {
        cout << endl << "***** Tree unbalanced!" << endl;
    }*/
    
    return ptr;
}

BinaryNode *AvlTree::singleRightRotation(BinaryNode *k2)
{
    BinaryNode* temp = k2->left;
    k2->left = temp->right;
    temp->right = k2;
    
    //update height
    temp->right->height = 1 + max(height(temp->right->left), height(temp->right->right));
    
    BinarySearchTree::probe_count += 7;
    BinarySearchTree::comparison_count++;
    
    return temp;
}

BinaryNode *AvlTree::doubleLeftRightRotation(BinaryNode *k3)
{
    k3->left = singleLeftRotation(k3->left);
    k3->left->height = 1 + max(height(k3->left->left), height(k3->left->right));
    
    BinarySearchTree::probe_count += 5;
    BinarySearchTree::comparison_count++;
    
    return singleRightRotation(k3);
}

BinaryNode *AvlTree::doubleRightLeftRotation(BinaryNode *k1)
{
    k1->right = singleRightRotation(k1->right);
    k1->right->height = 1 + max(height(k1->right->left), height(k1->right->right));
    
    BinarySearchTree::probe_count += 5;
    BinarySearchTree::comparison_count++;
    
    return singleLeftRotation(k1);
}

BinaryNode *AvlTree::singleLeftRotation(BinaryNode *k2)
{
    BinaryNode* temp = k2->right;
    k2->right = temp->left;
    temp->left = k2;
    
    //update height
    temp->left->height = 1 + max(height(temp->left->left), height(temp->left->right));
    
    BinarySearchTree::probe_count += 7;
    BinarySearchTree::comparison_count++;
    
    return temp;
}

int AvlTree::checkBalance(BinaryNode *ptr)
{
    BinarySearchTree::probe_count++;
    if (ptr == nullptr) return -1;
    
    int leftHeight  = checkBalance(ptr->left);
    int rightHeight = checkBalance(ptr->right);
    
    if ((abs(height(ptr->left) - height(ptr->right)) > 1)
        || (height(ptr->left)  != leftHeight)
        || (height(ptr->right) != rightHeight))
    {
        return -2;       // unbalanced
    }
    
    return height(ptr);  // balanced
}

