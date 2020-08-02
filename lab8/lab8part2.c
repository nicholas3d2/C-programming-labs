/* Description: Code to compete with AI
 * Author: Nicholas Ishankov
 * Date: 01/04/2020
 */
 
#include <stdio.h>
#include <stdbool.h>
//#include "lab8part2lib.h"

void printBoard(char board[][26], int n){
	printf("  ");
	for(int i = 0; i < n; i++){
		printf("%c", 97+i);
	}
	printf("\n");
	for(int i = 0; i < n; i++){
		printf("%c ", 97+i);
		for(int j = 0; j < n; j++){
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
}

bool positionInBounds(int n, int row, int col){
	return (row < n && col < n && row >= 0 && col >= 0);
}

bool checkLegalInDirection(char board[][26], int n, int row, int col, char color, int deltaRow, int deltaCol){
	bool legal = false;
	
	int count = 1;
	if(positionInBounds(n, row+count*deltaRow, col+count*deltaCol) && (board[row][col]=='U') && (board[row+deltaRow][col+deltaCol]!=color) && (board[row+deltaRow][col+deltaCol]!='U')){
		while(positionInBounds(n, row+count*deltaRow, col+count*deltaCol) && (board[row+count*deltaRow][col+count*deltaCol]!='U')){
			if(board[row+count*deltaRow][col+count*deltaCol] == color){
				legal = true;
				break;
			}
			count++;
		}
	}
	
	return legal;
}

bool movesAvailable(char board[][26], int n){
	bool available = false;
	
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
					for(int deltaRow = -1; deltaRow < 2; deltaRow++){ 
						for(int deltaCol = -1; deltaCol < 2; deltaCol++){
							if(!(deltaRow == 0 && deltaCol == 0) && checkLegalInDirection(board, n, i, j, 'W', deltaRow, deltaCol)){
								available = true;
							}
						}
					}
			}
		}
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
					for(int deltaRow = -1; deltaRow < 2; deltaRow++){ 
						for(int deltaCol = -1; deltaCol < 2; deltaCol++){
							if(!(deltaRow == 0 && deltaCol == 0) && checkLegalInDirection(board, n, i, j, 'B', deltaRow, deltaCol)){
								available = true;
							}
						}
					}
			}
		}
		
	return available;
}

void backupBoard(char board[][26],char temp[][26],int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			temp[i][j] = board[i][j];
		}
	}
}

void restoreBoard(char board[][26], char temp[][26], int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			board[i][j] = temp[i][j];
		}
	}
}

int testMove(char board[][26], int n, int color){
	int score = 0;
	int maxScore = 0;
	
	int flipRow = 0;
	int flipCol = 0;
	
	int count = 0;
	
	for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					bool available = false;
					score = 0;
						for(int deltaRow = -1; deltaRow < 2; deltaRow++){ 
							for(int deltaCol = -1; deltaCol < 2; deltaCol++){
								if(!(deltaRow == 0 && deltaCol == 0) && checkLegalInDirection(board, n, i, j, color, deltaRow, deltaCol)){
									available = true;
									
									flipRow = deltaRow;
									flipCol = deltaCol;
									
									count = 1;
									board[i][j] = color;
									while(positionInBounds(n, i+score*flipRow, j+score*flipCol) && (board[i+score*flipRow][j+score*flipCol]!='U')){
										score++;
										if(board[i+score*flipRow][j+score*flipCol] == color){
											break;
										}
									count++;
									}
									board[i][j] = 'U';
									
									if(score>maxScore){
										maxScore = score;
									}
									
								}
							}
						}
				}
			}
	return maxScore;
}

