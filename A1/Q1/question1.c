#include <stdio.h>
#include <assert.h>
#include <math.h>

/*
Author: Teghveer Ateliey
Date created: Oct 1, 2022
Last modified: Oct 1, 2022
Purpose: To compute the number of minutes in the period of m minutes, h hours, and d days
*/

//function declaration
int minutes (int m, int h, int d);

// beginning of main function
int main () {
    
    return 0;
} // end of main function

// the minutes function takes the number of minutes, hours, and days as integers for input, returns the total number of minutes as an integer
int minutes (int m, int h, int d) {
    int minInDay = (d*24)*60;
    int minInHour = h*60;
    return m + minInDay + minInHour;
} // end of minutes fuction