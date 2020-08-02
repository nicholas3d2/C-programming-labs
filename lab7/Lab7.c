/* Description: C program that supplements a reversi/othello type game
 * Author: Nicholas Ishankov
 * Date: 20/03/2020
 */
#include <stdio.h>
#include <stdbool.h>

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

/*bool legalMove(char board[][26], int n, int row, int col, int color, int flipRow, int flipCol){
	bool legal = false;
	
	for(flipRow = -1; flipRow < 2; flipRow++){
		for(flipCol = -1; flipCol < 2; flipCol++){
			if(!(flipRow == 0 && flipCol == 0) && positionInBounds(n, row, col) && checkLegalInDirection(board, n, row, col, color, flipRow, flipCol)){
				legal = true;
			}
		}
	}
	
	return legal;
	
}*/ 

int main(int argc, char **argv)
{
	int n;
	
	char board[26][26];
	
	printf("Enter the board dimension: ");
	scanf("%d", &n);
	
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
	
	//read input board config
	printf("Enter board configuration: \n");
	char color;
	char row;
	char col;
	bool end = true;
	do{
		scanf(" %c%c%c", &color, &row, &col);
		if(color == '!' && row == '!' && col == '!'){
			end = false;
		}else{
			board[row-97][col-97] = color;
		}
		
	}while(end);
	
	//print input board config
	printBoard(board, n);
	
	//print available moves for players W and B
	printf("Available moves for W:\n");
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			bool available = false;
				for(int deltaRow = -1; deltaRow < 2; deltaRow++){ 
					for(int deltaCol = -1; deltaCol < 2; deltaCol++){
						if(!(deltaRow == 0 && deltaCol == 0) && checkLegalInDirection(board, n, i, j, 'W', deltaRow, deltaCol)){
							available = true;
						}
					}
				}
				
				if(available){
					printf("%c%c\n", i+97,j+97);
				}
			}
		}
		
	printf("Available moves for B:\n");
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			bool available = false;
				for(int deltaRow = -1; deltaRow < 2; deltaRow++){ 
					for(int deltaCol = -1; deltaCol < 2; deltaCol++){
						if(!(deltaRow == 0 && deltaCol == 0) && checkLegalInDirection(board, n, i, j, 'B', deltaRow, deltaCol)){
							available = true;
						}
					}
				}
				
				if(available){
					printf("%c%c\n", i+97,j+97);
				}
			}
		}
		
	//See if user input move is valid, switch or leave board
	printf("Enter a move: \n");
	scanf(" %c%c%c", &color, &row, &col);
	
	int flipRow;
	int flipCol;
	
	row = row-97;
	col = col-97;
	
	bool legal = false;
	
	for(int deltaRow = -1; deltaRow < 2; deltaRow++){
		for(int deltaCol = -1; deltaCol < 2; deltaCol++){
			if(!(deltaRow == 0 && deltaCol == 0) && positionInBounds(n, row, col) && checkLegalInDirection(board, n, row, col, color, deltaRow, deltaCol)){
				legal = true;
				flipRow = deltaRow;
				flipCol = deltaCol;
			}
		}
	}
	
	if(legal){
		printf("Valid move.\n");
		board[row][col] = color;
		int count = 1;
			while(positionInBounds(n, row+count*flipRow, col+count*flipCol) && (board[row+count*flipRow][col+count*flipCol]!='U')){
				if(board[row+count*flipRow][col+count*flipCol] == color){
					break;
				}
				board[row+count*flipRow][col+count*flipCol] = color;
				count++;
			}
		
		printBoard(board, n);
		
	}else{
		printf("Invalid move.\n");
		printBoard(board, n);
	}
	
		return 0;
	}
	
	
	
