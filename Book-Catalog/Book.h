//
//  Book.h
//  Book_catalog
//
//  Created by Indira Bobburi on 10/2/17.
//  Copyright © 2017 sjsu. All rights reserved.
//

#ifndef Book_h
#define Book_h

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
     * Book categories.
     */
    enum class Category { FICTION, HISTORY, TECHNICAL, NONE };
    
    /**
     * Default constructor.
     */
    Book();
    
    /**
     * Constructor.
     */
    Book(string isbn, string last, string first, string title, Category category);
    
    /**
     * Destructor.
     */
    ~Book();
    
    /**
     * sets the category from string
     */
    void setCategory(const string& str);
    
    /**
     * sets the isbn from string
     */
    void setIsbn(string val);
    
    /**
     * gets the category from string
     */
    string getCategory() const;
    
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
    
private:
    string isbn, last, first, title;
    Category category;
};

#endif /* Book_h */
