/* Description: Cook book with broccoli recipes...
 * Author: Nicholas Ishankov
 * Date: 08/04/2020
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "rawRecipes.h"
#include <string.h>

#define MAXRECIPES 30 /* max # of recipes */
#define MAXINGREDIENTTYPES 250 /* max # of ingredient types */
#define MAXINGREDIENTS 250 /* max # of ingredients all recipes */

struct recipe{ //recipe struct
	char recipeName[100];
	char *ingredientsRecipe[MAXINGREDIENTTYPES]; //array of ingredients of that recipe
}recipe;

struct recipe recipes[MAXRECIPES]; //array of recipe structs
char *ingredients[MAXINGREDIENTS]; //array of ingredients
 
bool notDuplicate(int k, int i){
	for(int n = 0; n < k; n++){
		if((strcmp(ingredients[n], rawRecipes[i]+1))== 0){
			return false;
		}
	}
	return true;
}
 
void convertInputToDataStructure(){
	for(int i = 0; i < MAXINGREDIENTS; i++){
		ingredients[i] = (char*)calloc(100, sizeof(char));
	}
	
	for(int i = 0; i < MAXRECIPES; i++){
		for(int j = 0; j < MAXINGREDIENTS; j++){
		recipes[i].ingredientsRecipe[j] = (char*)calloc(100, sizeof(char));
		
		}
	}
	
	int i = 0;
	int j = 0;
	int k = 0;
	int l = 0;
	while(*rawRecipes[i] != '\0'){
		if(*rawRecipes[i] == '0'){ //recipe
			strcpy(recipes[j].recipeName, rawRecipes[i]+1);
			i++;
			l = 0;
			while(*rawRecipes[i] == '1'){ //ingredient
				if(notDuplicate(k,i)){
					strcpy(ingredients[k], rawRecipes[i]+1);
					k++;
				}
				strcpy(recipes[j].ingredientsRecipe[l], rawRecipes[i]+1); 
				l++;
				i++;
			}
			j++;
		}
		
		
	}
}

void printMenu() {
    printf("\n\nEnter a command by number\n");
    printf("1. List all Recipes\n");
    printf("2. Print a Recipe\n");
    printf("3. List All Recipes with a given ingredient\n");
    printf("4. List All Ingredients in alphabetical order\n");
    printf("5. Exit the program\n");
    printf("Give input: ");
}

void printAllRecipes(){
	int i = 0;
	while(i<24){
		printf("Recipe #%d: %s\n", i+1, recipes[i].recipeName);
		i++;
	}

}

void printRecipe(){
	int i = 0;
	int j = 0;
	printf("\n\nGive the number of the recipe (1-24):");
	scanf("%d", &i);
	
	printf("%s\n", recipes[i-1].recipeName);
	while(*recipes[i-1].ingredientsRecipe[j] != 0){
		printf("%s\n", recipes[i-1].ingredientsRecipe[j]);
		j++;
	}
}

void printForIngredient(){
	char input[250];
	int i = 0;
	int j = 0;
	
	printf("\n\nGive the name of the ingredient:");
	getchar();
	fgets(input, sizeof(input), stdin);
	
	input[strcspn(input, "\n")] = '\0';
	
	for(i = 0; i < 24; i++){
		j = 0;
		while(*recipes[i].ingredientsRecipe[j] != 0){
			if(strcmp(input, recipes[i].ingredientsRecipe[j])==0){
				printf("%s\n", recipes[i].recipeName);
			}
			j++;
		}
	}
	
}

void printAllIngredients(){
	char temp[250];
	
	for(int i = 0; i <= 96; i++){
		for(int j = i+1; j<=96; j++){
			if(strcmp(ingredients[i], ingredients[j])>0){
				strcpy(temp, ingredients[i]);
				strcpy(ingredients[i], ingredients[j]);
				strcpy(ingredients[j], temp);
			}
		}
	}
	
	printf("ALL INGREDIENTS\n");
	
	for(int i = 0; i < 97; i++){
		printf("%d: %s\n", i, ingredients[i]);
	}
}


int main(){
    // first move data from rawRecipes.h to a data structure
	convertInputToDataStructure();
	
	char notDone = 1;
	
	while(notDone){
		printMenu();
		int userChoice = 0;
		scanf("%d",&userChoice); 
		switch (userChoice){
			case 1: printAllRecipes(); break;
			case 2: printRecipe(); break;
			case 3: printForIngredient(); break;
			case 4: printAllIngredients(); break;
			case 5: notDone = 0; break;
			default: printf("Bad command\n"); break;
		}
	}

	return 0;
}
