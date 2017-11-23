//
//  RomanNumeral.h
//  RomanNumerals
//
//  Created by Indira Bobburi on 9/22/17.
//  Copyright © 2017 sjsu. All rights reserved.
//

#ifndef ROMANNUMERAL_H_
#define ROMANNUMERAL_H_

#include <string>
#include <iostream>

using namespace std;

class RomanNumeral
{
public:
    /**
     * Default constructor.
     */
    RomanNumeral();
    
    /**
     * Constructor by giving int value
     */
    RomanNumeral(int);
    
    /**
     * Constructor by giving string value
     */
    RomanNumeral(string);
    
    /**
     * Getter function to return roman value as string
     */
    string getRomanValue() const;

    /**
     * Getter function to return decimal value as int
     */
    int getDecimalValue() const;
    
    /**
     * Overloaded arithematic operators for the class object.
     */
    friend RomanNumeral operator+ (const RomanNumeral& r1, const RomanNumeral& r2);
    friend RomanNumeral operator- (const RomanNumeral& r1, const RomanNumeral& r2);
    friend RomanNumeral operator* (const RomanNumeral& r1, const RomanNumeral& r2);
    friend RomanNumeral operator/ (const RomanNumeral& r1, const RomanNumeral& r2);
    
    /**
     * Overloaded unary operators for the class object.
     */
    RomanNumeral& operator= (const RomanNumeral& r);
    
    /**
     * Overloaded comparison operators for the class object.
     */
    friend bool operator == (const RomanNumeral& r1, const RomanNumeral& r2);
    friend bool operator != (const RomanNumeral& r1, const RomanNumeral& r2);
    
    /**
     * Overloaded stream operators for the class object.
     */
    friend ostream& operator << (ostream& outs, const RomanNumeral& r);
    friend istream& operator >> (istream& outs, RomanNumeral& r);
   
private:
    string to_roman(int val);
    int to_decimal(string str);
    
    int get_single_digit_value(char c) const;
    
    string roman;
    int decimal;
};

#endif /* ROMANNUMERAL_H_ */
