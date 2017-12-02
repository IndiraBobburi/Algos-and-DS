//
//  main.cpp
//  BST and AVL trees
//
//  Created by Indira Bobburi on 11/23/17.
//  Copyright © 2017 sjsu. All rights reserved.
//
#include <iostream>
#include <vector>
#include <time.h>
#include <ctime>
#include <chrono>

#include "BinarySearchTree.h"
#include "AvlTree.h"
#include "BinaryTreeChecker.h"
#include "BinaryTreePrinter.h"

using namespace std;
using namespace std::chrono;

enum class TreeType
{
    BST, AVL
};

/**
 * Print the tree type.
 */
ostream& operator <<(ostream& out, const TreeType& type);

/**
 * Run the test with a binary search tree.
 */
void testBST();

/**
 * Run the test with an AVL tree.
 */
void testAVL();

/**
 * Build a binary search tree containing unique random integer data items.
 * @param tree the tree to make.
 * @param size is the size of input.
 */
void buildTree(BinarySearchTree& tree,
               int size);

/**
 * search a binary tree.
 * @param tree the tree to test.
 * @param size is the size of input.
 */
void searchTree(BinarySearchTree& tree,
                int size);

/**
 * print BST or AVL tree's probe and comparison counts and elapsed time.
 * @param tree whose statistics needs to be printed.
 */
void print_stats(BinarySearchTree& tree);

/**
 * Convert a number to a string with commas.
 * @param n the number.
 */
string commafy(long n);

/**
 * Dismantle a binary tree.
 * @param tree the tree to test.
 */
void dismantle_tree(BinarySearchTree& tree);

// Number of data items to test.
int VALUES[] = {10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000};

/**
 * Main.
 */
int main( )
{
    testBST();
    testAVL();
}

void testBST()
{
    cout << endl;
    cout << "**********************" << endl;
    cout << "* BINARY SEARCH TREE *" << endl;
    cout << "**********************" << endl;

    BinarySearchTree  tree;

    for (int n : VALUES)
    {
        cout << endl << "N = " << commafy(n) << endl << endl;
        cout << "INSERTION:" << endl;
        cout << setw(20) << "Probe count" << setw(20) << "Compare count"
             << setw(20) << "Elapsed time(ms)" << endl;

        tree.reset();
        buildTree(tree, n);

        cout << "SEARCH:" << endl;
        cout << setw(20) <<"Probe count" << setw(20) << "Compare count"
             << setw(20) << "Elapsed time(ms)" << endl;

        tree.reset();
        searchTree(tree, n);
        
        dismantle_tree(tree);
    }
}

void testAVL()
{
    cout << endl;
    cout << "************" << endl;
    cout << "* AVL TREE *" << endl;
    cout << "************" << endl;

    AvlTree tree;

    for (int n : VALUES)
    {
        cout << endl << "N = " << commafy(n) << endl << endl;
        cout << "INSERTION:" << endl;
        
        cout << setw(20) << "Probe count" << setw(20) << "Compare count"
             << setw(20) << "Elapsed time(ms)" << endl;

        tree.reset();
        buildTree(tree, n);

        cout << "SEARCH:" << endl;
        cout << setw(20) << "Probe count" << setw(20) << "Compare count"
             << setw(20) << "Elapsed time(ms)" << endl;

        tree.reset();
        searchTree(tree, n);
        
        dismantle_tree(tree);
    }
}

void buildTree(BinarySearchTree& tree, int input_size)
{
    srand(time(NULL));  // seed the random number generator

    for (int i = 1; i < input_size; i++)
    {
        int r = rand() % input_size;
        tree.insert(r);
    }

    print_stats(tree);
}

void searchTree(BinarySearchTree& tree, int input_size)
{
    srand(time(NULL));  // seed the random number generator

    for (int i = 1; i < input_size; i++)
    {
        int r = rand() % input_size;

        steady_clock::time_point start_time = steady_clock::now();

        tree.contains(r);

        steady_clock::time_point end_time = steady_clock::now();
        long msec = duration_cast<microseconds>(end_time - start_time).count();
        tree.increment_elapsed_time(msec);
    }

    print_stats(tree);
}

void print_stats(BinarySearchTree& tree)
{
    cout << setw(20) << commafy(tree.get_probe_count());
    cout << setw(20) << commafy(tree.get_comparison_count());
    cout << setw(20) << commafy(tree.get_elapsed_time());
    cout << endl << endl;
}


string commafy(long n)
{
    string str = to_string(n);
    int pos = str.length() - 3;

    while (pos > 0)
    {
        str.insert(pos, ",");
        pos -= 3;
    }

    return str;
}


void dismantle_tree(BinarySearchTree& tree)
{
    // Delete the root node each time through the loop.
    // Print the tree after each deletion.
    while (!tree.isEmpty())
    {
        BinaryNode *root = tree.getRoot();
        long data = root->data;

        tree.remove(data);
    }
}


