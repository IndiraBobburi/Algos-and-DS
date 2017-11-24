//
//  ShellSortOptimal.hpp
//  SortingAlgorithms
//
//  Created by Indira Bobburi on 11/11/17.
//  Copyright © 2017 sjsu. All rights reserved.
//

#ifndef SHELLSORTOPTIMAL_H_
#define SHELLSORTOPTIMAL_H_

#include "VectorSorter.h"

/**
 * The class that implements the optimal shellsort algorithm
 * for a vector of data, where the diminishing increment is
 * calculated according to Don Knuth.
 */
class ShellSortOptimal: public VectorSorter
{
public:
    ShellSortOptimal(string name);
    virtual ~ShellSortOptimal();
    
    virtual void run_sort_algorithm() throw (string);
};

#endif /* SHELLSORTOPTIMAL_H_ */
