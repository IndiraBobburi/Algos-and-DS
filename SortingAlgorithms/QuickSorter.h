//
//  QuickSorter.hpp
//  SortingAlgorithms
//
//  Created by Indira Bobburi on 11/11/17.
//  Copyright © 2017 sjsu. All rights reserved.
//

#ifndef QUICKSORTER_H_
#define QUICKSORTER_H_

#include <string>
#include "VectorSorter.h"
#include "Element.h"

/**
 * The abstract base class of the quicksort algorithms.
 */
class QuickSorter: public VectorSorter
{
public:
    QuickSorter(string name);
    virtual ~QuickSorter();
    
    virtual void run_sort_algorithm() throw (string);
    
protected:
    virtual Element& choose_pivot_strategy(const int left, const int right) = 0;
    
private:
    void quicksort(const int left, const int right);
    int partition(const int left, const int right, const Element& pivot);
    Element& choose_pivot(const int left, const int right);
};

#endif /* QUICKSORTER_H_ */
