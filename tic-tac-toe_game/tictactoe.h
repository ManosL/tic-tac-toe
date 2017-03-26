#ifndef TICTACTOE_H_INCLUDED
#define TICTACTOE_H_INCLUDED

struct free_boxes{
	int row;
	int column;
};

void print_board(int**);
void computer_turn(int,int,int**);
int check_win(int**,int);
int minimax(int **,int,int,int,int);

#endif // TICTACTOE_H_INCLUDED
