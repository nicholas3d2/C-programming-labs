/* Description: C program that calculates the monthly payment for a car with user input purchase price, 
 * down payment, finance term, and interest rate.
 * Author: Nicholas Ishankov - 1005798521
 * Date: 17/01/2020
 * */

#include <stdio.h>
#include <math.h>

int main(int argc, char **argv)
{
	int P; //declare variables
	int D; 
	int n; 
	float r; 
	double M; 
    
    printf("Enter the purchase price P: "); //prompt user to input data
	scanf("%d", &P); //read and save user input
	printf("Enter the amount of down payment D: "); 
	scanf("%d", &D); 
	printf("Enter the finance term (in months): "); 
	scanf("%d", &n); 
    printf("Enter the monthly interest rate (in percent): "); 
	scanf("%f", &r); 
    
    r/=100; //r must a percentage so /100
	M = ((P-D)*r*(pow((1+r),n)))/(pow((1+r),n)-1); //formula for monthly payment
	
	printf("The monthly payment is: %.2lf\n", M); //output monthly payment M
	return 0;
}
