#include <stdio.h>

int check_win(int** board,int turn){    
	int i,j,k,free=0,flag_turn=0;

	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(board[i][j]==turn)
				flag_turn+=1;
			if(flag_turn==3)
				return 1;
		}
		flag_turn=0;
	}

	for(j=0;j<3;j++){
		for(i=0;i<3;i++){
			if(board[i][j]==turn)
				flag_turn+=1;
			if(flag_turn==3)
				return 1;		
		}
		flag_turn=0;
	}	

	for(i=0,j=0;(i<3 && j<3);i++,j++){
			if(board[i][j]==turn){
				flag_turn+=1;
			}
			if(flag_turn==3){
				return 1;
			}
	}
	flag_turn=0;
    
    for(i=2,j=0;(i>=0 && j<3);i=i-1,j=j+1){
			if(board[i][j]==turn){
				flag_turn+=1;
			}
			if(flag_turn==3){
				return 1;
			}
    }

	return 0;
}