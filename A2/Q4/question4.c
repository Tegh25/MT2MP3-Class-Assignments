#include <stdio.h>
#include <assert.h>
#include <math.h>

/*
Author: Teghveer Ateliey
Date created: Oct 23, 2022
Last modified: Oct 23, 2022
Purpose: To sort an array using insertionsort and return the number of swap operations performed while sorting
*/

//function definition
int insertionsort(int* x, int size);

//start of main function
int main () {
    
    return 0;
} //end of main function

//start of bubblesort function, taking an integer array and its size as an int for inputs and outputting the number of examinations the algorithm makes as an integer
int insertionsort(int* x, int size) {
    //initializing variables used for sorting and counting examinations
    int index, j;
    int exams = 0;
    //iterates through each index for use in insertion sort
    for (int i = 1; i < size; i++) {
        //stores the value in the array in relation to the index iterating in for loop
        index = x[i];
        j = i - 1;
        //iterates back through to the start of the array if the index at j is greater than the one after it
        while (j >= 0 && x[j] > index) {
            x[j + 1] = x[j];
            j--; 
            //adds to examinations counter
            exams++;
        }
        //adds to examinations counter only if the while terminates after examination took place
        if (j >= 0) {
            exams++;
        }
        //sets the value after j to the index found initially once the condition in the while loop was reached
        x[j + 1] = index;
    }
    return exams;
} //end of insertionsort function