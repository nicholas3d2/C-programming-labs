/* Description: C program that determines volume of a tank defined by user input width, height, length, and depth by using an integration function and an equation function.
 * Author: Nicholas Ishankov - 1005798521
 * Date: 11/02/2020
 */
#include <stdio.h>
#include <math.h>

double equation(double width, double height, double y){ //equation for half of ellipse (in terms of y)
	return sqrt(pow(width/2,2)*(1-(pow(y,2)/pow(height/2,2))));
}

//function that calculates the volume by using a trapezoidal integral to find the cross sectional area of the ellipse
void trapezoidalIntegral(double depth, int n, double width, double height, double length, double* result){ 
	//initialize double variables
	double delta = depth/n;
	double integral = 0.0;
	
	double y0 = -height/2; //start and end values for integration
	double yf = -height/2 + depth;
	
	integral = equation(width, height, y0) * delta/2 + equation(width, height, yf) * delta/2; //calculate endpoints (f(y0) and f(yf)) and add to integral
	for(int i = 1; i < n; i++){ //perform summation n times by calling equation and adding it to integral value each repetition
		integral += equation(width, height, y0 + i*delta)*delta;
	}
	
	*result = 2*integral*length; //as area was half of the ellipse in the equation, double the value then multiply by length of the tank for volume
	
}

int main(int argc, char **argv)
{
	double depth, width, length, height; //initialize double variables to store user inputs
	double result = 0.0;
	//prompt user to enter values
	printf("Enter the width of the tank (in meters): ");
	scanf("%lf", &width);
	printf("Enter the height of the tank (in meters): ");
	scanf("%lf", &height);
	printf("Enter the length of the tank (in meters): ");
	scanf("%lf", &length);
	printf("Enter the specific depth on the measuring stick (in centimeters): ");
	scanf("%lf", &depth);
	printf("Depth %.2lf cm : ", depth);
	
	trapezoidalIntegral(depth/100, 10000, width, height, length, &result); //call function to evaluate volume
	
	printf("Volume %.2lf cubic meters\n", result); //print volume result
	
	return 0;
}
