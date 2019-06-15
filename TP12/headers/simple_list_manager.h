#ifndef __SIMPLE_LIST_MANAGER_H__
#define __SIMPLE_LIST_MANAGER_H__

typedef struct _node
{
	char* word;
	int size;
	struct _node* next;
} 
Node, *List;

Node* create_node(char* word);
List insert_node(List list, char* word);

List parse_file(const char* pathToFile);

void print_list(List list);

int get_size_of_list(List list);
int get_size_of_list_opti(List list);

int is_word_in_list(char* word, List list);
int is_word_in_list_rec(char* word, List list);

char* find_word(char* word, List list);

void free_list(List list);

#endif