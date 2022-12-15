#include <stdio.h>
#include <assert.h>
#include <math.h>

/*
Author: Teghveer Ateliey
Date created: Oct 23, 2022
Last modified: Oct 23, 2022
Purpose: To compute the juggler sequence of a given integer greater than 0
*/

//function definition
int juggler(int n);

//start of main function
int main () {

    return 0;
} //end of main function

//start of juggler function which takes an integer greater than zero as input and outputs an integer
int juggler(int n) {
    //only continue the recursive algorithm if we have not yet reached 1
    if(n != 1) {
        if(n % 2 == 0) {
            //recalls the juggler function if n is even while adding 1 for the counter
            return juggler(floor(pow(n, 0.5))) + 1;
        } else {
            //recalls the juggler function if n is odd while adding 1 for the counter
            return juggler(floor(pow(n, 1.5))) + 1;
        }
    //ends the recursive algorithm when 1 is reached
    } else {
        return 0;
    }
} //end of juggler function