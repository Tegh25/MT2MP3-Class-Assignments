#include <stdio.h>
#include <assert.h>
#include <math.h>

/*
Author: Teghveer Ateliey
Date created: Oct 1, 2022
Last modified: Oct 1, 2022
Purpose: To compute if the number provided is a leap year or not
*/

//function declaration
int LeapYearCheck (int n);

//start of main function
int main () {
    
    return 0;
} //end of main function

//function takes in a year as an integer input, returns integers 1 (true) or 0 (false) to confirm if the input is a leap year or not
int LeapYearCheck (int n) {
    //n is a leap year if it is divisible by 4 and not 100 OR if it is divisble by 100 and 400
    if ((n % 4 == 0 && n % 100 != 0) || (n % 100 == 0 && n % 400 == 0)) {
        return 1; //return 1 for true
    } else {
        return 0; //return 0 for false
    }
} //end of LeapYearCheck function