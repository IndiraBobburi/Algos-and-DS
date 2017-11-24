Sorting algorithms include Selection, Insertion, Shellsort(optimal and suboptimal), quicksort(optimal and suboptimal), mergesort 

Comparing the algorithms  
To compare the performances of the sorting algorithms, these statistics for each algorithm at each data size are kept track of:  
• The total number of copy constructor calls for the data elements being sorted.  
• The total number of destructor calls of the data elements.  
• The total number of times a data element is moved. Count one move whenever an element moves from one part of the vector or linked list to another. Whenever two elements are swapped, that counts as two moves.  
• The total number of compares of two data elements. Count one compare whenever a data element is compared against another element.  
• The amount of time (in milliseconds) required to do the sort. 

All these algorithms are compared with Unsorted random data, already sorted data, reverse sorted data, data with all zeroes. 
