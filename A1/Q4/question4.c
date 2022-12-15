#include <stdio.h>
#include <assert.h>
#include <math.h>

/*
Author: Teghveer Ateliey
Date created: Oct 1, 2022
Last modified: Oct 1, 2022
Purpose: To compute the floating point number which represents the compound interest rate for a bank over a number of years
*/

//function declaration
float compoundInterest (float p, int a, int n);

//start of main function
int main () {
    
    return 0;
} //end of main function

//compoundInt takes a float, int, and int as input to be used in the formula a*(1+p)^n, then returns the output as float rounded to 2 decimal places (ideally)
float compoundInterest (float p, int a, int n) {
    //computes formula with given values
    float compInterest = a*pow(1 + p, n);
    //rounds computation to 2 decimal places
    float rounded = (roundf(compInterest * 100.00))/100.00;
    return rounded;
} //end of compoundInterest function