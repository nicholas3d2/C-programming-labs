/* Description: C program that calculates a ski rental charge with a user input daily rate, and rental period,
 * with a free day for every 3 days renting.  
 * Author: Nicholas Ishankov - 1005798521
 * Date: 17/01/2020
 * */
#include <stdio.h>

int main(int argc, char **argv)
{
	float dailyRate; //declare float variable for daily rate
	int rentalPeriod; //declare integer variable for rental period
	int freeDays; //declare integer variable for number of free days
	const float hst = 1.13; //declare constant float for %13 tax multiplier
    
    printf("Enter the daily rate: "); //prompt user to input data
	scanf("%f", &dailyRate); //read and save user input
	printf("Enter the rental period (in days): \n"); 
	scanf("%d", &rentalPeriod); 
    
    freeDays = rentalPeriod/4; //compute number of free days by performing integer division with rental period/4
	printf("Your total free day(s) in this rental is: %d\n", freeDays); //display total number of free days
	printf("The total charge including taxes is: %.2f\n", dailyRate*(rentalPeriod-freeDays)*hst); //compute and display total charge with 2 decimal points
    
	return 0;
}
