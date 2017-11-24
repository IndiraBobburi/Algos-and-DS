//
//  ShellSortSubOptimal.cpp
//  SortingAlgorithms
//
//  Created by Indira Bobburi on 11/11/17.
//  Copyright © 2017 sjsu. All rights reserved.
//

#include "ShellSortSubOptimal.h"

/**
 * Constructor.
 * @param name the name of this algorithm.
 */
ShellSortSuboptimal::ShellSortSuboptimal(string name) : VectorSorter(name) {}

/**
 * Destructor.
 */
ShellSortSuboptimal::~ShellSortSuboptimal() {}

/**
 * Run the suboptimal shellsort algorithm.
 * @throws an exception if an error occurred.
 */
void ShellSortSuboptimal::run_sort_algorithm() throw (string)
{
    for(int h = data.size()/2; h > 0; h = h/2)
    {
        for(int i = h; i < data.size(); i++)
        {
            Element temp = data[i];
            for(int j = i; j >= h; j -= h)
            {
                compare_count++;
                if(data[j-h] > temp)
                {
                    data[j] = data[j-h];
                    move_count++;
                }
                else
                {
                    data[j] = temp;
                    move_count++;
                    break;
                }
            }
        }
    }
}

