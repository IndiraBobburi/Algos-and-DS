//
//  Book.cpp
//  Book_catalog_linked_lists
//
//  Created by Indira Bobburi on 10/11/17.
//  Copyright © 2017 sjsu. All rights reserved.
//

#include "Book.hpp"

using namespace std;

Book::Book()
{
    isbn = "";
    last = "";
    first = "";
    title = "";
}

Book::Book(string isbn, string last, string first, string title) :
isbn(isbn), last(last), first(first), title(title)
{
}

Book::~Book()
{
}

void Book::setIsbn(string val)
{
    isbn = val;
}

void Book::setLast(string val)
{
    last = val;
}

void Book::setFirst(string val)
{
    first = val;
}

void Book::setTitle(string val)
{
    title = val;
}

string Book::getIsbn() const
{
    return this->isbn;
}

string Book::getFirst() const
{
    return this->first;
}

string Book::getLast() const
{
    return this->last;
}

string Book::getTitle() const
{
    return this->title;
}

istream& operator >> (istream& in, Book& book)
{
    
    getline(in, book.isbn, ',');
    getline(in, book.last, ',');
    getline(in, book.first, ',');
    getline(in, book.title);
    
    return in;
}

ostream& operator << (ostream& out, Book& book)
{
    out << "Book{ISBN=" << book.isbn << ", ";
    out << "last=" << book.last << ", ";
    out << "first=" << book.first << ", ";
    out << "title=" << book.title << "}";
    
    return out;
}
