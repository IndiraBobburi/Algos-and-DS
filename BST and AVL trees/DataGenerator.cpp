//
//  DataGenerator.cpp
//  SortingAlgorithms
//
//  Created by Indira Bobburi on 11/11/17.
//  Copyright © 2017 sjsu. All rights reserved.
//


#include <stdlib.h>
#include <time.h>
#include "DataGenerator.h"

/**
 * Default constructor.
 */
DataGenerator::DataGenerator() {}

/**
 * Destructor.
 */
DataGenerator::~DataGenerator() {}

/**
 * Generate random values to fill a data vector.
 * Reuse previously generated data if possible.
 * @param data the target data vector.
 * @param size the number of random data elements to generate.
 */
void DataGenerator::generate_data(int size)
{
    random_data.clear();
    srand(time(NULL));  // seed the random number generator
    
    for (int i = 0; i < size; i++)
    {
        int r = rand()%size;
        random_data.push_back(r);
    }
}


