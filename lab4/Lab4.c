/* Description: C program that calculates credit card purchased value, and total interest charges using a for loop and function. User
 * inputs include amount already owed, monthly purchases and payments, interest, and months.
 * Author: Nicholas Ishankov - 1005798521
 * Date: 03/02/2020
 */
 
#include <stdio.h>
#include <stdlib.h>
//function that returns due amount ath the end of a month as a double
double owedAmount(double previousMonth, double purchases, double repaid, double interest){ //parameters include previous months due amount, purchases, payment, interest
	double dueAmount; //initialize double variable to be used in formula d = u + p + ((u + p)*i) - r
	if(previousMonth > 0 || purchases > repaid){ //check if there was money due in the previous month, or if more was purchesed then repaid
		dueAmount = previousMonth + purchases + ((previousMonth + purchases)*interest) - repaid; //calculate due amount
	}else{
		dueAmount = 0; //else, no money due for the next month
	}
	
	if(dueAmount < 0){ //if the due amount is a negative value, return a 0
		return 0.0;
	}else{
		return dueAmount; //return due amount
	}
}

int main(int argc, char **argv)
{
	//initialize variables to store user inputs
	double initialOwed, alreadyOwed, purchases, payment, interest, totalInterest = 0.0;
	int months;
	
	//prompt user to enter inputs
	printf("Enter amount already owed on card: ");
	scanf("%lf", &alreadyOwed);
	initialOwed = alreadyOwed;
	printf("Enter purchase amount per month: ");
	scanf("%lf", &purchases);
	printf("Enter payment amount per month: ");
	scanf("%lf", &payment);
	printf("Enter yearly interest rate as percent: ");
	scanf("%lf", &interest);
	printf("Enter number of months to consider: ");
	scanf("%d", &months);
	
	for(int i = 0; i<months; i++){ //for loop where amount of calculations determined by input months
		if(alreadyOwed != 0){ //compound interest if money is owed
			totalInterest += (alreadyOwed + purchases)*(interest/1200);
		}
		
		alreadyOwed = owedAmount(alreadyOwed, purchases, payment, interest/1200); //call function
	}
	
	printf("Total purchased value: %.2lf\n", initialOwed + (purchases*months)); //output total purchased value
	printf("Total interest charges: %.2lf\n", totalInterest); //output total interest
	
	return 0;
}
