//
//  BookApp.cpp
//  Book_catalog
//
//  Created by Indira Bobburi on 10/2/17.
//  Copyright © 2017 sjsu. All rights reserved.
//

#include "Book.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Status codes.
enum class StatusCode {OK, DUPLICATE, NOT_FOUND, INVALID_COMMAND};

/**
 * Binary search the index where to insert/delete the book with given isbn
 * @param catalog is the vector of book records.
 * @param isbn is the isbn of the Book object that needs to be inserted/deleted.
 * @param status is DUPLICATE for adding a new book that already exist, NOT_FOUND for book not found for deleting
 * @return index where to insert the book, if book with isbn already exists return -1
 */
int search(vector<Book>& catalog, const string& isbn, StatusCode& status);

/**
 * Inserts book in a sorted order. Prints the message where it is inserted.
 * @param catalog is the vector of book records.
 * @param book is the Book object that needs to be inserted.
 */
void insertBook(vector<Book>& catalog, Book& book);

/**
 * Deletes the book from the catalog.
 * @param catalog is the vector of book records.
 * @param isbn is the ISBN of the book object that needs to be deleted.
 */
void deleteBook(vector<Book>& catalog, const string& isbn);

/**
 * Prints the books present in the catalog which matches the search criteria
 * @param catalog is the vector of book records.
 * @param attribute is the parameter that we are searching. Null string for empty criteria
 * @param value is the parameter value that matches the search criteria.
 */
void printCatalog(vector<Book>& catalog, string attribute, const string& value);

const string INPUT_FILE_NAME = "commands.in";

int search(vector<Book>& catalog, const string& isbn, StatusCode& status)
{
    int low = 0, high = catalog.size(), mid = 0;
    
    while (low <= high)
    {
        mid = (low + high)/2;
        
        if(mid < catalog.size())
        {
            if(isbn == catalog.at(mid).getIsbn())
            {
                status = StatusCode::DUPLICATE;
                return mid;
            }
            else if(isbn < catalog.at(mid).getIsbn())
            {
                high = mid;
            }
            else
            {
                low = mid+1;
            }
        }
        
        if(low == high)
        {
            status = StatusCode::NOT_FOUND;
            return low;
        }
    }
    
    return -1;
}

void insertBook(vector<Book>& catalog, Book& book)
{
    StatusCode status;
    int index = search(catalog, book.getIsbn(), status);
    cout << "Inserted at index " << index << ": " << book << endl;
    
    if(status == StatusCode::DUPLICATE)
    {
        cout << "*** Duplicate ISDN ***" << endl;
    }
    else
    {
        catalog.insert(catalog.begin()+index, book);
    }

    return;
}

void deleteBook(vector<Book>& catalog, const string& isbn)
{
    StatusCode status;
    int index = search(catalog, isbn, status);
    
    cout << "Removed ";
    if(index == -1 || status == StatusCode::NOT_FOUND)
    {
        Book book;
        book.setIsbn(isbn);
        cout << book << endl;
        cout << "*** Book not found ***" << endl;
    }
    else
    {
        cout << catalog.at(index) << endl;
        catalog.erase(catalog.begin()+index);
    }
}

void printCatalog(vector<Book>& catalog, string attribute, const string& value)
{
    vector<Book>::iterator it;
    int printed = 0;
    
    for(it = catalog.begin(); it != catalog.end(); it++)
    {
        if(attribute == "")
        {
            if(!printed)
            {
                cout << "All books in the catalog:" << endl;
                printed = 1;
            }
            cout << *it << endl;
        }
        else if(attribute == "author" && (it->getLast() == value || it->getFirst() == value))
        {
            {
            if(!printed)
            {
                cout << "Books by author " << value << ":" << endl;
                printed = 1;
            }
            cout << *it << endl;
            }
        }
        else if(attribute == "category" && (it->getCategory() == value))
        {
            if(!printed)
            {
                cout << "Books in category " << value << ":" << endl;
                printed = 1;
            }
            cout << *it << endl;
        }
        else if(attribute == "isbn")
        {
            if(!printed)
            {
                cout << "Book with ISBN " << value << ":" << endl;
                printed = 1;
            }
            if(it->getIsbn() == value)
            {
                cout << *it << endl;
                return; /*since isbn is unique*/
            }
        }
    }
}

/**
 * The main. Open the command input file and loop to process commands.
 */
int main()
{
    // Open the input file.
    ifstream input;
    input.open(INPUT_FILE_NAME);
    if (input.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }
    
    vector<Book> catalog;  // book catalog
    //catalog.reserve(10);
    char command;
    input >> command;  // read the first command
    
    /**
     * Loop to read commands until the end of file.
     */
    while (!input.fail())
    {
        cout << endl << command << " ";
        if(command == '+')
        {
            Book book;
            input >> book;
            
            //add to the vector
            insertBook(catalog, book);
        }
        else if(command == '?')
        {
            string attribute, value;
            
            string searchInput;
            getline(input, searchInput);
            
            if(searchInput == "")
            {
                attribute = "";
                value = "";
            }
            else
            {
                std::size_t pos = searchInput.find("=");
                attribute = searchInput.substr(1, pos-1); //zero index is the space
                value = searchInput.substr(pos+1);
            }
            
            printCatalog(catalog, attribute, value);
        }
        else if(command == '-')
        {
            string isbn;
            input >> isbn;
            
            deleteBook(catalog, isbn);
        }
        else
        {
            string str;
            getline(input, str);
            cout << "*** Invalid command ***" << endl;
        }
        
        input >> command;
    }
    
    return 0;
}