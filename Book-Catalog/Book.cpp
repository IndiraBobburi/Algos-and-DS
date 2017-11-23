//
//  Book.cpp
//  Book_catalog
//
//  Created by Indira Bobburi on 10/2/17.
//  Copyright © 2017 sjsu. All rights reserved.
//

#include "Book.h"

using namespace std;

Book::Book()
{
    isbn = "";
    last = "";
    first = "";
    title = "";
    category = Category::NONE;
}

Book::Book(string isbn, string last, string first, string title, Category category) :
isbn(isbn), last(last), first(first), title(title), category(category)
{
    
}

Book::~Book()
{
    
}

void Book::setCategory(const string& str)
{
    if(str == "FICTION" || str == "fiction") category = Category::FICTION;
    if(str == "HISTORY" || str == "history") category = Category::HISTORY;
    if(str == "TECHNICAL" || str == "technical") category = Category::TECHNICAL;
    if(str == "NONE" || str == "none") category = Category::NONE;
}

void Book::setIsbn(string val)
{
    isbn = val;
}

string Book::getCategory() const
{
    if(category == Category::FICTION) return "fiction";
    else if(category == Category::HISTORY) return "history";
    else if(category == Category::TECHNICAL) return "technical";
    else if(category == Category::NONE) return "none";
    return "";
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
    string str;

    getline(in, str, ',');
    book.isbn = str.substr(1, str.size()-1); //To remove the space in the front
    
    getline(in, book.last, ',');
    getline(in, book.first, ',');
    getline(in, book.title, ',');
    getline(in, str);
    book.setCategory(str);

    return in;
}

ostream& operator << (ostream& out, Book& book)
{
    out << "Book{ISBN=" << book.isbn << ", ";
    out << "last=" << book.last << ", ";
    out << "first=" << book.first << ", ";
    out << "title=" << book.title << ", ";
    out << "category=" << book.getCategory() << "}";
    
    return out;
}