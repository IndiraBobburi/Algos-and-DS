//
//  BookNode.hpp
//  Book_catalog_linked_lists
//
//  Created by Indira Bobburi on 10/11/17.
//  Copyright © 2017 sjsu. All rights reserved.
//

#ifndef BookNode_hpp
#define BookNode_hpp

#include <stdio.h>
#include "Book.hpp"

class BookNode
{
public:
    //Constructors to initialize a node
    BookNode(Book book);
    
    //Retrive book for this node
    Book getData() const;
    
    //Retrive next node in the list
    BookNode* getNext() const;
    
    //Use to modify the value stored in the list
    void setData(Book book);
    
    //Use to change the reference of book node
    void setNext(BookNode* link);
    
    friend class BookList;
    
private:
    Book data;
    BookNode* next;
};

typedef BookNode* BookNodePtr;
#endif /* BookNode_hpp */
