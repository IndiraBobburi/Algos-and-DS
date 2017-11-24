//
//  ShellSortSubOptimal.hpp
//  SortingAlgorithms
//
//  Created by Indira Bobburi on 11/11/17.
//  Copyright © 2017 sjsu. All rights reserved.
//

#ifndef SHELLSORTSUBOPTIMAL_H_
#define SHELLSORTSUBOPTIMAL_H_

#include "VectorSorter.h"

/**
 * The class that implements the suboptimal Shellsort algorithm
 * for a vector of data, where the diminishing increment is halved
 * for each pass.
 */
class ShellSortSuboptimal: public VectorSorter
{
public:
    ShellSortSuboptimal(string name);
    virtual ~ShellSortSuboptimal();
    
    virtual void run_sort_algorithm() throw (string);
};

#endif /* SHELLSORTSUBOPTIMAL_H_ */
