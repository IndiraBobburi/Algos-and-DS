//
//  BookList.cpp
//  Book_catalog_linked_lists
//
//  Created by Indira Bobburi on 10/11/17.
//  Copyright © 2017 sjsu. All rights reserved.
//

#include "BookList.hpp"

BookList::BookList(const string name) : name(name), head(nullptr), tail(nullptr)
{
}

BookNode* BookList::insert(Book book)
{
    BookNode* node = new BookNode(book);
    if(head == nullptr)
    {
        head = node;
        tail = node;
    }
    else if(book.isbn < head->data.isbn)
    {
        node->next = head;
        head = node;
    }
    else
    {
        BookNode *p = head->next;
        BookNode *prev = head;
        
        while(p != nullptr && book.isbn >= p->data.isbn)
        {
            prev = p;
            p = p->next;
        }
        
        if(book.isbn != prev->data.isbn )
        {
            prev->next = node;
            node->next = p;
            
            if(p == nullptr)
            {
                tail = prev;
            }
        }
    }
    
    return node;
}

void BookList::print()
{
    cout << "Book list: " << name << endl;
    cout << endl;
    int count = 0;
    BookNode* p = head;
    while(p != nullptr)
    {
        cout << p->data << endl;
        p = p->next;
        count++;
    }
    cout << "(" << count << " books)" << endl;
    cout << endl;
}

void BookList::merge(BookList booklist)
{
    if(head == nullptr)
    {
        head = booklist.head;
        tail = booklist.tail;
        return;
    }
    
    if(booklist.head->data.isbn > tail->data.isbn) /*the new list comes after the current list*/
    {
        tail->next = booklist.head;
        tail = booklist.tail;
        return;
    }
    
    if (booklist.tail->data.isbn < head->data.isbn) /*the new list comes before the current node*/
    {
        booklist.tail->next = head;
        head = booklist.head;
        return;
    }

    BookNode* node = booklist.head;
    while(node != nullptr)
    {
        insert(node->data);
        node = node->next;
    }
}

void BookList::split(string split_at, BookList& first, BookList& second)
{
    BookNode* node = head;
    while(node != nullptr)
    {
        if(node->data.getLast() < split_at)
        {
            if(first.head == nullptr)
            {
                first.head = node;
                first.tail = node;
            }
            else
            {
                first.tail->next = node;
                first.tail = node;
            }
        }
        else
        {
            if(second.head == nullptr)
            {
                second.head = node;
                second.tail = node;
            }
            else
            {
                second.tail->next = node;
                second.tail = node;
            }
        }
        
        node = node->next;
    }
    
    first.tail->next = nullptr;
    second.tail->next = nullptr;
}
