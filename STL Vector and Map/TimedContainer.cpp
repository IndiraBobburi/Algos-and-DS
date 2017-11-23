//
//  TimedContainer.cpp
//  STL Vector and Map
//
//  Created by Indira Bobburi on 11/7/17.
//  Copyright © 2017 sjsu. All rights reserved.
//

#include "TimedContainer.h"
#include "Word.h"
#include <chrono>

using namespace std::chrono;

TimedContainer::TimedContainer(){}

TimedContainer::~TimedContainer(){}

void TimedContainer::increment_elapsed_time(long val)
{
    elapsed_time += val;
}

Word *TimedContainer::timed_insert(const string text)
{
    // Start the timer.
    steady_clock::time_point start_time = steady_clock::now();
    
    // Do the insertion.
    Word *word = insert(text);
    
    // Compute the elapsed time in microseconds
    // and increment the total elapsed time.
    steady_clock::time_point end_time = steady_clock::now();
    increment_elapsed_time(duration_cast<microseconds>(end_time - start_time).count());
    
    return word;
}

Word *TimedContainer::timed_search(const string text)
{
    // Start the timer.
    steady_clock::time_point start_time = steady_clock::now();
    
    // Do the search.
    Word *word = search(text);
    
    // Compute the elapsed time in microseconds
    // and increment the total elapsed time.
    steady_clock::time_point end_time = steady_clock::now();
    long elapsed = duration_cast<microseconds>(end_time - start_time).count();
    increment_elapsed_time(elapsed);
    
    return word;
}

long TimedContainer::get_elapsed_time() const
{
    return elapsed_time;
}

void TimedContainer::reset_elapsed_time()
{
    elapsed_time = 0;
}

