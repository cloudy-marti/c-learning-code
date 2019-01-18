#ifndef __ALLOC_2D_H
#define __ALLOC_2D_H

char** initialize_2D_array(int sizeX, int sizeY);
void fill_2D_array(char** array, int sizeX, int sizeY);
void print_2D_array(char** array, int sizeX, int sizeY);
void free_2D_array(char** array, int sizeX, int sizeY);

#endif