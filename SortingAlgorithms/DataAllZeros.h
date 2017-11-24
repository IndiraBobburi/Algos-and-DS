//
//  DataAllZeros.hpp
//  SortingAlgorithms
//
//  Created by Indira Bobburi on 11/11/17.
//  Copyright © 2017 sjsu. All rights reserved.
//

#ifndef DATAALLZEROS_H_
#define DATAALLZEROS_H_

#include "DataGenerator.h"
#include "Element.h"

/**
 * Generator for data that is all zeros.
 */
class DataAllZeros: public DataGenerator
{
public:
    DataAllZeros();
    virtual ~DataAllZeros();
    
    virtual void generate_data(vector<Element>& data, int size);
};

#endif /* DATAALLZEROS_H_ */
