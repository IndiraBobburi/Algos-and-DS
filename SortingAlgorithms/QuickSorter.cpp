//
//  QuickSorter.cpp
//  SortingAlgorithms
//
//  Created by Indira Bobburi on 11/11/17.
//  Copyright © 2017 sjsu. All rights reserved.
//

#include <iostream>
#include "QuickSorter.h"
using namespace std;

/**
 * Constructor.
 * @param name the name of this algorithm.
 */
QuickSorter::QuickSorter(string name) : VectorSorter(name) {}

/**
 * Destructor.
 */
QuickSorter::~QuickSorter() {}

/**
 * Run the quicksort algorithm.
 * @throws an exception if an error occurred.
 */
void QuickSorter::run_sort_algorithm() throw (string)
{
    quicksort(0, size-1);
}

/**
 * The quicksort algorithm recursively sorts data subranges.
 * @param left the left index of the subrange to sort.
 * @param right the right index of the subrange to sort.
 */
void QuickSorter::quicksort(const int left, const int right)
{
    if(left < right)
    {
        int p_index = partition(left, right, choose_pivot(left, right));
        
        quicksort(left, p_index-1);
        quicksort(p_index+1, right);
    }
}

/**
 * Choose the pivot according to a pivot strategy.
 * The chosen pivot will be moved temporarily to the right end.
 * @param left the left index of the partition to sort.
 * @param right the right index of the partition to sort.
 * @return the pivot value.
 */
Element& QuickSorter::choose_pivot(const int left, const int right)
{
    return choose_pivot_strategy(left, right);
}

/**
 * Partition the subrange by moving data elements < pivot to the left
 * and data elements > pivot to the right.
 * @param left the left index of the partition to sort.
 * @param right the right index of the partition to sort.
 * @param pivot the pivot value.
 */
int QuickSorter::partition(const int left, const int right, const Element& pivot)
{
   /* int i = left;
    int j = right-1;
    
    while(i<j)
    {
        while(i<j && data[i] <= pivot)
        {
            compare_count++;
            i++;
        }
        while(i<j && data[j] > pivot)
        {
            compare_count++;
            j--;
        }
        
        //if(i<j && (data[i] >= pivot) && (data[j] < pivot))
        if(i<j)
            swap(i, j);
        else
            break;
    }
   
    if(data[j] > data[right])
    {
        compare_count++;
        swap(j, right);
    }
    return j;*/
    
    int i = (left-1);  // Index of smaller element
    
    for (int j = left; j <= right - 1; j++)
    {
        // If current element is smaller than or equal to pivot
        if (data[j] <= pivot)
        {
            compare_count++;
            i++;    // increment index of smaller element
            swap(i, j);
        }
    }
    swap(i+1, right);
    return (i + 1);
}

