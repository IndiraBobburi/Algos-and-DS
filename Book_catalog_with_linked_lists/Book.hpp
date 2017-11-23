//
//  Book.hpp
//  Book_catalog_linked_lists
//
//  Created by Indira Bobburi on 10/11/17.
//  Copyright © 2017 sjsu. All rights reserved.
//

#ifndef Book_hpp
#define Book_hpp

#include <string>
#include <iostream>
using namespace std;

/**
 * The Book class.
 */
class Book
{
public:
    
    /**
     * Default constructor.
     */
    Book();
    
    /**
     * Constructor.
     */
    Book(string isbn, string last, string first, string title);
    
    /**
     * Destructor.
     */
    ~Book();

    /**
     * sets the isbn from string
     */
    void setIsbn(string val);
    
    /**
     * sets the last from string
     */
    void setLast(string val);
    
    /**
     * sets the first from string
     */
    void setFirst(string val);
    
    /**
     * sets the first from string
     */
    void setTitle(string val);
    
    /**
     * return isbn of the book
     */
    string getIsbn() const;
    
    /**
     * return first name of author of the book
     */
    string getFirst() const;
    
    /**
     * return last name of author of the book
     */
    string getLast() const;
    
    /**
     * return title of the book
     */
    string getTitle() const;
    
    friend istream& operator >> (istream& in, Book& book);
    
    friend ostream& operator << (ostream& out, Book& book);
    
    friend class BookList;
    
private:
    string isbn, last, first, title;
};

#endif /* Book_hpp */
