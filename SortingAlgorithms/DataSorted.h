//
//  DataSorted.hpp
//  SortingAlgorithms
//
//  Created by Indira Bobburi on 11/11/17.
//  Copyright © 2017 sjsu. All rights reserved.
//

#ifndef DATASORTED_H_
#define DATASORTED_H_

#include "DataGenerator.h"
#include "Element.h"

/**
 * Generator for already sorted data.
 */
class DataSorted: public DataGenerator
{
public:
    DataSorted();
    virtual ~DataSorted();
    
    virtual void generate_data(vector<Element>& data, int size);
};

#endif /* DATASORTED_H_ */

