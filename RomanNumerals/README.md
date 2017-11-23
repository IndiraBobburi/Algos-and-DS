RomanNumerals  

Reading, writing and arithmetic operations on Roman Numerals by overloading operators  

Design and implement a C++ class RomanNumeral that reads, writes, and performs arithmetic operations on Roman numerals. This class must have:  

• Private member variables string roman and int decimal that store the Roman numeral string (such as "MCMLXVIII") and its integer value (such as 1968).  

• Private member functions to_roman and to_decimal that convert between the string and integer values of a RomanNumeral object and thereby set the values of member variables roman and decimal.  

• Public constructors, one that takes an integer parameter and another that takes a string parameter.  

o One constructor creates a RomanNumeral object from an integer value.  

o The other creates a RomanNumeral object from a string value.  

• Public getter functions that return an object’s string and integer values.  

• Overloaded arithmetic operators + - * and / that enable direct arithmetic operations with Roman numerals.  
 
o Roman numerals do integer division (drop the fraction part of a quotient).  

• Overloaded equality operators == and != that enable direct comparisons of RomanNumeral objects.  

• Overloaded I/O stream operators >> and <<  

o Input a Roman numeral value as a string, such as MCMLXVIII  

o Output a Roman numeral value in the form [integer value:roman string] such as [1968:MCMLXVIII]   
