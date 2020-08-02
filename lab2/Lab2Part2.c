/* Description: C program that decrypts a user input integer in the form d(9-b)(9-c)a to abcd.
 * Author: Nicholas Ishankov - 1005798521
 * Date: 17/01/2020
 * */

#include <stdio.h>

int main(int argc, char **argv)
{
	int encrypted; //declare an integer variable to store the encrypted code
	
	printf("Enter an encrypted 4-digit combination: "); //prompt the user to enter their encrypted integer
	scanf("%d", &encrypted); //read and save user input integer
    
    //integer input in form d(9-b)(9-c)a and we need it in abcd.
	int a = encrypted%10; //yields 1's digit
	int c = -1*((encrypted/10)%10 - 9); //yields 10's digit - 9, then negated
	int b = -1*((encrypted/100)%10 - 9); //yields 100's digit - 9, then negated
	int d = (encrypted/1000)%10; //yields 1000's digit
    
    printf("The real combination is: %d%d%d%d\n", a,b,c,d); //output decrypted integer in form abcd
    
	return 0;
}
