/* Description: C program that calculates the resistances of 2 user created resistors with character inputs throught the terminal.
 * The resistances and tolerances are output, and the resistors in series and parallel is calculated and output. 
 * Author: Nicholas Ishankov - 1005798521
 * Date: 24/01/2020
 */
 
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	char band1R1, band2R1, bandmR1, bandtR1, band1R2, band2R2, bandmR2, bandtR2; //initialize character variables to store user inputs
	int b1r1, b2r1, b1r2, b2r2; //initialize integer variables
	float bmr1, bmr2, btr1, btr2; //initialize float variables for multiplier and tolerance
	
	//prompt and save user inputs for band character; resistor 1
	printf("Please enter the 1st band of resistor 1: \n");
	scanf(" %c", &band1R1);
	printf("Please enter the 2nd band of resistor 1: \n");
	scanf(" %c", &band2R1);
	printf("Please enter the multiplier band of resistor 1: \n");
	scanf(" %c", &bandmR1);
	printf("Please enter the tolerance band of resistor 1: \n");
	scanf(" %c", &bandtR1);
	
	//prompt and save user inputs for band character; resistor 2
	printf("Please enter the 1st band of resistor 2: \n");
	scanf(" %c", &band1R2);
	printf("Please enter the 2nd band of resistor 2: \n");
	scanf(" %c", &band2R2);
	printf("Please enter the multiplier band of resistor 2: \n");
	scanf(" %c", &bandmR2);
	printf("Please enter the tolerance band of resistor 2: \n");
	scanf(" %c", &bandtR2);
	
	printf("\nColour bands for resistor 1: \n");
	//logic to determine and print band 1 color for resistor 1, and assign the according value to variables
	if((band1R1 == 'K')||(band1R1 == 'k')){
		b1r1 = 0;
		printf("Black ");
	}else if((band1R1 == 'B')||(band1R1 == 'b')){
		b1r1 = 1;
		printf("Brown ");
	}else if((band1R1 == 'R')||(band1R1 == 'r')){
		b1r1 = 2;
		printf("Red ");
	}else if((band1R1 == 'O')||(band1R1 == 'o')){
		b1r1 = 3;
		printf("Orange ");
	}else if((band1R1 == 'E')||(band1R1 == 'e')){
		b1r1 = 4;
		printf("Yellow ");
	}else if((band1R1 == 'G')||(band1R1 == 'g')){
		b1r1 = 5;
		printf("Green ");
	}else if((band1R1 == 'U')||(band1R1 == 'u')){
		b1r1 = 6;
		printf("Blue ");
	}else if((band1R1 == 'V')||(band1R1 == 'v')){
		b1r1 = 7;
		printf("Violet ");
	}else if((band1R1 == 'Y')||(band1R1 == 'y')){
		b1r1 = 8;
		printf("Grey ");
	}else if((band1R1 == 'W')||(band1R1 == 'w')){
		b1r1 = 9;
		printf("White ");
	}else{
		printf("\nInvalid colour for the 1st band of resistor 1. Exiting the program... \n"); //if no color matched the input, exit the program
		exit(0);
	}
	
	//logic to determine band 2 for resistor 1
	if((band2R1 == 'K')||(band2R1 == 'k')){
		b2r1 = 0;
		printf("Black ");
	}else if((band2R1 == 'B')||(band2R1 == 'b')){
		b2r1 = 1;
		printf("Brown ");
	}else if((band2R1 == 'R')||(band2R1 == 'r')){
		b2r1 = 2;
		printf("Red ");
	}else if((band2R1 == 'O')||(band2R1 == 'o')){
		b2r1 = 3;
		printf("Orange ");
	}else if((band2R1 == 'E')||(band2R1 == 'e')){
		b2r1 = 4;
		printf("Yellow ");
	}else if((band2R1 == 'G')||(band2R1 == 'g')){
		b2r1 = 5;
		printf("Green ");
	}else if((band2R1 == 'U')||(band2R1 == 'u')){
		b2r1 = 6;
		printf("Blue ");
	}else if((band2R1 == 'V')||(band2R1 == 'v')){
		b2r1 = 7;
		printf("Violet ");
	}else if((band2R1 == 'Y')||(band2R1 == 'y')){
		b2r1 = 8;
		printf("Grey ");
	}else if((band2R1 == 'W')||(band2R1 == 'w')){
		b2r1 = 9;
		printf("White ");
	}else{
		printf("\nInvalid colour for the 2nd band of resistor 1. Exiting the program... \n");
		exit(0);
	}
	
	//logic to determine band 3 for resistor 1
	if((bandmR1 == 'K')||(bandmR1 == 'k')){
		bmr1 = 1;
		printf("Black ");
	}else if((bandmR1 == 'B')||(bandmR1 == 'b')){
		bmr1 = 10;
		printf("Brown ");
	}else if((bandmR1 == 'R')||(bandmR1 == 'r')){
		bmr1 = 100;
		printf("Red ");
	}else if((bandmR1 == 'O')||(bandmR1 == 'o')){
		bmr1 = 1000;
		printf("Orange ");
	}else if((bandmR1 == 'E')||(bandmR1 == 'e')){
		bmr1 = 10000;
		printf("Yellow ");
	}else if((bandmR1 == 'G')||(bandmR1 == 'g')){
		bmr1 = 100000;
		printf("Green ");
	}else if((bandmR1 == 'U')||(bandmR1 == 'u')){
		bmr1 = 1000000;
		printf("Blue ");
	}else if((bandmR1 == 'V')||(bandmR1 == 'v')){
		bmr1 = 10000000;
		printf("Violet ");
	}else if((bandmR1 == 'L')||(bandmR1 == 'l')){
		bmr1 = 0.1;
		printf("Gold ");
	}else if((bandmR1 == 'S')||(bandmR1 == 's')){
		bmr1 = 0.01;
		printf("Silver ");
	}else{
		printf("\nInvalid colour for the multiplier band of resistor 1. Exiting the program... \n");
		exit(0);
	}
	
	//logic to determine band 4 for resistor 1
	if((bandtR1 == 'K')||(bandtR1 == 'k')){
		btr1 = 0;
		printf("Black ");
	}else if((bandtR1 == 'B')||(bandtR1 == 'b')){
		btr1 = 1;
		printf("Brown ");
	}else if((bandtR1 == 'R')||(bandtR1 == 'r')){
		btr1 = 2;
		printf("Red ");
	}else if((bandtR1 == 'Y')||(bandtR1 == 'y')){
		btr1 = 0.05;
		printf("Grey ");
	}else if((bandtR1 == 'G')||(bandtR1 == 'g')){
		btr1 = 0.5;
		printf("Green ");
	}else if((bandtR1 == 'U')||(bandtR1 == 'u')){
		btr1 = 0.25;
		printf("Blue ");
	}else if((bandtR1 == 'V')||(bandtR1 == 'v')){
		btr1 = 0.10;
		printf("Violet ");
	}else if((bandtR1 == 'L')||(bandtR1 == 'l')){
		btr1 = 5;
		printf("Gold ");
	}else if((bandtR1 == 'S')||(bandtR1 == 's')){
		btr1 = 10;
		printf("Silver ");
	}else{
		printf("\nInvalid colour for the tolerance band of resistor 1. Exiting the program... \n");
		exit(0);
	}
	
	printf("\nColour bands for resistor 2: \n");
	//logic to determine and print band 1 for resistor 2, and assign according values to variables
	if((band1R2 == 'K')||(band1R2 == 'k')){
		b1r2 = 0;
		printf("Black ");
	}else if((band1R2 == 'B')||(band1R2 == 'b')){
		b1r2 = 1;
		printf("Brown ");
	}else if((band1R2 == 'R')||(band1R2 == 'r')){
		b1r2 = 2;
		printf("Red ");
	}else if((band1R2 == 'O')||(band1R2 == 'o')){
		b1r2 = 3;
		printf("Orange ");
	}else if((band1R2 == 'E')||(band1R2 == 'e')){
		b1r2 = 4;
		printf("Yellow ");
	}else if((band1R2 == 'G')||(band1R2 == 'g')){
		b1r2 = 5;
		printf("Green ");
	}else if((band1R2 == 'U')||(band1R2 == 'u')){
		b1r2 = 6;
		printf("Blue ");
	}else if((band1R2 == 'V')||(band1R2 == 'v')){
		b1r2 = 7;
		printf("Violet ");
	}else if((band1R2 == 'Y')||(band1R2 == 'y')){
		b1r2 = 8;
		printf("Grey ");
	}else if((band1R2 == 'W')||(band1R2 == 'w')){
		b1r2 = 9;
		printf("White ");
	}else{
		printf("\nInvalid colour for the 1st band of resistor 2. Exiting the program... \n");
		exit(0);
	}
	
	//logic to determine band 2 for resistor 2
	if((band2R2 == 'K')||(band2R2 == 'k')){
		b2r2 = 0;
		printf("Black ");
	}else if((band2R2 == 'B')||(band2R2 == 'b')){
		b2r2 = 1;
		printf("Brown ");
	}else if((band2R2 == 'R')||(band2R2 == 'r')){
		b2r2 = 2;
		printf("Red ");
	}else if((band2R2 == 'O')||(band2R2 == 'o')){
		b2r2 = 3;
		printf("Orange ");
	}else if((band2R2 == 'E')||(band2R2 == 'e')){
		b2r2 = 4;
		printf("Yellow ");
	}else if((band2R2 == 'G')||(band2R2 == 'g')){
		b2r2 = 5;
		printf("Green ");
	}else if((band2R2 == 'U')||(band2R2 == 'u')){
		b2r2 = 6;
		printf("Blue ");
	}else if((band2R2 == 'V')||(band2R2 == 'v')){
		b2r2 = 7;
		printf("Violet ");
	}else if((band2R2 == 'Y')||(band2R2 == 'y')){
		b2r2 = 8;
		printf("Grey ");
	}else if((band2R2 == 'W')||(band2R2 == 'w')){
		b2r2 = 9;
		printf("White ");
	}else{
		printf("\nInvalid colour for the 2nd band of resistor 2. Exiting the program... \n");
		exit(0);
	}
	
	//logic to determine band 3 for resistor 2
	if((bandmR2 == 'K')||(bandmR2 == 'k')){
		bmr2 = 1;
		printf("Black ");
	}else if((bandmR2 == 'B')||(bandmR2 == 'b')){
		bmr2 = 10;
		printf("Brown ");
	}else if((bandmR2 == 'R')||(bandmR2 == 'r')){
		bmr2 = 100;
		printf("Red ");
	}else if((bandmR2 == 'O')||(bandmR2 == 'o')){
		bmr2 = 1000;
		printf("Orange ");
	}else if((bandmR2 == 'E')||(bandmR2 == 'e')){
		bmr2 = 10000;
		printf("Yellow ");
	}else if((bandmR2 == 'G')||(bandmR2 == 'g')){
		bmr2 = 100000;
		printf("Green ");
	}else if((bandmR2 == 'U')||(bandmR2 == 'u')){
		bmr2 = 1000000;
		printf("Blue ");
	}else if((bandmR2 == 'V')||(bandmR2 == 'v')){
		bmr2 = 10000000;
		printf("Violet ");
	}else if((bandmR2 == 'L')||(bandmR2 == 'l')){
		bmr2 = 0.1;
		printf("Gold ");
	}else if((bandmR2 == 'S')||(bandmR2 == 's')){
		bmr2 = 0.01;
		printf("Silver ");
	}else{
		printf("\nInvalid colour for the multiplier band of resistor 2. Exiting the program... \n");
		exit(0);
	}
	
	//logic to determine band 4 for resistor 2
	if((bandtR2 == 'K')||(bandtR2 == 'k')){
		btr2 = 0;
		printf("Black ");
	}else if((bandtR2 == 'B')||(bandtR2 == 'b')){
		btr2 = 1;
		printf("Brown ");
	}else if((bandtR2 == 'R')||(bandtR2 == 'r')){
		btr2 = 2;
		printf("Red ");
	}else if((bandtR2 == 'Y')||(bandtR2 == 'y')){
		btr2 = 0.05;
		printf("Grey ");
	}else if((bandtR2 == 'G')||(bandtR2 == 'g')){
		btr2 = 0.5;
		printf("Green ");
	}else if((bandtR2 == 'U')||(bandtR2 == 'u')){
		btr2 = 0.25;
		printf("Blue ");
	}else if((bandtR2 == 'V')||(bandtR2 == 'v')){
		btr2 = 0.10;
		printf("Violet ");
	}else if((bandtR2 == 'L')||(bandtR2 == 'l')){
		btr2 = 5;
		printf("Gold ");
	}else if((bandtR2 == 'S')||(bandtR2 == 's')){
		btr2 = 10;
		printf("Silver ");
	}else{
		printf("\nInvalid colour for the tolerance band of resistor 2. Exiting the program... \n");
		exit(0);
	}
	
	printf("\nValue in ohms of resistor 1: \n");
	
	float resistance1 = (b1r1*10 + b2r1)*bmr1; //calculate the resistance of the first resistor
	//determine proper units for resistor 1
	if (resistance1 < 1000){ //ohms if less than 1000
		printf("%.2f Ohms +/- %.2f%% \n", resistance1, btr1);
	}else if(1000 <= resistance1 && resistance1 < 1000000){ //KOhms if greater than or equal to 1000 and less than 1000000
		printf("%.2f KOhms +/- %.2f%% \n", resistance1/1000, btr1);
	}else{ //MOhms if greater than or equal to 1000000
		printf("%.2f MOhms +/- %.2f%% \n", resistance1/1000000, btr1);
	}
	
	printf("Value in ohms of resistor 2: \n");
	
	float resistance2 = (b1r2*10 + b2r2)*bmr2; //calculate the resistance of the second resistor
	//determine proper units for resistor 2
	if (resistance2 < 1000){
		printf("%.2f Ohms +/- %.2f%% \n", resistance2, btr2);
	}else if(1000 <= resistance2 && resistance2 < 1000000){
		printf("%.2f KOhms +/- %.2f%% \n", resistance2/1000, btr2);
	}else{
		printf("%.2f MOhms +/- %.2f%% \n", resistance2/1000000, btr2);
	}
	
	float series = resistance1 + resistance2; //calculate resistors in series 
	float parallel = (resistance1*resistance2)/series; //calculate resistors in parallel
	
	printf("\nThe Equivalent in series is ");
	//determine proper units for series
	if(series < 1000){
		printf("%.2f Ohms\n", series);
	}else if(1000 <= series && series < 1000000){
		printf("%.2f KOhms\n", series/1000);
	}else{
		printf("%.2f MOhms\n", series/1000000);
	}
	
	printf("The Equivalent in parallel is ");
	//determine proper units for parallel
	if(parallel < 1000){
		printf("%.2f Ohms\n", parallel);
	}else if(1000 <= parallel && parallel < 1000000){
		printf("%.2f KOhms\n", parallel/1000);
	}else{
		printf("%.2f MOhms\n", parallel/1000000);
	}
	
	return 0;
}
