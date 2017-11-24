//
//  MergeSort.cpp
//  SortingAlgorithms
//
//  Created by Indira Bobburi on 11/11/17.
//  Copyright © 2017 sjsu. All rights reserved.
//

#include <string>
#include "MergeSort.h"

/**
 * Constructor.
 * @param name the name of the algorithm.
 */
MergeSort::MergeSort(string name) : ListSorter(name) {}

/**
 * Destructor.
 */
MergeSort::~MergeSort() {}

/**
 * Run the mergesort algorithm.
 * @throws an exception if an error occurred.
 */
void MergeSort::run_sort_algorithm()
throw (string)
{
    // Defensive programming: Make sure we end up
    // with the same size list after sorting.
    int size_before = data.get_size();
    
    mergesort(data);
    
    // Check sizes.
    int size_after = data.get_size();
    if (size_before != size_after)
    {
        string message = "***** Size mismatch: before " +
        to_string(size_before) + ", size after " +
        to_string(size_after);
        throw message;
    }
}

/**
 * The mergesort algorithm recursively splits and merges data lists.
 * @param list the list of data to sort.
 */
void MergeSort::mergesort(LinkedList& list)
{
    //if list contains 0 or 1 element
    if(list.get_head() == NULL || list.get_head()->getNext() == NULL)
    {
        return;
    }
    
    LinkedList list1;
    LinkedList list2;
    list.split(list1, list2);
    
    mergesort(list1);
    mergesort(list2);
    list.reset();
    merge(list, list1, list2);
}

/**
 * Merge two sublists back into a single list.
 * @param list the merged list.
 * @param sublist1 the first sublist.
 * @param sublist2 the second sublist.
 */
void MergeSort::merge(LinkedList& list,
                      LinkedList& sublist1, LinkedList& sublist2)
{
    while(sublist1.get_head() != nullptr || sublist2.get_head() != nullptr)
    {
        Node* node = nullptr;
       
        if(sublist1.get_head() == nullptr)
        {
            move_count++;
            list.concatenate(sublist2);
            return;
        }
        else if(sublist2.get_head() == nullptr)
        {
            move_count++;
            list.concatenate(sublist1);
            return;
        }
        else if(sublist1.get_head()->getData() < sublist2.get_head()->getData())
        {
            node = sublist1.remove_head();
        }
        else
        {
            node = sublist2.remove_head();
        }
        compare_count++;
        move_count++;
        list.add(node);
    }
}

/**
 * Clear the data.
 */
void MergeSort::clear() { data.clear(); }

