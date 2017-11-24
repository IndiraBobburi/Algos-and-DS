//
//  QuickSortSuboptimal.cpp
//  SortingAlgorithms
//
//  Created by Indira Bobburi on 11/11/17.
//  Copyright © 2017 sjsu. All rights reserved.
//

#include "QuickSortSuboptimal.h"

/**
 * Constructor.
 * @param name the name of this algorithm.
 */
QuickSortSuboptimal::QuickSortSuboptimal(string name) : QuickSorter(name) {}

/**
 * Destructor.
 */
QuickSortSuboptimal::~QuickSortSuboptimal() {}

/**
 * Choose a bad pivot, always the leftmost element of the subrange.
 * @param left the left index of the subrange to sort.
 * @param right the right index of the subrange to sort.
 * @return the chosen pivot value.
 */
Element& QuickSortSuboptimal::choose_pivot_strategy(const int left, const int right)
{
    swap(left, right);
    return data[right];
}

