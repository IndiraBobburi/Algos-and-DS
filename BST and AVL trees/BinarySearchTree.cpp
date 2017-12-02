//
//  BinarySearchTree.cpp
//  BST and AVL trees
//
//  Created by Indira Bobburi on 11/23/17.
//  Copyright © 2017 sjsu. All rights reserved.
//

#include <iostream>
#include <string>
#include "BinarySearchTree.h"
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

long BinarySearchTree::probe_count = 0;
long BinarySearchTree::comparison_count = 0;
long BinarySearchTree::elapsed_time = 0;

BinarySearchTree::BinarySearchTree() : root(nullptr)
{
}

BinarySearchTree::~BinarySearchTree()
{
    clear();
}

BinaryNode *BinarySearchTree::getRoot() const { probe_count++; return root; }

int BinarySearchTree::height() const { return height(root); }

int BinarySearchTree::height(const BinaryNode *ptr) const
{
    if(ptr != nullptr)
    {
        probe_count++;
        return (1 + max(height(ptr->left), height(ptr->right)));
    }
    else
    {
        return -1;
    }
}

long BinarySearchTree::findMin() const throw(string)
{
    if (isEmpty()) throw(string("Empty tree"));
    
    probe_count++;
    
    return findMin(root)->data;
}

BinaryNode *BinarySearchTree::findMin(BinaryNode *ptr) const
{
    if(ptr == nullptr) return nullptr;
    
    while( ptr->left != nullptr )
    {
        ptr = ptr->left;
        probe_count++;
    }
    
    probe_count++;
    
    return ptr;
}

long BinarySearchTree::findMax() const throw(string)
{
    if (isEmpty()) throw(string("Empty tree"));
    
    probe_count++;
    
    return findMax(root)->data;
}

BinaryNode *BinarySearchTree::findMax(BinaryNode *ptr) const
{
    if(ptr == nullptr) return nullptr;
    
    while(ptr->right != nullptr)
    {
        ptr = ptr->right;
        probe_count++;
    }
    
    probe_count++;
    return ptr;
}

void BinarySearchTree::clear()
{
    clear(root);
}

void BinarySearchTree::clear(BinaryNode* &ptr)
{
    if(ptr != nullptr)
    {
        probe_count++;
        clear(ptr->left);
        clear(ptr->right);

        delete ptr;
    }
}

bool BinarySearchTree::isEmpty() const
{
    probe_count++;
    return root == nullptr;
}

bool BinarySearchTree::contains(const long data) const
{
    return contains(data, root);
}

bool BinarySearchTree::contains(const long data, BinaryNode *ptr) const
{
    if(ptr == nullptr) return false;
    
    probe_count++;
    if(data == ptr->data)
    {
        comparison_count++;
        return true;
    }
    else if(data < ptr->data)
    {
        comparison_count += 2;
        return contains(data, ptr->left);
    }
    else
    {
        comparison_count += 2;
        return contains(data, ptr->right);
    } 
}

void BinarySearchTree::insert(const long data)
{
    steady_clock::time_point start_time = steady_clock::now();

    insert(data, root);

    steady_clock::time_point end_time = steady_clock::now();
    long msec = duration_cast<microseconds>(end_time - start_time).count();
    this->increment_elapsed_time(msec);
}

void BinarySearchTree::insert(const long data, BinaryNode* &ptr)
{
    //    cout << "=== Insert called on "
    //         << (ptr != nullptr ? to_string(ptr->data) : "null")
    //         << endl;
    probe_count++;
    if(ptr == nullptr)
    {
        ptr = new BinaryNode(data);
    }
    else if(data < ptr->data)
    {
        comparison_count++;
        insert(data, ptr->left);
    }
    else if(data > ptr->data)
    {
        comparison_count += 2;
        insert(data, ptr->right);
    }
}

void BinarySearchTree::remove(const long data)
{
    remove(data, root);
}

void BinarySearchTree::remove(const long data, BinaryNode* &ptr)
{
    //    cout << "=== Remove called on "
    //         << (ptr != nullptr ? to_string(ptr->data) : "null")
    //         << endl;
    probe_count++;
    if(ptr == nullptr) return; //not found
    else if(data < ptr->data)
    {
        comparison_count++;
        remove(data, ptr->left);
    }
    else if(data > ptr->data)
    {
        comparison_count += 2;
        remove(data, ptr->right);
    }
    else //data found
    {
        if(ptr->left != nullptr && ptr->right != nullptr)
        {
            BinaryNode* smallest = findMin(ptr->right);
            ptr->data = smallest->data;
            
            comparison_count++;
            probe_count += 3;
            remove(ptr->data, ptr->right); //don't pass smallest here as we need the original ptr to be deleted
        }
        else
        {
            BinaryNode* delNode = ptr;
            if(ptr->left == nullptr)
            {
                ptr = ptr->right;
                probe_count++;
            }
            else
            {
                ptr = ptr->left;
                probe_count += 2;
            }
            
            delete delNode;
        }
    }
}

void BinarySearchTree::reset()
{
    probe_count = 0;
    comparison_count = 0;
    elapsed_time = 0;
}

void BinarySearchTree::increment_elapsed_time(const long msec) 
{ 
    elapsed_time += msec; 
}
