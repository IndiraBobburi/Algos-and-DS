#include <iostream>
#include <iomanip>
#include <mpir.h>
#include <stdlib.h>
#include <string.h>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

const int MAX_ITERATIONS = 7;
const int PLACES         = 1000000;        // desired decimal places
const int PRECISION      = PLACES + 1;  // +1 for the digit 3 before the decimal

const int BASE       = 10;  // base 10 numbers
const int BIT_COUNT  = 8;   // bits per machine word

const int BLOCK_SIZE = 10;                // print digits in blocks
const int LINE_SIZE  = 100;               // digits to print per line
const int LINE_COUNT = PLACES/LINE_SIZE;  // lines to print
const int GROUP_SIZE = 5;                 // line grouping size
duration<double> time_span_cube;

/**
 * Compute the cube root of an integer using Newton's method
 * @param x where to store the result.
 * @param a the number whose cube root to compute.
 * @param method = 0 uses netwon method, 1 used hailey's method
 */
void cube_root(mpf_t& x, const mpf_t a, int method = 0);

void print(const mpf_t& pi);

void cube_root(mpf_t& x, const mpf_t a, int method)
{
	steady_clock::time_point start = steady_clock::now();
	if(method == 0)
	{
		mpf_t two, three, xn, xn_sq, xn2;

		//initialize constants
		mpf_init(two);  mpf_set_str(two,  "2", BASE);
		mpf_init(three);  mpf_set_str(three,  "3", BASE);
		mpf_init(xn);
		mpf_init(xn_sq);
		mpf_init(xn2);

		//set initial value of x as a
		mpf_set(x, a);

		//loop till x is not same as previous value(xn)
		for(int i = 0; i < 100 && mpf_cmp(xn, x); i++)
		{
			mpf_set(xn, x);

			mpf_mul(xn_sq, xn, xn);
			mpf_mul(xn2, two, xn);
			mpf_div(x , a , xn_sq);
			mpf_add(x, x, xn2);
			mpf_div(x, x, three);
		}
	}
	else if(method == 1)
	{
		mpf_t num, den, x_cube, two, xn;
		mpf_init(num); mpf_init(den); mpf_init(x_cube); mpf_init(xn);

		mpf_init(two);  mpf_set_str(two,  "2", BASE);
		mpf_mul(num, two, a);

		mpf_set(x, a);

		//loop till x is not same as previous value(xn)
		for(int i = 0; i < MAX_ITERATIONS && mpf_cmp(xn, x) ; i++)
		{
			mpf_set(xn, x);
			mpf_pow_ui(x_cube, xn, 3);
			mpf_mul(num, two, a);
			mpf_add(num, x_cube, num);

			mpf_mul(den, two, x_cube);
			mpf_add(den, den, a);

			mpf_div(x, num, den);
			mpf_mul(x, x, xn);
		}
	}

    steady_clock::time_point end = steady_clock::now();
    time_span_cube += duration_cast<duration<double> >(end - start);
}

