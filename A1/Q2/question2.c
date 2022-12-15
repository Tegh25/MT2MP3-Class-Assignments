#include <stdio.h>
#include <assert.h>
#include <math.h>

/*
Author: Teghveer Ateliey
Date created: Oct 1, 2022
Last modified: Oct 1, 2022
Purpose: To compute the floating point number which reproduces the formula (1^2 + ... + n^2)/(n^3) > 1/3 for any integer for n
*/

//function declaration
float onethird(int n);

//start of main function
int main () {
    
    return 0;
} //end of main function

//function takes integer n as a input and returns float after computing the formula
float onethird(int n) {
    //initializes numerator in formula
    float numerator = 0;
    //for loop iterates from 1 until int n and adds the square of each iteration to the numerator variable
    for (int i = 1; i <= n; i++) {
        numerator += (float) pow(i, 2);
    }
    //return numerator divided by int n to the power of 3
    return (float) numerator / pow(n, 3);
} //end of onethird function