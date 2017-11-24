//
//  DataGenerator.cpp
//  SortingAlgorithms
//
//  Created by Indira Bobburi on 11/11/17.
//  Copyright © 2017 sjsu. All rights reserved.
//

#include <string>
#include <vector>
#include "DataGenerator.h"

using namespace std;

/**
 * Constructor.
 * @param name the name of this generator.
 */
DataGenerator::DataGenerator(string name) : name(name) {}

/**
 * Destructor.
 */
DataGenerator:: ~DataGenerator() {}

/**
 * Getter
 * @return the name of this generator.
 */
string DataGenerator::get_name() { return name; }

