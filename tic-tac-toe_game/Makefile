tic-tac-toe: tic-tac-toe.o check_win.o minimax_way.o print_board.o
	gcc tic-tac-toe.o check_win.o minimax_way.o print_board.o -o tic-tac-toe

tic-tac-toe.o: tic-tac-toe.c
	gcc -c tic-tac-toe.c  

check_win.o: check_win.c
	gcc -c check_win.c

minimax_way.o: minimax_way.c
	gcc -c minimax_way.c

print_board.o: print_board.c
	gcc -c print_board.c

.PHONY: clean

clean:
	rm -f tic-tac-toe.o check_win.o minimax_way.o print_board.o tic-tac-toe
