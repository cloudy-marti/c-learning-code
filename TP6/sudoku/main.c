#include <stdio.h>

#include "sudoku.h"
#include "in_out.h"

int main(int argc, char* argv[]){
	Board sudoku;

	fread_board(argv[1], sudoku);
	print_board(sudoku);

	int tmp = sudoku_solver(sudoku, 0);

	if(tmp == 1)
	{
		print_board(sudoku);
	}
	else
	{
		printf("sudoku could not be solved\n");
		print_board(sudoku);
	}

	return 0;
}
