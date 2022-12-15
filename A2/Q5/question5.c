#include <stdio.h>
#include <assert.h>
#include <math.h>

/*
Author: Teghveer Ateliey
Date created: Oct 23, 2022
Last modified: Oct 23, 2022
Purpose: To find an item in a sorted array using binary search and return the number of examinations it took to find that item
*/

//function definition
int binsearch(int* x, int y, int size);

//start of main function
int main () {
    
    return 0;
} //end of main function

//start of binary search function, takes sorted array, integer y, and the size of the array all as integers for input, outputs number of examinations as integer
int binsearch(int* x, int y, int size) {
    //initializes variables for lowerbound, upperbound, and middle index for the binary search algorithm
    int lowerbound = 0;
    int upperbound = size-1;
    int midIndex = (upperbound + lowerbound)/2;
    //initializes counter to store number of examination steps done by the algorithm
    int exams = 1;
    //loop iterates until the inputted item is found by one of the bounds or the middle index
    while (y != x[lowerbound] && y != x[upperbound] && y != x[midIndex]) {
        //adjusts the bounds if the item is greater than the middle index
        if (y > x[midIndex]) {
            lowerbound = midIndex + 1;
            midIndex = (upperbound + lowerbound)/2;
        //adjusts the bounds if the item is lower than the middle index
        } else {
            upperbound = midIndex - 1;
            midIndex = (upperbound + lowerbound)/2;
        }
        //returns -1 if the middle index is equal to one of the bounds, meaning that the item could not be found
        if (midIndex == upperbound || midIndex == lowerbound) {
            return -1;
        }
        //adds to the exams counter for each iteration/examination
        exams++;
    }
    return exams;
} //end of binsearch function