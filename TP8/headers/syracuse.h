#ifndef __SYRACUSE_H
#define __SYRACUSE_H

void print_syracuse(long unsigned int nb);
long unsigned int fly_syracuse(long unsigned int nb);
long unsigned int max_syracuse(long unsigned int nb);
long int opti_fly_syracuse(long int* cache, long int nb);
long int* initialize_array(long int size);
void fill_array(long int* array, long int size);

#endif