//
//  Created by Indira Bobburi on 9/11/17.
//  Copyright © 2017 sjsu. All rights reserved.
//
#include <iostream>
#include <vector>

using namespace std;

const int MAX_START = 50;   // maximum starting number

/**
 Computes a vector with prime numbers starting from start
 @param n is the length of the prime vector required
 @param start is the strting value of the prime_vector
 @param prime_vector is the vector returned with primes and 0's.
 */
void create_prime_vector(const int n, const int start, vector<int>& prime_vector);

/**
 Create a spiral with the numbers starting from middle of matrix till end.
 If number is prime store # or else .
 @param n is the length of the square matrix
 @param primes is the prime vector computed to fill the spiral
 @param spiral is the vector of vectors which contains the final matrix
 */
void create_spiral(const int n, const vector<int>& primes, vector< vector<char> >& spiral);

/**
 Print spiral prints the spiral matrix created
 @param spiral is the vector of vectors which contains the matrix to be printed
 @param n is the length of the square matrix
 */
void print_spiral(const vector< vector<char> >& spiral, const int n);

/**
 Creates the spiral matrix and prints the matrix
 @param n is the length of the two dimensional square matrix
 @param start is the starting number from where the matrix starts
 */
void do_prime_spiral(const int n, const int start);

/**
 * The main: Generate and print prime spirals of various sizes.
 */
int main()
{
    do_prime_spiral(5, 1);
    do_prime_spiral(25, 11);
    do_prime_spiral(35, 0);
    do_prime_spiral(50, 31);
    do_prime_spiral(101, 41);
}

void create_prime_vector(const int n, const int start, vector<int>& prime_vector)
{
    //fill vector with values from start to n*n
    for(int i = 0; i < n; i++)
    {
        prime_vector.at(i) = start+i;
    }
    
    // replace composite numbers with 0
    for(int p = 2; p< start+prime_vector.size(); p++)
    {
        for(int j = 0; j < prime_vector.size(); j++)
        {
            if( (prime_vector.at(j) < 2) || (prime_vector.at(j) != p && prime_vector.at(j) % p == 0) )
            {
                prime_vector.at(j) = 0;
            }
        }
    }
}

void create_spiral(const int n, const vector<int>& primes, vector< vector<char> >& spiral)
{
    int center = n/2, p_index = 0;
    int i = center, j = center;
    
    for(int dist_cent = 0; dist_cent < center+1; dist_cent++) //filling each squares
    {
        for(;( (i != center+dist_cent) || (j != center+dist_cent) );)
        {
            //going up
            for(; (i != center-dist_cent) && i > -1; i--, p_index++)
            {
                spiral[i][j] = primes[p_index] ? '#' : '.';
            }
            
            //going left
            for(; j != center-dist_cent && j > -1; j--, p_index++)
            {
                spiral[i][j] = primes[p_index] ? '#' : '.';
            }
            
            //going down
            for(; i != center+dist_cent && i< n; i++, p_index++)
            {
                spiral[i][j] = primes[p_index] ? '#' : '.';
            }
            
            //going right
            for(; j != center+dist_cent && j <n; j++, p_index++)
            {
                spiral[i][j] = primes[p_index] ? '#' : '.';
            }
        }
        
        //fill bottom-right corner from the center
        spiral[i][j] = primes[p_index] ? '#' : '.';
        p_index++;
        j++;
    }
}

void print_spiral(const vector< vector<char> >& spiral, const int n)
{
    cout << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << spiral[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void do_prime_spiral(const int n, const int start)
{
    cout << "Prime spiral of size " << n << " starting at " << start << endl;
    
    if(start < 1 || start > MAX_START)
    {
        cout << "***** Error: Starting value " << start << " < 1 or > " << MAX_START << endl;
        cout << endl;
        return;
    }
    
    if(n % 2 == 0) // Size of matrix is even
    {
        cout << "***** Error: Size " << n << " must be odd." << endl;
        cout << endl;
        return;
    }
    
    vector<int> prime(n*n);
    vector< vector<char> > spiral(n, vector<char>(n));
    
    create_prime_vector(n*n, start, prime);
    
    create_spiral(n, prime, spiral);
    
    print_spiral(spiral, n);
}
