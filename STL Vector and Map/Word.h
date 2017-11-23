//
//  Word.hpp
//  STL Vector and Map
//
//  Created by Indira Bobburi on 11/7/17.
//  Copyright © 2017 sjsu. All rights reserved.
//

#ifndef WORD_H_
#define WORD_H_

#include <string>
using namespace std;

/**
 * A word entry consisting of a word text and a frequency count
 * for a concordance.
 */
class Word
{
public:
    /**
     * Default constructor.
     */
    Word();
    
    /**
     * Constructor.
     * Create a word entry with the given text. Initialize the count to 1.
     * @param text the text of the word.
     */
    Word(string text);
    
    /**
     * Destructor.
     */
    virtual ~Word();
    
    /**
     * To get the count of the word in the document
     * @return the count of the word repeated
     */
    int get_count() const;
    
    /**
     * Increment the count by 1
     */
    void increment_count();
    
    /**
     * getter to get the string in the Word
     * @return the string in the word
     */
    string get_text() const;
    
    /**
     * Overloading operator for the != binary operation
     * @param other is the word that is compared
     * @return true if other is not the same as this or else false
     */
    bool operator !=(const Word& other);
    
    /**
     * Compares the text in this word to the text using std::string.compare
     * @param val is the comparing string
     * return 0 if the val is same as text, <0 if text is less than val and >0 if the val is greater than text
     */
    int compare_text(const string val);
    
private:
    string text;
    int count;
};

#endif /* WORD_H_ */

