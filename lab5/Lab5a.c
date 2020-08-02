/* Description: C program that reads two user inputs n and q, and then using a function the program finds two values that add to q and 
 * have n as a product.
 * Author: Nicholas Ishankov - 1005798521
 * Date: 07/02/2020
 */
#include <stdio.h>

//function to try and find pair of divisors of n which sum up to q
void getPairDivisor(int n, int q, int* mAddress, int* pAddress){ //parameters n, q and pointer to mAddress and pAddress
	int p = 0; //initialize variable to be used as p divisor
	for(int m = 0; m < q/2; m++){ //m divisor of n
		p = q - m; //p divisor of n
		if(m*p == n){ //if n is a product of the divisors
			//save values to pointer to address
			*mAddress = m; 
			*pAddress = p;
		}
	}
}

int main(int argc, char **argv)
{
	int n, q, m, p; //initialize variables
	m = 0;
	p = q;
	
	//prompt and read user inputs
	printf("Please enter an input number n: ");
	scanf("%d", &n);
	printf("Please enter a query number q: ");
	scanf("%d", &q);
	
	getPairDivisor(n, q, &m, &p); //call function to get pair divisors
	
	if(m != 0){ //if an m value was found (m isnt 0 anymore) print results
		printf("m = %d, p = %d, m*p = %d, and m+p = %d\n", m, p, n, q);
	}else{ 
		printf("The program could not find any pair divisors for these inputs\n");
	}
		
	return 0;
}
