/*AI source file*/
#include <stdio.h>
#include <stdlib.h>
#include "tictactoe.h"

void copy_board(int **board,int **newboard){
	int i,j;

	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			newboard[i][j]=board[i][j];
		}
	}
	return;
}

int minimax(int **board,int turn,int moves,int player,int opponent){
	int **newboard,**bestboard,**worstboard;
	int i,j,k=0,opposite_turn,free_counter=0,cur_result,max_result=-100,min_result=100;
	struct free_boxes *boardoffree;
	int checking;

	if(turn==player) opposite_turn=opponent;
	else if(turn==opponent) opposite_turn=player;

	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(board[i][j]!=player && board[i][j]!=opponent){
				free_counter+=1;
			}
		}
	}
	checking=check_win(board,opposite_turn);
	if(checking==1 && turn==opponent){
		return -10;
	}

	if(checking==1 && turn==player){
		return 10;
	}

	if(checking==0 && free_counter==0){
		/*printf("%c\n",opposite_turn);
		print_board(board);    just for testing
		printf("draw\n");*/
		return 0;
	}

	bestboard=malloc(3*sizeof(int*));
	worstboard=malloc(3*sizeof(int*));
	for(i=0;i<3;i++){
		bestboard[i]=malloc(3*sizeof(int));
		worstboard[i]=malloc(3*sizeof(int));
	}

	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			bestboard[i][j]=-1;
		}
	}

	boardoffree=malloc(free_counter*sizeof(struct free_boxes));
	if(boardoffree==NULL){
		printf("Memory Error\n");
		return -1000;
	}

	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(board[i][j]!='O' && board[i][j]!='X'){
				boardoffree[k].row=i;
				boardoffree[k].column=j;
				k++;
			}
		}
	}
	k=0;

	for(k=0;k<free_counter;k++){
		newboard=malloc(3*sizeof(int*));
		for(i=0;i<3;i++){
			newboard[i]=malloc(3*sizeof(int));
		}

		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				newboard[i][j]=-1;
			}
		}
		copy_board(board,newboard);
		newboard[boardoffree[k].row][boardoffree[k].column]=turn;
		cur_result=minimax(newboard,opposite_turn,moves+1,player,opponent);
		if(cur_result<min_result && turn==player){
			min_result=cur_result;
			copy_board(newboard,worstboard);
			if(cur_result==-10) break; /*something like alpha-beta pruning, because if i find the best i will not find better*/
		}
		else
		if(cur_result>max_result && turn==opponent){
			max_result=cur_result;
			copy_board(newboard,bestboard);
			if(cur_result== 10) break; /*something like alpha-beta pruning*/
		}							   /*because if I find the best i will not find better*/
		for(i=0;i<3;i++){
			free(newboard[i]);
		}
		free(newboard);
	}
   if(moves==0 && turn==opponent)
	copy_board(bestboard,board);
   if(moves==0 && turn==player)
   	copy_board(worstboard,board);
	for(i=0;i<3;i++){
		free(bestboard[i]);
		free(worstboard[i]);
	}
	free(bestboard);
	free(worstboard);

	if(turn==player)
		return min_result;
	
	if(turn==opponent)
		return max_result;
}