#ifndef __ALLOC_ARG_H
#define __ALLOC_ARG_H

int get_size(char* argv);
char** initialize_arg_array(int argc, char** argv);
void fill_arg_array(int argc, char** argv, char** array);
void print_arg_array(int argc, char** argv);
void free_arg_array(int argc, char** argv);

#endif