int main(int argc, char **argv)
{
	int n;
	
	char board[26][26];
	char temp[26][26];
	
	char computerColor;
	char playerColor;
	
	printf("Enter the board dimension: ");
	scanf("%d", &n);
	
	printf("Computer plays (B/W): ");
	scanf(" %c", &computerColor);
	
	//initial board config
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			board[i][j] = 'U';
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if((i == j) && i+1 == (n/2)){
				board[i][j] = 'W';
				board[i+1][j+1] = 'W';
				board[i][j+1] = 'B';
				board[i+1][j] = 'B';
			}
		}
	}
	
	//print initial config
	printBoard(board, n);
	
	bool endGame = false;
	
	bool computerTurn = false;
	bool playerTurn = false;
	
	int computerScore, playerScore;
	
	//set initial start turn
	if(computerColor == 'B'){
		computerTurn = true;
		playerColor = 'W';
	}else{
		playerTurn = true;
		playerColor = 'B';
	}
	
	char color;
	char row;
	char col;
	
	int count = 0;
	
	int score = 0;
	int minScore = 0;
	
	int flipRow = 0;
	int flipCol = 0;
	
	int bestRow = 0;
	int bestCol = 0;
	
	bool noMove = false;
	
	bool legal = false;
	
	while((!endGame) && movesAvailable(board, n)){
		
		if(computerTurn){
			
			color = computerColor;
			
			score = 0;
			minScore = 100;
			
			flipRow = 0;
			flipCol = 0;
			
			bestRow = 0;
			bestCol = 0;
			
			noMove = true;
			
			int movesFound = 0;
			
			backupBoard(board, temp, n); //BOARD BACKED UP INTO TEMP BEFORE MOVE MADE!!!
			
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					for(int deltaRow = -1; deltaRow < 2; deltaRow++){ 
						for(int deltaCol = -1; deltaCol < 2; deltaCol++){
							if(!(deltaRow == 0 && deltaCol == 0) && checkLegalInDirection(board, n, i, j, color, deltaRow, deltaCol)){
								noMove = false;
								
								if((i == 0 && j == 0) || (i == 0 && j == n-1) || (i == n-1 && j == n-1) || (i == n-1 && j == 0)){
									bestRow = i;
									bestCol = j;
									
								}else{
								
								backupBoard(board, temp, n); //ACTUAL BOARD BACKED UP INTO TEMP BEFORE MOVE MADE!!!
								flipRow = deltaRow;
								flipCol = deltaCol;
								row = i;
								col = j;
								
								board[row][col] = color;
								count = 1;
								while(positionInBounds(n, row+count*flipRow, col+count*flipCol) && (board[row+count*flipRow][col+count*flipCol]!='U')){
									if(board[row+count*flipRow][col+count*flipCol] == color){
										break;
									}
									board[row+count*flipRow][col+count*flipCol] = color;
									count++;
								}
								
								int score = testMove(board, n, playerColor);
								
								if(!(i == 1 && j == 0) && !(i == 1 && j == 1) && !(i == 0 && j == 1) 
								&& !(i == n-2 && j == 0) && !(i == n-2 && j == 1) && !(i == n-1 && j == 1) 
								&& !(i == 1 && j == n-1) && !(i == 1 && j == n-2) && !(i == 0 && j == n-2)
								&& !(i == n-2 && j == n-1) && !(i == n-2 && j == n-2) && !(i == n-1 && j == n-2)){
									movesFound++;
									if(score<=minScore){
										minScore = score;
										bestRow = i;
										bestCol = j;
									}
									
								}else if(score<minScore && movesFound == 0){ 
									minScore = score;
									bestRow = i;
									bestCol = j;
								}
								
								restoreBoard(board, temp, n); //RESTORE ACTUAL GAME BOARD
								
								}
							}
						}
					}
				}
			}
			
			if(noMove){
				printf("%c player has no valid move.\n", computerColor);
			}else{ //make best possible play
				
				flipRow = 0;
				flipCol = 0;
				
				row = bestRow;
				col = bestCol;
	
				for(int deltaRow = -1; deltaRow < 2; deltaRow++){
					for(int deltaCol = -1; deltaCol < 2; deltaCol++){
						if(!(deltaRow == 0 && deltaCol == 0) && positionInBounds(n, row, col) && checkLegalInDirection(board, n, row, col, color, deltaRow, deltaCol)){
							flipRow = deltaRow;
							flipCol = deltaCol;
							
							board[row][col] = color;
								count = 1;
								while(positionInBounds(n, row+count*flipRow, col+count*flipCol) && (board[row+count*flipRow][col+count*flipCol]!='U')){
									if(board[row+count*flipRow][col+count*flipCol] == color){
										break;
									}
									board[row+count*flipRow][col+count*flipCol] = color;
									count++;
								}
							board[row][col] = 'U';
						}
					}
				}
				
				board[row][col] = color;
				
				printf("Computer places %c at %c%c.\n", computerColor, bestRow+97, bestCol+97);
				printBoard(board, n);
			}
			
			computerTurn = false;
			playerTurn = true;
			
		}//end computer turn
		
		else if(playerTurn){
			
			color = playerColor;
			
			noMove = true;
			
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					bool available = false;
						for(int deltaRow = -1; deltaRow < 2; deltaRow++){ 
							for(int deltaCol = -1; deltaCol < 2; deltaCol++){
								if(!(deltaRow == 0 && deltaCol == 0) && checkLegalInDirection(board, n, i, j, color, deltaRow, deltaCol)){
									available = true;
									noMove = false;
								}
							}
						}
				}
			}
			
			if(noMove){
				printf("%c player has no valid move.\n", playerColor);
			}else{
			//findSmarterMove(board, n, color, &row, &col);
			//printf("Testing AI move (row, col): %c%c\n", row +'a', col +'a');
			
			printf("Enter move for colour %c (RowCol): ", playerColor);
			scanf(" %c%c", &row, &col);
			
			flipRow = 0;
			flipCol = 0;
	
			row = row-97;
			col = col-97;
			
			legal = false;
	
			for(int deltaRow = -1; deltaRow < 2; deltaRow++){
				for(int deltaCol = -1; deltaCol < 2; deltaCol++){
					if(!(deltaRow == 0 && deltaCol == 0) && positionInBounds(n, row, col) && checkLegalInDirection(board, n, row, col, playerColor, deltaRow, deltaCol)){
						legal = true;
						flipRow = deltaRow;
						flipCol = deltaCol;
						
						board[row][col] = playerColor;
						count = 1;
						while(positionInBounds(n, row+count*flipRow, col+count*flipCol) && (board[row+count*flipRow][col+count*flipCol]!='U')){
							if(board[row+count*flipRow][col+count*flipCol] == playerColor){
								break;
							}
							board[row+count*flipRow][col+count*flipCol] = playerColor;
							count++;
						}
						board[row][col] = 'U';
					}
				}
			}
	
			if(legal){
				board[row][col] = playerColor;
				printBoard(board, n);
		
			}else{
				printf("Invalid move.\n");
				printf("%c player wins. \n", computerColor);
				endGame = false; //END GAME!
				return 0;
			}
			
		}
		
		playerTurn = false;
		computerTurn = true;
		
		}//end player turn
		
		
	} //game loop
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(board[i][j] == computerColor){
				computerScore++;
			}else if(board[i][j] == playerColor){
				playerScore++;
			}
		}
	}
	
	if(playerScore > computerScore){
		printf("%c player wins. \n", playerColor);
	}else if(playerScore < computerScore){
		printf("%c player wins. \n", computerColor);
	}else{
		printf("Draw! \n");
	}
	
	return 0;
}
