//
//  InsertionSort.cpp
//  SortingAlgorithms
//
//  Created by Indira Bobburi on 11/11/17.
//  Copyright © 2017 sjsu. All rights reserved.
//

#include "InsertionSort.h"

/**
 * Constructor.
 * @param name the name of the algorithm.
 */
InsertionSort::InsertionSort(string name) : VectorSorter(name) {}

/**
 * Destructor.
 */
InsertionSort::~InsertionSort() {}

/**
 * Run the insertion sort algorithm.
 * @throws an exception if an error occurred.
 */
void InsertionSort::run_sort_algorithm() throw (string)
{
    for(int i = 1; i < size; i++)
    {
        Element ele = data[i];
        //insert data[i] at appropriate position
        for(int j = i-1; j >= 0; j--)
        {
            compare_count++;
            if(data[j] > ele)
            {
                data[j+1] = data[j];
                move_count++;
            }
            else
            {
                if(i !=  j+1)
                {
                    data[j+1] = ele;
                    move_count++;
                }
                break;
            }
        }
    }
}

