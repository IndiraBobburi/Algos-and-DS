//
//  DataRandom.hpp
//  SortingAlgorithms
//
//  Created by Indira Bobburi on 11/11/17.
//  Copyright © 2017 sjsu. All rights reserved.
//

#ifndef DATARANDOM_H_
#define DATARANDOM_H_

#include "DataGenerator.h"
#include "Element.h"

/**
 * Generator for unsorted random data.
 */
class DataRandom: public DataGenerator
{
public:
    DataRandom();
    virtual ~DataRandom();
    
    void generate_data(vector<Element>& data, int size);
    
private:
    vector<Element> random_data;
};

#endif /* DATARANDOM_H_ */

