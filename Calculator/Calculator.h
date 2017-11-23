//
//  Calculator.h
//  Calculator
//
//  Created by Indira Bobburi on 10/31/17.
//  Copyright © 2017 sjsu. All rights reserved.
//

#ifndef Calculator_h
#define Calculator_h

#include <string>

using namespace std;
/**
 * Calculator class which uses BODMAS priority for calculating.
 */
class Calculator
{
public:
    Calculator();
    /*compute the string in Calculator and returns the output*/
    void compute();
    
    /**
     * Sets the string for the calculator to compute
     * @param value is the string to be set for computation
     **/
    void set_string(const string value);
    
private:
    /**
     * Checks whether the string contains only number
     * @param s is the string to be checked
     * @return the true if the string is a number, otherwise false.
     **/
    bool is_number(const string& s);
    
    /**
     * Checks if the string is a valid string which can be computed in this calculator
     * @param s is the string which is checked
     * @return -1 if the string is valid, otherwise returns the first position at which the string failed.
     **/
    int is_valid_string(const string& s);
    
    /**
     * Computes the expression and throw when an error is encountered
     * @param str is the input expression
     **/
    void expression(string &str) throw (string);
    
    /**
     * Computes the term and throw when an error is encountered
     * @param str is the input term
     **/
    void term(string &str) throw (string);
    
    /**
     * Computes the factor and throw when an error is encountered
     * @param str is the input factor
     **/
    void factor(string &str) throw (string);
    
    /**
     * Computes the power
     * @param base is the base of the exponential
     * @param pow is the exponent
     **/
    string power(string base, string pow);
    
    /**
     * local str to be computed
     **/
    string str;
};

#endif /* Calculator_h */
