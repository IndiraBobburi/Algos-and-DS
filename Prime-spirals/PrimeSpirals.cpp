//
//  main.cpp
//  Assignment2-Week3-Spirals
//
//  Created by Indira Bobburi on 9/10/17.
//  Copyright © 2017 sjsu. All rights reserved.
//

#include <iostream>
#include <iomanip>

using namespace std;

const int MAX_SIZE  = 101;  // maximum size of the square matrix
const int MAX_START = 50;   // maximum starting number

/**
 Create a two dimenstional array and fill numbers in spiral form from start
 @param n is the size of the square matrix
 @param start is the starting number to be fill at the matrix center
 */
void do_spiral(const int n, const int start);

/**
 For a given square matrix, fills the values with the numbers in spiral form.
 @param a is two dimensional array/square matrix
 @param n is the size of the square matrix
 @param start is the starting number for the spiral
 */
void make_spiral(int **a, const int n, int start);

/**
 For a given square matrix, prints the values in that matrix
 @param a is two dimensional array/square matrix
 @param n is the size of the square matrix
 */
void print_spiral(int **a, const int n);

/**
 * The main: Generate and print spirals of various sizes.
 */
int main()
{
    do_spiral(1, 1);
    do_spiral(5, 1);
    do_spiral(9, 11);
    do_spiral(12, 13);
    do_spiral(15, 17);
    
    int** a = new int*[3];
    
    for(int i = 0; i < 3; i++)
        a[i] = new int[3];
}

void do_spiral(const int n, const int start)
{
    cout << "Spiral of size " << n << " starting at " << start << endl;
    if(n % 2 == 0) // Size of matrix is even
    {
        cout << "***** Error: Size " << n << " must be odd." << endl;
        cout << endl;
        return;
    }
    else if(n > MAX_SIZE)
    {
        cout << "***** Error: Size must be less than " << MAX_SIZE << endl;
        cout << endl;
        return;
    }
    else if( start > MAX_START)
    {
        cout << "***** Error: Start number must be less than " << MAX_START << endl;
        cout << endl;
        return;
    }
    
    int **a = new int*[n];
    for(int i = 0; i < n; i++)
    {
        a[i] = new int[n];
    }
    
    make_spiral(a, n, start);
    
    print_spiral(a, n);
    
    for(int i = 0; i< n; i++)
    {
        delete [] a[i];
    }
    delete [] a;
}

void make_spiral(int **a, const int n, int start)
{
    int center = n/2;
    int i = center, j = center;
    
    for(int dist_cent = 0; dist_cent < center+1; dist_cent++) //filling each squares
    {
        for(;( (i != center+dist_cent) || (j != center+dist_cent) );)
        {
            //going up
            for(; (i != center-dist_cent) && i > -1; i--, start++)
            {
                a[i][j] = start;
            }
            
            //going left
            for(; j != center-dist_cent && j > -1; j--, start++)
            {
                a[i][j] = start;
            }
            
            //going down
            for(; i != center+dist_cent && i< n; i++, start++)
            {
                a[i][j] = start;
            }
            
            //going right
            for(; j != center+dist_cent && j <n; j++, start++)
            {
                a[i][j] = start;
            }
        }
        
        //fill bottom-right corner from the center
        a[i][j] = start;
        start++;
        j++;
    }
}

void print_spiral(int **a, const int n)
{
    cout << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << setw(4) << a[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
