/* Description: C program that creates an m by n 2d array determined by the user and randomly places mines on a grid. Two grids are 
 * output, one showing safe and dangerous tiles and the other showing how many mines border the safe tile.
 * Author: Nicholas Ishankov - 1005798521
 * Date: 21/02/2020
 */
#include <stdio.h>
#include "lab6.h"

int main(int argc, char **argv)
{
	//intialize variables to store user input variables
	int m, n; //rows, cols
	double p; //probability
	
	//read user inputs
	printf("Enter the number of rows: ");
	scanf("%d", &m);
	printf("Enter the number of columns: ");
	scanf("%d", &n);
	printf("Enter the probability p value: ");
	scanf("%lf", &p);
	
	int grid[m + 2][n + 2]; //generate 2d array for the grid
	double randNum;
	//initial grid
	for(int i = 0; i < m + 2; i++){ //row
		for(int j = 0; j < n + 2; j++){ //col
			if(i == 0 || i == m + 1 || j == 0 || j == n + 1){
				grid[i][j] = 0; //safe
			}else{
				randNum = rand(); //generate number between 0 and 1
				if(randNum < p){
					grid[i][j] = 1; //mine
				}else{
					grid[i][j] = 0; //safe
				}
			}
		}
	}
	
	//seperate grid with lines
	for(int i = 0; i < 2*n -1; i++){
		printf("-");
	}
	printf("\n");
	
	//print grid with mines
	for(int i = 1; i < m + 1; i++){
		for(int j = 1; j < n + 1; j++){
			if(grid[i][j] == 1){
				printf("* "); //print mine
			}else{
				printf(". "); //print no mine
			}
		}
		printf("\n");
	}
	
	//seperate grid with lines
	for(int i = 0; i < 2*n -1; i++){
		printf("-");
	}
	printf("\n");
	
	//final grid (with neighboring data)
	for(int i = 1; i < m + 1; i++){
		for(int j = 1; j < n + 1; j++){
			if(grid[i][j] == 0){ //if a tile is safe proceed to check all neighboring tiles
				int counter = 9; //start counter at 9 to avoid later confusion when printing mines for 1 and 1 for neighboring tiles
				if(grid[i+1][j] == 1){
					counter++;
				}
				if(grid[i-1][j] == 1){
					counter++;
				}
				if(grid[i][j+1] == 1){
					counter++;
				}
				if(grid[i][j-1] == 1){
					counter++;
				}
				if(grid[i+1][j+1] == 1){
					counter++;
				}
				if(grid[i+1][j-1] == 1){
					counter++;
				}
				if(grid[i-1][j+1] == 1){
					counter++;
				}
				if(grid[i-1][j-1] == 1){
					counter++;
				}
				grid[i][j] = counter; //for every unsafe tile increase counter by 1 and then save that value into the grid position
			}
		}
	}
	
	//print grid with neighboring mine info
	for(int i = 1; i < m+1; i++){
		for(int j = 1; j < n+1; j++){
			if(grid[i][j] == 1){
				printf("* "); //print mine
			}else{
				printf("%d ", grid[i][j] - 9); //print value with neighboring mines 
			}
		}
		printf("\n");
	}
	
	for(int i = 0; i < 2*n -1; i++){
		printf("-");
	}
	printf("\n");
	
	return 0;
}
