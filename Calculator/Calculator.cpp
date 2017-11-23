//
//  Calculator.cpp
//  Calculator
//
//  Created by Indira Bobburi on 10/31/17.
//  Copyright © 2017 sjsu. All rights reserved.
//

#include "Calculator.h"
#include <iostream>
#include <math.h>

Calculator::Calculator()
{
    
}

bool Calculator::is_number(const string& s)
{
    string::const_iterator it;
    for(it = s.begin(); it != s.end(); it++)
    {
        if(*it  == '-' && it == s.begin())
            continue;
        if((*it < '0' || *it > '9') && (*it != '.'))
            return false;
    }
    return true;
}

int Calculator::is_valid_string(const string& s)
{
    string::const_iterator it;
    for(it = s.begin(); it != s.end(); it++)
    {
        if((*it < '0' || *it > '9') && (*it != '.')
           && (*it != '*') && (*it != '/')
           && (*it != '+') && (*it != '-')
           && (*it != '(') && (*it != ')')
           && (*it != 'E') && (*it != 'e'))
            return (it - s.begin());
    }
    return -1;
}

void Calculator::compute()
{
    try
    {
        factor(str);
    }
    catch (string& msg)
    {
        cout << "***** " << msg << endl;
    }
    
    if(is_number(str))
        cout << stod(str) << endl;
}

void Calculator::set_string(const string value)
{
    str = value;
}

void Calculator::factor(string &str) throw (string)
{
    if(is_number(str)) // string a integer
        return;
    
    int pos = is_valid_string(str);
    if(pos != -1)
    {
        if(pos > 0)
            cout <<  str.substr(0, pos) << endl;
        throw( string("Unexpected ") + string(1, str[pos]));
    }
            
    size_t bracket_open = str.find_last_of("(");
    size_t bracket_close = str.find_first_of(")");
    if(bracket_open != string::npos && bracket_close == string::npos)
    {
        throw( string("Missing )") );
    }
            
    if(bracket_open == string::npos && bracket_close != string::npos)
    {
        cout << str.substr(0, bracket_close) << endl;
        throw( string("Unexpected )") );
    }
            
    if(bracket_open == string::npos && bracket_close == string::npos)
    {
        expression(str);
    }
    else
    {
        string exp;
        exp = str.substr(bracket_open+1, bracket_close-bracket_open-1);
        expression(exp);
        str.replace(bracket_open, bracket_close-bracket_open+1, exp);
    }
    term(str);
}
            
void Calculator::term(string &str) throw (string)
{
    if(str.find("(") != string::npos && str.find(")") != string::npos)
        factor(str);
    
    //find * operator
    size_t mul_pos = str.find("*");
    if(mul_pos != string::npos)
    {
        string term1 = str.substr(0, mul_pos);
        if(!is_number(term1))
            factor(term1);
        
        string term2 = str.substr(mul_pos+1);
        if(!is_number(term2))
            factor(term2);
        
        if(is_number(term1) && is_number(term2))
        {
            double val = stod(term1) * stod(term2);
            str = to_string(val);
        }
    }
    
    //find / operator
    size_t div_pos = str.find("/");
    if(div_pos != string::npos)
    {
        string term1 = str.substr(0, div_pos);
        if(!is_number(term1))
            factor(term1);
        
        string term2 = str.substr(div_pos+1);
        if(!is_number(term2))
            factor(term2);
        
        if(is_number(term1) && is_number(term2))
        {
            if(stod(term2) == 0)
            {
                throw (string("Division by zero"));
            }
            double val = stod(term1) / stod(term2);
            str = to_string(val);
        }
    }
    
    if((mul_pos == string::npos) && (div_pos == string::npos))
    {
        factor(str);
    }
}
            
string Calculator::power(string base, string power)
{
    double b = (base == "e") ? 10 : stod(base);
    double p = stod(power);
    double val = pow(b, p);
    return to_string(val);
}
            
void Calculator::expression(string &str) throw (string)
{
    if(str.find("(") != string::npos && str.find(")") != string::npos)
        factor(str);
    
    //find + operator
    size_t add_pos = str.find("+");
    
    if(add_pos != string::npos)
    {
        if(str.at(add_pos-1) == 'E' || str.at(add_pos-1) == 'e')
        {
            string::iterator it;
            int count =0;
            for(it = str.begin()+add_pos+1; it != str.end(); it++,count++)
            {
                if(*it < '0' || *it > '9')
                    break;
            }
            string e_power = power("e", str.substr(add_pos+1, count));
            if(add_pos-1 > 0)
            {
                e_power.insert(e_power.begin(), '*');
            }
            str.replace(add_pos-1, count+2, e_power);
            expression(str);
            return;
        }
        
        string term1 = str.substr(0, add_pos);
        if(!is_number(term1))
            term(term1);
        
        string term2 = str.substr(add_pos+1);
        if(!is_number(term2))
            term(term2);
        
        if(is_number(term1) && is_number(term2))
        {
            double val = stod(term1) + stod(term2);
            str = to_string(val);
        }
    }
    
    //find - operator
    size_t sub_pos = str.find("-");
    if(sub_pos != string::npos)
    {
        if(str.at(sub_pos-1) == 'E' || str.at(sub_pos-1) == 'e')
        {
            string::iterator it;
            int count =0;
            for(it = str.begin()+sub_pos+1; it != str.end(); it++,count++)
            {
                if(*it < '0' || *it > '9')
                    break;
            }
            string e_power = power("e", str.substr(sub_pos, count+1));
            if(sub_pos-1 > 0)
            {
                e_power.insert(e_power.begin(), '*');
            }
            str.replace(sub_pos-1, count+2, e_power);
            expression(str);
            return;
        }
        
        string term1 = str.substr(0, sub_pos);
        if(sub_pos == 0)
            return;
        if(!is_number(term1))
            term(term1);
        
        string term2 = str.substr(sub_pos+1);
        if(!is_number(term2))
            term(term2);
        
        if(is_number(term1) && is_number(term2))
        {
            double val = stod(term1) - stod(term2);
            str = to_string(val);
        }
    }
    
    if((add_pos == string::npos) && (sub_pos == string::npos))
    {
        term(str);
    }
}
