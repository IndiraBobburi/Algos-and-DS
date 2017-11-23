A concordance table is an alphabetical list of words from a document and their frequencies. Your input data will be a text file of the U.S. constitution and its amendments:  

http://www.cs.sjsu.edu/~mak/CMPE180-92/assignments/11/USConstitution.txt  

Program reads each word of the text. If the word is not already in the concordance, enter the word with an initial count of 1 into both the vector and map versions. If the word already exists in the concordance, increment the word’s count by one in the vector and in the map. The words in the concordance must be unique, and, of course, both versions must end up with the same words and counts. Word comparisons are not be case-sensitive. Numbers or punctuation marks are not included.  

Program will keep track of how much time it takes to enter all the words into the vector version of the concordance, and how much time it takes to enter all the words into the map version of the concordance. For each word, elapsed time is computed only of the operation of either entering a new word into the concordance or incrementing the count of an existing word. Time to read the word from the input text file is not included. 
Total time for the vector vs. the total time for the map is computed in microseconds (µsec).  

After building the two versions of the concordance, the total time it takes to do 100,000 random word searches in each version is computed.
Binary search is used since vector-based concordance is sorted.  
