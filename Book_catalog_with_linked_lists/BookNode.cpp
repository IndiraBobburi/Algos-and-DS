//
//  BookNode.cpp
//  Book_catalog_linked_lists
//
//  Created by Indira Bobburi on 10/11/17.
//  Copyright © 2017 sjsu. All rights reserved.
//

#include "BookNode.hpp"
#include "Book.hpp"

BookNode::BookNode(Book book)
{
    data = book;
    next = nullptr;
}

Book BookNode::getData() const
{
    return data;
}

BookNode* BookNode::getNext() const
{
    return next;
}

void BookNode::setData(Book book)
{
    data = book;
}

void BookNode::setNext(BookNode* link)
{
    next = link;
}
