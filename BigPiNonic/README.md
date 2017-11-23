# BigPiNonic
Printing million digits of Pi using Borwein's algorithm

This program will use the Nonic Convergence algorithm published at
https://en.wikipedia.org/wiki/Borwein's_algorithm 

Each iteration increases the number of correct digits by a factor of 9.

This program also uses The Multiple Precision Integers and Rationals (MPIR) library. 
Downloaded and built from http://mpir.org/downloads.html.

Things you will get to know:
1. How to use MPIR library.
2. Implementation of Borwein's algorithm's Nonic Convergence.
3. Optimizations made to print 1000 digits first and then to proceed to print 1000000 digits
