#include <stdio.h>
#include <assert.h>
#include <math.h>

/*
Author: Teghveer Ateliey
Date created: Oct 1, 2022
Last modified: Oct 1, 2022
Purpose: to calculate the average gas mileage in one or more trips as inputted by the user
*/

//function declaration
void mileage (void);

//start of main function
int main () {
	mileage();
    return 0;
} //end of main function

//mileage function takes no input and returns void output, function prompts user for trip details and prints mileage of trip
void mileage (void) {
    //initializes variables for inputting fuel and distance for each trip, total fuel/dist for all trips
    float totalFuel, fuelUsed;
    float totalDist, distance;
    //initializes variable for user to declare if they have more data or not
    char cont = 'y';

    //do while loop contiuously prompts user for fuel/dist trip details and adds to total fuel, then prompts to allow user to terminate the loop
    do {
        //prompts user for the fuel used during the trip
        printf("How much fuel have you used? : ");
        scanf("%f", &fuelUsed);
        //adds fuel used in trip to total used in all trips
        totalFuel += fuelUsed;

        //prompts user for the distance travelled during the trip
        printf("How far did you travel? : ");
        scanf("%f", &distance);
        //adds distance travelled in trip to total travelled in all trips
        totalDist += distance;

        //prompts user if they would like to continue
        printf("Do you have more data to enter? (y/n) : ");
        scanf(" %c", &cont);
        
    //ends do while loop if user does not enter y (yes)
    } while (cont == 'y');
    //prints the gas mileage (total distance travelled divided by total fuel used) to 4 decimal places
    printf("\nYour gas mileage is %.4f\n", totalDist/totalFuel);
} //end of mileage function