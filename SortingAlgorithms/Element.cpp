//
//  Element.cpp
//  SortingAlgorithms
//
//  Created by Indira Bobburi on 11/11/17.
//  Copyright © 2017 sjsu. All rights reserved.
//

#include <iostream>
#include "Element.h"

using namespace std;

long Element::copy_count = 0;
long Element::dest_count = 0;

/**
 * Default constructor.
 */
Element::Element() : value(0) {}

/**
 * Constructor.
 * @param val the element's value.
 */
Element::Element(long val) : value(val) {}

/**
 * Copy constructor.
 * @param other the other element to be copied.
 */
Element::Element(const Element& other)
{
    value = other.value;
    copy_count++;
}

/**
 * Destructor.
 */
Element::~Element()
{
    dest_count++;
}

/**
 * Getter.
 * @return the value.
 */
long Element::get_value() const { return value; }

/**
 * Operator overloading >
 */
bool operator > (const Element& first, const Element& second)
{
    return (first.value > second.value);
}

/**
 * Operator overloading <=
 */
bool operator <= (const Element& first, const Element& second)
{
    return (first.value <= second.value);
}

/**
 * Operator overloading >=
 */
bool operator >= (const Element& first, const Element& second)
{
    return (first.value >= second.value);
}

/**
 * Operator overloading <
 */
bool operator < (const Element& first, const Element& second)
{
    return (first.value < second.value);
}

/**
 * Operator overloading <<
 */
ostream& operator << (ostream& outs, const Element& element)
{
    outs << element.value;
    return outs;
}

long Element::get_copy_count()
{
    return copy_count;
}

long Element::get_destructor_count()
{
    return dest_count;
}

void Element::reset()
{
    copy_count = 0;
    dest_count = 0;
}
