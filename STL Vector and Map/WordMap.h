//
//  WordMap.hpp
//  STL Vector and Map
//
//  Created by Indira Bobburi on 11/7/17.
//  Copyright © 2017 sjsu. All rights reserved.
//

#ifndef WORDMAP_H_
#define WORDMAP_H_

#include <map>
#include "TimedContainer.h"
#include "Word.h"

using namespace std;

typedef map<string, Word> wordMap;

/**
 * A map implementation for the concordance that inherits a timer.
 **/
class WordMap : public TimedContainer
{
public:
    /**
     * Default constructor.
     */
    WordMap();
    
    /**
     * Destructor.
     */
    virtual ~WordMap();
    
    /**
     * Insert a new word into the map,
     * or increment the count of an existing word.
     * @param text the text of the word to insert or increment.
     * @return a pointer to the word entry.
     */
    Word *insert(const string text);
    
    /**
     * Search the map for a word entry with the given text.
     * @param text the text of the word to find.
     * @return a pointer to the word entry if found, nullptr if not.
     */
    Word *search(const string text);
    
    /**
     * function to return the size of the map
     * @return the size of the map
     */
    const long get_size();
    
    /**
     * function to return the size of the map
     * @return the map data of the class
     */
    wordMap& get_data();
    
private:
    wordMap data;
};

#endif /* WORDMAP_H_ */

