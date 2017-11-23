//
//  RomanNumeral.cpp
//  RomanNumerals
//
//  Created by Indira Bobburi on 9/22/17.
//  Copyright © 2017 sjsu. All rights reserved.
//
#include "RomanNumeral.h"

RomanNumeral::RomanNumeral() : roman(""), decimal(0)
{
}

RomanNumeral::RomanNumeral(int value)
{
    decimal = value;
    roman = to_roman(value);
}

RomanNumeral::RomanNumeral(string str)
{
    roman = str;
    decimal = to_decimal(roman);
}

string RomanNumeral::to_roman(int val)
{
    string str;
    
    //Fill Thousand's digit
    int x = val/1000;
    if(x > 0)
    {
        str.append(x, 'M');
    }
    val %= 1000;
    
    //Fill hundred's digit
    x = val/100;
    if(x>0)
    {
        switch(x)
        {
            case 9:
                str.append("CM");
                break;
            case 8:
                str.append("DCCC");
                break;
            case 7:
                str.append("DCC");
                break;
            case 6:
                str.append("DC");
                break;
            case 5:
                str.append("D");
                break;
            case 4:
                str.append("CD");
                break;
            case 3:
                str.append("CCC");
                break;
            case 2:
                str.append("CC");
                break;
            case 1:
                str.append("C");
                break;
        }
    }
    val %= 100;
   
    //Fill ten's digit
    x = val/10;
    if(x>0)
    {
        switch(x)
        {
            case 9:
                str.append("XC");
                break;
            case 8:
                str.append("LXXX");
                break;
            case 7:
                str.append("LXX");
                break;
            case 6:
                str.append("LX");
                break;
            case 5:
                str.append("L");
                break;
            case 4:
                str.append("XL");
                break;
            case 3:
                str.append("XXX");
                break;
            case 2:
                str.append("XX");
                break;
            case 1:
                str.append("X");
                break;
        }
    }
    val %= 10;
    
    //Fill units digit
    if(val > 0)
    {
        switch(val)
        {
            case 9:
                str.append("IX");
                break;
            case 8:
                str.append("VIII");
                break;
            case 7:
                str.append("VII");
                break;
            case 6:
                str.append("VI");
                break;
            case 5:
                str.append("V");
                break;
            case 4:
                str.append("IV");
                break;
            case 3:
                str.append("III");
                break;
            case 2:
                str.append("II");
                break;
            case 1:
                str.append("I");
                break;
        }
    }
    return str;
}

int RomanNumeral::get_single_digit_value(char c) const
{
	switch(c)
    {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
    }
    return 0; //invalid roman character
}

int RomanNumeral::to_decimal(string str)
{
    int val = 0, first =0, next =0;

    for(int i =0; i< str.length()-1; i++)
    {
        first = get_single_digit_value(str.at(i));
        next  = get_single_digit_value(str.at(i+1));
        
        if(first < next)
        {
            val += (next-first);
            i++;
        }
        else
        {
            val += first;
            if(i == str.length()-2)
            {
                val += next;
            }
        }
    }
    
    return val;
}

string RomanNumeral::getRomanValue() const
{
    return roman;
}

int RomanNumeral::getDecimalValue() const
{
    return decimal;
}

RomanNumeral operator+ (const RomanNumeral& r1, const RomanNumeral& r2)
{
    int value = r1.getDecimalValue() + r2.getDecimalValue();
    RomanNumeral result(value);
    return result;
}

RomanNumeral operator- (const RomanNumeral& r1, const RomanNumeral& r2)
{
    int value = r1.getDecimalValue() - r2.getDecimalValue();
    RomanNumeral result(value);
    return result;
}

RomanNumeral operator* (const RomanNumeral& r1, const RomanNumeral& r2)
{
    int value = r1.getDecimalValue() * r2.getDecimalValue();
    RomanNumeral result(value);
    return result;
}

RomanNumeral operator/ (const RomanNumeral& r1, const RomanNumeral& r2)
{
    int value = r1.getDecimalValue() / r2.getDecimalValue();
    RomanNumeral result(value);
    return result;
}

RomanNumeral& RomanNumeral::operator= (const RomanNumeral& r)
{
    this->decimal = r.decimal;
    this->roman = r.roman;
    return *this;
}

bool operator == (const RomanNumeral& r1, const RomanNumeral& r2)
{
     return (r1.getDecimalValue() == r2.getDecimalValue());
}

bool operator != (const RomanNumeral& r1, const RomanNumeral& r2)
{
    return (r1.getDecimalValue() != r2.getDecimalValue());
}

ostream& operator << (ostream& outs, const RomanNumeral& r)
{
    outs << "[" << r.getDecimalValue() << ":" << r.getRomanValue() << "]";
    return outs;
}

istream& operator >> (istream& in, RomanNumeral& r)
{
    string str;
    in >> str;
    
    if(!str.empty())
    {
        r.roman = str;
        r.decimal = r.to_decimal(str);
    }
    
    return in;
}
