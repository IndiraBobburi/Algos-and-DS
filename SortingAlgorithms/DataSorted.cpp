//
//  DataSorted.cpp
//  SortingAlgorithms
//
//  Created by Indira Bobburi on 11/11/17.
//  Copyright © 2017 sjsu. All rights reserved.
//

#include "DataSorted.h"

/**
 * Default constructor.
 */
DataSorted::DataSorted() : DataGenerator("Already sorted") {}

/**
 * Destructor.
 */
DataSorted:: ~DataSorted() {}

/**
 * Generate already sorted values (low to high) to fill a vector.
 * @param data the data vector to fill.
 */
void DataSorted::generate_data(vector<Element>& data, int size)
{
    for (long i = 0; i < size; i++) data.push_back(Element(i));
}
