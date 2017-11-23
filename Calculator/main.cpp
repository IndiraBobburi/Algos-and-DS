//
//  main.cpp
//  Calculator
//
//  Created by Indira Bobburi on 10/30/17.
//  Copyright © 2017 sjsu. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include "Calculator.h"
using namespace std;

const string INPUT_FILE_NAME = "input.txt";
bool INTERACTIVE = true; //make this flag to true for interactive calculator session.

/**
 * test program that shows the ability of the calculator
 * @param in is the input file stream to read the commands from
 */
void test(ifstream& in);

int main()
{
    if(INTERACTIVE)
    {
        cout << "Expression? ";
        char c;
        Calculator calc;
        while((cin >> c) && c != '.')
        {
            string str = "";
            while(c != '=')
            {
                str.push_back(c);
                cin >> c;
            }
            
            calc.set_string(str);
            calc.compute();
            
            cout << endl;
            cout << "Expression? ";
        }
        cout << endl << "Done!" << endl;
    }
    else
    {
        ifstream in;
        in.open(INPUT_FILE_NAME);
        if (in.fail())
        {
            cout << "Input file open failed: " << INPUT_FILE_NAME;
            return -1;
        }
        test(in);
    }
    return 0;
}

void test(ifstream& in)
{
    string command;
    cout << "Expression? ";
    getline(in, command);
    Calculator calc;
    while(!in.fail())
    {
        cout << command << endl;
        if(command == ".")
        {
            cout << endl << "Done!" << endl;
            break;
        }
        else
        {
            std::size_t pos = command.find("=");
            if(pos != string::npos)
            {
                string str = command.substr(0, pos-1);
                
                str.erase(remove(str.begin(), str.end(), ' '), str.end());
                
                calc.set_string(str);
                calc.compute();
            }
            
            cout << endl << "Expression? ";
            getline(in, command);
        }
    }
}
