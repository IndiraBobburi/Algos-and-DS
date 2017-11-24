//
//  QuickSortOptimal.hpp
//  SortingAlgorithms
//
//  Created by Indira Bobburi on 11/11/17.
//  Copyright © 2017 sjsu. All rights reserved.
//

#ifndef QUICKSORTOPTIMAL_H_
#define QUICKSORTOPTIMAL_H_

#include "QuickSorter.h"

/**
 * The class that implements the optimal quicksort algorithm
 * for a vector of data by using a good pivot strategy.
 */
class QuickSortOptimal: public QuickSorter
{
public:
    QuickSortOptimal(string name);
    virtual ~QuickSortOptimal();
    
private:
    virtual Element& choose_pivot_strategy(const int left, const int right);
};

#endif /* QUICKSORTOPTIMAL_H_ */
