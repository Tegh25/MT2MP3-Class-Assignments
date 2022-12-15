#include <stdio.h>
#include <assert.h>
#include <math.h>

/*
Author: Teghveer Ateliey
Date created: Oct 23, 2022
Last modified: Oct 23, 2022
Purpose: To sort an array using bubblesort and return the number of swap operations performed while sorting
*/

//function initialization
int bubblesort(int* x, int size);

//start of main function
int main () {
    
    return 0;
} //end of main function

//start of bubblesort function, taking an integer array and its size as an int for inputs and outputting the number of swap operations as an integer 
int bubblesort(int* x, int size) {
    //intializing variables for counting swap operations and for swapping the indexes of arrays
    int swaps = 0;
    int temp;
    //iterates from size-1 to 0, this is so that we dont repeat the sorting of indexes that have been sorted already
    for (int i = (size-1); i >= 0; i--) {
        //iterates from 0 to i-1, using i as the "size" for the indexes that havent been sorted
        for (int j = 0; j <= (i-1); j++) {
            //if an index is greater than the one after it, swap both indexes using the temp variable
            if (x[j] > x[j+1]) {
                temp = x[j+1];
                x[j+1] = x[j];
                x[j] = temp;
                //increases the counter for number of swap operations
                swaps++;
            }
        }
    }
    return swaps;
} //end of bubblesort function