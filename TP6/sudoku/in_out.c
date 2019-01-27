#include <stdio.h>

#include "headers/in_out.h"

int fread_board(const char* file, Board board){
	FILE* f;
	int row, column;
	int entry;

	f = fopen(file, "r");
	if (f == NULL)
	{
		fprintf(stderr, "Erreur d'ouverture du fichier %s\n", file);
		return 0;
	}

	for (row=0 ; row<9 ; row++)
	{
		for (column=0 ; column<9 ; column++)
		{
			fscanf(f, "%d", &entry);
			board[row][column] = entry;
		}
	}
	return 1;
}