void compute_pi(mpf_t& pi)
{
    mpf_t a, r, s;
    mpf_init(a); mpf_init(r); mpf_init(s);

    //constants in iterations
    mpf_t one, two, three, nine, twenty_seven;
    mpf_init(one);  mpf_set_str(one,  "1", BASE);
    mpf_init(two);  mpf_set_str(two,  "2", BASE);
    mpf_init(three);  mpf_set_str(three,  "3", BASE);
    mpf_init(nine);  mpf_set_str(nine,  "9", BASE);
    mpf_init(twenty_seven);  mpf_set_str(twenty_seven,  "27", BASE);

    //initialize the iteration 0 values.
    mpf_div(a, one, three);
    mpf_sqrt(r, three);
    mpf_sub(r, r, one);
    mpf_div(r, r, two);

    mpf_t s_bef_cube; mpf_init(s_bef_cube);
    mpf_t u_bef_cube; mpf_init(u_bef_cube);
    mpf_t r_bef_cube; mpf_init(r_bef_cube);

    mpf_pow_ui(s_bef_cube, r, 3);
    mpf_sub(s_bef_cube, one, s_bef_cube);
    cube_root(s, s_bef_cube);

    mpf_t t, u, v, w, t_sq, tu, u_sq, threePow2n_1, wa, s_den;
    mpf_init(t); mpf_init(u); mpf_init(v); mpf_init(w);
    mpf_init(t_sq); mpf_init(tu); mpf_init(u_sq);
    mpf_init(threePow2n_1);
    mpf_init(wa); mpf_init(s_den);

    mpir_ui i;
    for(i=0; i< MAX_ITERATIONS; i++)
    {
    		steady_clock::time_point t1 = steady_clock::now();

        //compute t
        mpf_mul(t, two, r);
        mpf_add(t, one, t);

        //compute u
        mpf_mul(u_bef_cube, r, r);
        mpf_add(u_bef_cube, r, u_bef_cube);
        mpf_add(u_bef_cube, one, u_bef_cube);
        mpf_mul(u_bef_cube, r, u_bef_cube);
        mpf_mul(u_bef_cube, nine, u_bef_cube);
        cube_root(u, u_bef_cube);

        //compute v
        mpf_mul(t_sq, t, t);
        mpf_mul(u_sq, u, u);
        mpf_mul(tu, t, u);
        mpf_add(v, t_sq, tu);
        mpf_add(v, v, u_sq);

        //compute w
        mpf_mul(w, s, s);
        mpf_add(w, s, w);
        mpf_add(w, one, w);
        mpf_mul(w, twenty_seven, w);
        mpf_div(w, w, v);

        //compute 3 pow 2n-1
        if(i>0)
        {
        		mpf_pow_ui(threePow2n_1, three, 2*i-1);
        }
        else // 2n-1 = -1 when i = 0
        {
        		mpf_div(threePow2n_1, one, three);
        }

        mpf_mul(wa, w, a);
        mpf_sub(a, one, w);
        mpf_mul(a, threePow2n_1, a);
        mpf_add(a, wa, a);

        //compute s
        mpf_mul(s_den, two, u);
        mpf_add(s_den, t, s_den);
        mpf_mul(s_den, s_den, v);

        mpf_sub(s, one, r);
        mpf_pow_ui(s, s, 3);
        mpf_div(s, s, s_den);

        //compute r
        mpf_pow_ui(r_bef_cube, s, 3);
        mpf_sub(r_bef_cube, one, r_bef_cube);
        cube_root(r, r_bef_cube);

        steady_clock::time_point t2 = steady_clock::now();

        duration<double, std::milli> time_span = duration_cast<duration<double, std::milli> >(t2 - t1);

        cout << "Iteration "<< i+1  << " took "<< time_span.count() << " ms."<< endl;
    }
    mpf_div(pi, one, a);
}

void print(const mpf_t& pi)
{
    mp_exp_t exp;  // where the decimal resides

    // Convert the multiple-precision number x to a C string.
    char *str = NULL;
    char *s = mpf_get_str(str, &exp, BASE, PRECISION, pi);

    cout << endl;
    for(int i = 0; i< exp; i++)
    {
    		cout << s[i]; //prints 3
    }
    cout << ".";

    s = s+exp;

    char block[BLOCK_SIZE + 1];  // 1 extra for the ending \0

    // Print each line.
    for (int i = 1; i <= LINE_COUNT; i++)
    {
        // Print blocks of digits in each line.
        for (int j = 0; j < LINE_SIZE; j += BLOCK_SIZE)
        {
            strncpy(block, s+j, BLOCK_SIZE);
            block[BLOCK_SIZE] = '\0';
            cout << block << " ";
        }

        cout << endl << "  ";

        //blank line after each group.
        if (i%GROUP_SIZE == 0) cout << endl << "  ";

        s += LINE_SIZE;
    }

    free(str); //since this can be the allocated block as per documentation.
}


/**
  * The main.
  */
int main (void)
{
    mpf_set_default_prec(BIT_COUNT*PRECISION);

    mpf_t pi; mpf_init(pi);

    steady_clock::time_point start = steady_clock::now();

    compute_pi(pi);

    steady_clock::time_point end = steady_clock::now();
    duration<double> time_span = duration_cast<duration<double> >(end - start);
    cout << "Total time taken for computation: "<< time_span.count() << " seconds"<< endl;
    cout << "Percentage of cube root computations in the total time taken :";
    cout << time_span_cube.count()*100/time_span.count() << endl;

    print(pi);

    return 0;
}
