//
//  ShellSortOptimal.cpp
//  SortingAlgorithms
//
//  Created by Indira Bobburi on 11/11/17.
//  Copyright © 2017 sjsu. All rights reserved.
//

#include "ShellSortOptimal.h"
#include <math.h>

/**
 * Constructor.
 * @param name the name of this algorithm.
 */
ShellSortOptimal::ShellSortOptimal(string name) :VectorSorter(name) {}

/**
 * Destructor.
 */
ShellSortOptimal::~ShellSortOptimal() {}

/**
 * Run the optimal shellsort algorithm.
 * According to Don Knuth:
 * h = 3*i + 1 for i = 0, 1, 2, ... used in reverse.
 * @throws an exception if an error occurred.
 */
void ShellSortOptimal::run_sort_algorithm() throw (string)
{
    //donald knuth values are 1, 4, 13, .. (3^k - 1)/2;
    //find max k first
    int h = 0;
    int k = 1;
    while(h < size)
    {
        h = (pow(3, k) - 1)/2;
        k++;
    }
    
    for(int l = k-1 ; l >= 1; l--)
    {
        h = (pow(3, l) - 1)/2;
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

