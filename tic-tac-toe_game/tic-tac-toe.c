#include <stdio.h>
#include <stdlib.h>
#include "tictactoe.h"

int main(void){
	int i,j,row,column,position=-1,moves=9;
	int player,computer;
	int **board;



	board=malloc(3*sizeof(int*));
	for(i=0;i<3;i++){
		board[i]=malloc(3*sizeof(int));
	}

	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			board[i][j]=-1;
		}
	}
	while(position!=1 && position!=2){
		printf("Play first(=1) or play second(=2)?\n");
		scanf("%d",&position);
		if(position==1){
			player='O';
			computer='X';
		}
		if(position==2){
			player='X';
			computer='O';
		}
		if(position!=1 && position!=2){
			printf("Please give a valid input\n");
		}
}

	while(moves>=0){
		if(position==1){
			print_board(board);
			printf("Player's turn\n");
			printf("Enter the row and the column you want to put O\n");
			scanf("%d %d",&row,&column);
			printf("\033[2J\033[1;1H");
			if(row<0 || row>=3 || column<0 || column>=3){
				while(row<0 || row>=3 || column<0 || column>=3){
					printf("Please give me a valid box\n");
					printf("Enter the row and the column you want to put O\n");
					scanf("%d %d",&row,&column);
				}
			}
			if(board[row][column]==computer || board[row][column]==player){
				while(board[row][column]==computer || board[row][column]==player){
					printf("Please give me a box that is free\n");
					printf("Enter the row and the column you want to put O\n");
					scanf("%d %d",&row,&column);
				}
			}
			board[row][column]=player;   
			if(check_win(board,player)==1){
				print_board(board);
				printf("You won\n");
				return 0;
			}
			moves=moves-1;
			if(moves==0 && check_win(board,player)==0){
				print_board(board);
				printf("Draw\n");
				return 0;
			}
			minimax(board,computer,0,player,computer);
			if(check_win(board,computer)==1){
				print_board(board);
				printf("You lost\n");
				return 0;
			} 
			moves=moves-1;
		}

		if(position==2){
			minimax(board,computer,0,player,computer);
			if(check_win(board,computer)==1){
				print_board(board);
				printf("You lost\n");
				return 0;
			}
			moves=moves-1;
			if(moves==0 && check_win(board,computer)==0){
				print_board(board);
				printf("Draw\n");
				return 0;
			}
			print_board(board);
			printf("Player's turn\n");
			printf("Enter the row and the column you want to put X\n");
			scanf("%d %d",&row,&column);
			if(row<0 || row>=3 || column<0 || column>=3){
				while(row<0 || row>=3 || column<0 || column>=3){
					printf("Please give me a valid box\n");
					printf("Enter the row and the column you want to put X\n");
					scanf("%d %d",&row,&column);
				}
			}
			if(board[row][column]==computer || board[row][column]==player){
				while(board[row][column]==computer || board[row][column]==player){
					printf("Please give me a box that is free\n");
					printf("Enter the row and the column you want to put X\n");
					scanf("%d %d",&row,&column);
				}
			}
			board[row][column]=player;
			if(check_win(board,player)==1){
				print_board(board);
				printf("You won\n");
				return 0;
			}
			moves=moves-1;
		}
	}
}
