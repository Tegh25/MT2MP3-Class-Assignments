#include <stdio.h>
#include <assert.h>
#include <math.h>

/*
Author: Teghveer Ateliey
Date created: Oct 1, 2022
Last modified: Oct 1, 2022
Purpose: To find the sum of all numbers up to (and including) N that are multiples of either x or y as inputted into the function
*/

//function declaration
int multiples (int x, int y, int N);

//start of main function
int main () {
    
    return 0;
} //end of main function

//multiples function takes 3 integers as input, x and y used for finding multiples and N as the upper limit
//output of function is an int that is the sum of all multiples of x and y
int multiples (int x, int y, int N) {
    int sum = 0;
    //iterates from 1 to N, finds multiples of x and y and adds it to the variable sum
    for (int i = 1; i <= N; i++) { 
        if (i % x == 0 || i % y == 0) {
            sum += i;
        }
    }
    //returns sum as an int
    return sum;
} //end of multiples function