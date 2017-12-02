//
//  DataGenerator.hpp
//  SortingAlgorithms
//
//  Created by Indira Bobburi on 11/11/17.
//  Copyright © 2017 sjsu. All rights reserved.
//

#ifndef DATAGENERATOR_H_
#define DATAGENERATOR_H_

#include <string>
#include <vector>

using namespace std;

class DataGenerator
{
public:
    DataGenerator();
    virtual ~DataGenerator();
    
    void generate_data(int size);
    
private:
    vector<int> random_data;
};

#endif /* DATAGENERATOR_H_ */

