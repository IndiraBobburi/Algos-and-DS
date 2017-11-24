//
//  Element.hpp
//  SortingAlgorithms
//
//  Created by Indira Bobburi on 11/11/17.
//  Copyright © 2017 sjsu. All rights reserved.
//

#ifndef DATA_H_
#define DATA_H_

#include <iostream>
using namespace std;

/**
 * The class for the data elements that will be sorted.
 */
class Element
{
public:
    Element();
    Element(long val);
    Element(const Element& other);
    virtual ~Element();
    
    long get_value() const;

    friend bool operator > (const Element& first, const Element& second);
    
    friend bool operator < (const Element& first, const Element& second);
    
    friend bool operator <= (const Element& first, const Element& second);
    
    friend bool operator >= (const Element& first, const Element& second);
    
    friend ostream& operator << (ostream& outs, const Element& element);
    
    static long get_copy_count();
    static long get_destructor_count();
    
    static void reset();
    
    friend class Sorter;
    
private:
    long value;
    static long copy_count;
    static long dest_count;
};

#endif /* DATA_H_ */
