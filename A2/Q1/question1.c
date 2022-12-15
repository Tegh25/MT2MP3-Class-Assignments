#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

/*
Author: Teghveer Ateliey
Date created: Oct 22, 2022
Last modified: Oct 22, 2022
Purpose: To compute the mean, median, and mode of each given array while also given the size of each array
*/

//function definitions
int* sortArray(int* x, int size);
double mean(int* x, int size);
double median(int* x, int size);
int mode(int* x, int size);

//start of main function
int main () {
    
    return 0;
} //end of main function

//start of sortArray function which takes an array and its size as input and returns the array sorted using insertion sort
int* sortArray(int* x, int size) {
    //initializing variables used for sorting
    int index, j;
    //iterates through each index for use in insertion sort
    for (int i = 1; i < size; i++) {
        //stores the value in the array in relation to the index iterating in for loop
        index = x[i];
        j = i - 1;
        //iterates back through to the start of the array if the index at j is greater than the one after it
        while (j >= 0 && x[j] > index) {
            x[j + 1] = x[j];
            j--;
        }
        //sets the value after j to the index found initially once the condition in the while loop was reached
        x[j + 1] = index;
    }
    //returns the sorted array
    return x;
} //end of sortArray function

//start of mean function taking int array x and int size as input, returning the mean of the array as a double
double mean(int* x, int size) {
    //initializing sum variable to calculating mean/average
    int sum = 0;
    //iterates through array to add each index to the sum variable
    for (int i = 0; i < size; i++) {
        sum += x[i];
    }
    //returns sum divided by the size of the array
    return (double) sum / size;
} //end of mean function

//start of mean function taking int array x and int size as input, returning the median of the array as a double
double median(int* x, int size) {
    //initializes storage for sorted array
    int sorted[size];
    //uses sort function to sort array then assign it to the initialized variable
    for (int i = 0; i < size; i++) {
        sorted[i] = sortArray(x, size)[i];
    }
    //finds the median of the array depending on if the array size is even or odd
    if (size % 2 == 1) {
        return sorted[(int) floor(size/2.0)];
    } else {
        return (sorted[size/2 - 1] + sorted[size/2]) / 2.0;
    }
} //end of median function

//start of mean function taking int array x and int size as input, returning the mode of the array as an int
int mode(int* x, int size) {
    //initializes storage for sorted array
    int sorted[size];
    //uses sort function to sort array then assign it to the initialized variable
    for (int i = 0; i < size; i++) {
        sorted[i] = sortArray(x, size)[i];
    }
    //intializes variables to count the number of each unique value in the array
    int highestTally = 1;
    int tally = 1;
    //intializes variable to store the unique value that shows up the most in the array
    int mode = sorted[0];
    //iterates through sorted list to compare values at each index
    for (int i = 1; i < size; i++) {
        //compares each index with the one before it
        if (sorted[i-1] == sorted[i]) {
            //adds to the tally if they match, this means there is more than one instance of that unique value
            tally++;
            //if the tally beats the highest tally, that means that this unique value shows up the most in the array
            if (tally > highestTally) {
                highestTally++;
                //sets the mode to the value with the most tallies
                mode = sorted[i];
            }
        } else {
            //resets tallies when moving to a new unique value in the array
            tally = 1;
        }
    }
    //returns mode as an int
    return mode;
} //end of mode function