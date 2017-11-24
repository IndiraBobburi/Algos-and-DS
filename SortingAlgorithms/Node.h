//
//  Node.hpp
//  SortingAlgorithms
//
//  Created by Indira Bobburi on 11/11/17.
//  Copyright © 2017 sjsu. All rights reserved.
//

#ifndef NODE_H_
#define NODE_H_

#include "Element.h"

/**
 * A node of the linked list for mergesort.
 */
class Node
{
public:
    Node(Element);
    
    Element& getData();
    Node* getNext() const;
    
    friend class LinkedList;
    friend class ListSorter;
private:
    Element element;
    Node* next;
};

#endif /* NODE_H_ */

