#include <stdio.h>
#include <assert.h>
#include <math.h>

/*
Author: Teghveer Ateliey
Date created: Oct 1, 2022
Last modified: Oct 1, 2022
Purpose: to calculate the factorial of a non-negative integer in two different ways, using while loops and do while loops
*/

//function declarations
int FactorialWhile (int n);
int FactorialDoWhile (int n);

//start of main function
int main () {
    
    return 0;
} //end of main function

//this function takes integer n as local variable input, calculates its factorial, and returns the answer as an integer
int FactorialWhile (int n) {
    //initializing product variable for computation and for returning
    int product = 1;
    //while loop iterates down from n until it reachs 1, multplies each iteration to product
    while (n > 1) {
        product *= n;
        n--;
    }
    return product;
} //end of FactorialWhile function

//this function takes integer n as local variable input, calculates its factorial, and returns the answer as an integer
int FactorialDoWhile (int n) {
    //initializing product variable for computation and for returning    
    int product = 1;
    //if statement only allows factorial to be calculated if input is a positive integer
    if (n > 0) {
        //do while loop iterates down from n until it reachs 1, multplies each iteration to product
        do {
            product *= n;
            n--;
        } while (n > 1); //condition for do while loop
    //if statement returns 1 if the input is not a positive integer
    } else {
        return 1;
    }
    //returns factorial calculation if input is a positive integer
    return product;
} //end of FactorialDoWhile function