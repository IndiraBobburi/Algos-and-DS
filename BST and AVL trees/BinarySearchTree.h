//
//  BinarySearchTree.hpp
//  BST and AVL trees
//
//  Created by Indira Bobburi on 11/23/17.
//  Copyright © 2017 sjsu. All rights reserved.
//

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <string>
#include "BinaryNode.h"
#include <ctime>
#include <chrono>

using namespace std;

class BinarySearchTree
{
public:
    /**
     * Default constructor
     */
    BinarySearchTree();
    
    /**
     * Destructor
     */
    virtual ~BinarySearchTree();
    
    /**
     * Getter.
     * @return pointer to the root of the tree.
     */
    BinaryNode *getRoot() const;
    
    /**
     * Public member function to return the height of a subtree.
     * @return the height.
     */
    int height() const;
    
    /**
     * Public member function to find the minimum data item in a subtree.
     * @return the minimum data item in the tree
     *         or nullptr if the tree is empty.
     * @throw a string message if an error occurred.
     */
    long findMin() const throw(string);
    
    /**
     * Public member function to find the maximum data item in a subtree.
     * @return pointer to the maximum data item in the tree
     *         or nullptr if the tree is empty.
     * @throw a string message if an error occurred.
     */
    long findMax() const throw(string);
    
    /**
     * Public member function to empty a subtree.
     */
    void clear();
    
    /**
     * Is the tree empty?
     * @return true if and only if the tree is empty.
     */
    bool isEmpty() const;
    
    /**
     * Public member function to search for a data item in the tree.
     * @param data the data to search for.
     * @return true if and only if data is in the tree.
     */
    bool contains(const long data) const;
    
    /**
     * Public member function to insert a data item into a subtree
     * and set the new root of the subtree.
     * @param data the data to insert into the tree.
     */
    void insert(const long data);
    
    /**
     * Public member function to remove a data item from a subtree
     * and set the new root of the subtree.
     * Do nothing if the data item is not found.
     * @param data the data to remove.
     */
    void remove(const long data);
    
    //reset the counters
    void reset();
    
    //increment the elapsed time
    void increment_elapsed_time(const long msec);
    
    static long get_probe_count() {return probe_count;}
    static long get_comparison_count() {return comparison_count;}
    static long get_elapsed_time() {return elapsed_time;}
    
protected:
    /**
     * Protected member function to compute the height of a subtree.
     * @param ptr pointer to the root node of the subtree.
     * @return the height.
     */
    virtual int height(const BinaryNode *ptr) const;
    
    /**
     * Protected member function to insert a data item into a subtree
     * and set the new root of the subtree.
     * @param data the data to insert.
     * @param ptr pointer to the root node of the subtree.
     */
    virtual void insert(const long data, BinaryNode* &ptr);
    
    /**
     * Protected member function to remove a data item from a subtree
     * and set the new root of the subtree.
     * Do nothing if the data item is not found.
     * @param data the data to remove.
     * @param ptr pointer to the root node of the subtree.
     */
    virtual void remove(const long data, BinaryNode* &ptr);
    
protected:
    static long probe_count;
    static long comparison_count;
    static long elapsed_time;
    
private:
    BinaryNode *root;  // tree root
    
    /**
     * Private member function to find the minimum data item in a subtree.
     * @param ptr pointer to the root node of the subtree.
     * @return pointer to the node containing the smallest data item
     *         or nullptr if the subtree is empty.
     */
    BinaryNode *findMin(BinaryNode *ptr) const;
    
    /**
     * Private member function to find the maximum data item in a subtree.
     * @param ptr pointer to the root node of the subtree.
     * @return pointer to the node containing the largest data item
     *         or nullptr if the subtree is empty.
     */
    BinaryNode *findMax(BinaryNode *ptr) const;
    
    /**
     * Private member function to empty a subtree.
     * @param ptr pointer to the root node of the subtree.
     */
    void clear(BinaryNode* &ptr);
    
    /**
     * Private member function to search for a data item in a subtree.
     * @param data the data to search for.
     * @param ptr pointer to the root node of the subtree.
     * @return true if and only if data is in the tree.
     */
    bool contains(const long data, BinaryNode *ptr) const;
    
    
};


#endif // BINARY_TREE_CHECKER_H
