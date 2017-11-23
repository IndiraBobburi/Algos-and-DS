//
//  BookList.hpp
//  Book_catalog_linked_lists
//
//  Created by Indira Bobburi on 10/11/17.
//  Copyright © 2017 sjsu. All rights reserved.
//

#ifndef BookList_hpp
#define BookList_hpp

#include "BookNode.hpp"

class BookList
{
public:
    /**
     * Constructor.
     * @param name the name of this list.
     */
    BookList(const string name);
 
    /* Insert a new book node into the list sorted by isbn of book
     * @param book is the book that need to be inserted
     * @return the BookNode pointing to the inserted book
     */
    BookNode* insert(Book book);
    
    /* Merge another booklist into this in a sorted order
     * @param booklist to be merged
     */
    void merge(BookList booklist);
    
    /*Print the books in the BookList*/
    void print();
    
    /* Split the booklist into two booklists based on the last names
     * @param split_at is the string used to split into lists
     * @param first is the list with last names before split_at
     * @param second is the list with last names after split_at
     */
    void split(string split_at, BookList& first, BookList& second);
private:
    BookNode* head;   // head of the list of book nodes
    BookNode* tail;   // tail of the list of book nodes
    string name;      // name of this book list
};

#endif /* BookList_hpp */
