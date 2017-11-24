//
//  QuickSortOptimal.cpp
//  SortingAlgorithms
//
//  Created by Indira Bobburi on 11/11/17.
//  Copyright © 2017 sjsu. All rights reserved.
//

#include "QuickSortoptimal.h"

/**
 * Constructor.
 * @param name the name of this algorithm.
 */
QuickSortOptimal::QuickSortOptimal(string name) : QuickSorter(name) {}

/**
 * Destructor.
 */
QuickSortOptimal::~QuickSortOptimal() {}

/**
 * Choose a good pivot, the median-of-three:
 * The middle value of the leftmost, rightmost, and center elements.
 * This is a compromise since the most optimal pivot would be the
 * median of the subrange, but that's too expensive to compute.
 * @param left the left index of the subrange to sort.
 * @param right the right index of the subrange to sort.
 * @return the chosen pivot value.
 */
Element& QuickSortOptimal::choose_pivot_strategy(const int left, const int right)
{
    int mid = (left+right)/2;
    
    Element ele;
    
    if(data[mid] > data[right])
        swap(mid, right);
    if(data[left] > data[right])
        swap(mid, left);
    if(data[mid] > data[left])
        swap(mid, left);
    
    compare_count += 3;
        
    swap(mid, right);
    return data[right];
}

