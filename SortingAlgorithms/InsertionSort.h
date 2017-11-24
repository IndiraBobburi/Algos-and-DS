//
//  InsertionSort.h
//  SortingAlgorithms
//
//  Created by Indira Bobburi on 11/11/17.
//  Copyright © 2017 sjsu. All rights reserved.
//

#ifndef INSERTIONSORT_H_
#define INSERTIONSORT_H_

#include "VectorSorter.h"

/**
 * The class that implements the insertion sort algorithm
 * for a vector of data.
 */
class InsertionSort: public VectorSorter
{
public:
    InsertionSort(string name);
    virtual ~InsertionSort();
    
    virtual void run_sort_algorithm() throw (string);
};

#endif /* INSERTIONSORT_H_ */
