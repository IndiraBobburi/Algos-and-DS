//
//  DataReverseSorted.hpp
//  SortingAlgorithms
//
//  Created by Indira Bobburi on 11/11/17.
//  Copyright © 2017 sjsu. All rights reserved.
//

#ifndef DATAREVERSESORTED_H_
#define DATAREVERSESORTED_H_

#include "DataGenerator.h"
#include "Element.h"

/**
 * Generator for reverse-sorted data.
 */
class DataReverseSorted: public DataGenerator
{
public:
    DataReverseSorted();
    virtual ~DataReverseSorted();
    
    virtual void generate_data(vector<Element>& data, int size);
};

#endif /* DATAREVERSESORTED_H_ */
