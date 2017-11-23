//
//  main.cpp
//  Book_catalog_linked_lists
//
//  Created by Indira Bobburi on 10/11/17.
//  Copyright © 2017 sjsu. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include "Book.hpp"
#include "BookList.hpp"

using namespace std;

const string LOCATION = "/Users/indirabobburi/workspace/Book_catalog_linked_lists/Book_catalog_linked_lists/";
const string CATEGORIES_FILE_NAME = LOCATION + "categories.txt";

int main()
{
    ifstream input;
    input.open(CATEGORIES_FILE_NAME);
    if(input.fail())
    {
        cout << "Failed to open " << CATEGORIES_FILE_NAME << endl;
        return -1;
    }
    
    BookList mergedlist("MERGED");
    BookList authorsAM("AUTHORS A-M");
    BookList authorsNZ("AUTHORS N-Z");
    
    string command;
    input >> command;
    
    while(!input.fail())
    {
        ifstream file;
        string str = LOCATION + command + ".txt";
        
        file.open(str);
        
        if(file.fail())
        {
            cout << "Failed to open " << str << endl;
            return -1;
        }
        
        BookList l(command);
        while(!file.fail())
        {
            Book book;
            file >> book;
            
            if(file.fail()) break;
            
            l.insert(book);
        }
        l.print();
        mergedlist.merge(l);
        
        input >> command;
    }
    
    mergedlist.print();
    
    mergedlist.split("N", authorsAM, authorsNZ);
    
    authorsAM.print();
    authorsNZ.print();
    
    return 0;
}
