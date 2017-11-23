//
//  main.cpp
//  Assignement-Week3
//
//  Created by Indira Bobburi on 9/10/17.
//  Copyright © 2017 sjsu. All rights reserved.
//
#include <iostream>
#include <iomanip>

using namespace std;

const int MAX_NUMBER = 1000;  // maximum possible prime number
const int ROW_SIZE   = 20;    // row size for printing

/**
 Computes prime numbers in the given input array starting from 2.
 @param input an array of the integers
 @param n size of the input
 */
void compute_primes(int input[], const int n);

/**
 Computes print prime numbers marked in the given input array.
 @param input an array of the integers
 @param n size of the input
 */
void print_primes(int input[], const int n);

/**
 * The main: Compute and print the prime numbers up to MAX_NUMBER.
 */
int main()
{
    int input[MAX_NUMBER-2]; // 0 and 1 not included corresponding values from [2-999]
    
    for(int i = 0 ; i < MAX_NUMBER-2; i++)
    {
        /* 0 means composite ; 1 means prime.
         Initially, mark all as primes.
         */
        input[i] = i+2;
    }
    
    compute_primes(input, MAX_NUMBER-2);
    
    print_primes(input, MAX_NUMBER-2);
    
    return 0;
}

void compute_primes(int input[], const int n)
{
    int present_prime;
    
    //input[] index represents the numbers with offset 2
    //the value at the index 0 or 1 at an index represents composite or prime number
    for(int i = 0; i< n; i++)
    {
        if(input[i] != 0)
        {
            present_prime = i+2;
            for(int j = i+1; j < n;j++)
            {
                if((j+2) % present_prime == 0)
                {
                    input[j] = 0;
                }
            }
        }
    }
}

/**
 Computes print prime numbers marked in the given input array.
 @param input an array of the integers
 @param n size of the input
 */
void print_primes(int input[], const int n)
{
    for(int i =0, count =0; i< n; i++)
    {
        if(input[i] != 0)
        {
            count++;
            cout <<  setw(4) << i+2;
            if(count%ROW_SIZE == 0)
            {
                cout << endl;
            }
        }
    }
    cout << endl;
    cout << endl << "Done!" << endl;
}
