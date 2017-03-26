#include <stdio.h>



void print_board(int** board){
	int i,j;
	printf(" 0 1 2\n");
	for(i=0;i<3;i++){
		printf("%d",i);
		for(j=0;j<3;j++){
			if(board[i][j]=='O')
				printf("O");
			if(board[i][j]=='X')
				printf("X");
			if(board[i][j]!='O' && board[i][j]!='X')
				printf(" ");
			printf("|");
		}
		printf(" %d\n",i);
	}
	printf(" 0 1 2\n");
}