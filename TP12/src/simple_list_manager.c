#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/simple_list_manager.h"

Node* create_node(char* word)
{
	Node* node = (Node*)malloc(sizeof(Node));
	
	node->word = (char*)malloc((strlen(word)+1)*sizeof(char));
	node->word = strcpy(node->word, word);

	node->size = 1;
	node->next = NULL;

	return node;
}

List insert_node(List list, char* word)
{
	Node* newNode = create_node(word);

	newNode->next = list;

	if(list != NULL)
	{
		newNode->size += list->size;
	}

	return newNode;
}

int get_size_of_list(List list)
{
	if(list == NULL)
	{
		return 0;
	}

	return 1 + get_size_of_list(list->next);
}

int get_size_of_list_opti(List list)
{
	if(list == NULL)
	{
		return 0;
	}

	return list->size;
}

int is_word_in_list(char* word, List list)
{
	if(list == NULL)
	{
		return 0;
	}

	Node* pointer = list;

	while(pointer != NULL)
	{
		if(strcmp(word, pointer->word) == 0)
		{
			return 1;
		}

		pointer = pointer->next;
	}

	return 0;
}

int is_word_in_list_rec(char* word, List list)
{
	if(list == NULL)
	{
		return 0;
	}

	if(strcmp(word, list->word) == 0)
	{
		return 1;
	}

	return is_word_in_list_rec(word, list->next);
}

char* find_word(char* word, List list)
{
	if(list == NULL)
	{
		return NULL;
	}

	if(strcmp(word, list->word) == 0)
	{
		return list->word;
	}

	return find_word(word, list->next);
}

List parse_file(const char* pathToFile)
{
	FILE* file;
	file = fopen(pathToFile, "r");

	if(file == NULL)
	{
		fprintf(stderr, "File \"%s\" not found ...\n", pathToFile);
		return NULL;
	}

	char input[64];

	List list = NULL;

	while(1)
	{
		if(fscanf(file, "%s", input) == EOF)
		{
			break;
		}
		
		if(!is_word_in_list(input, list))
		{
			list = insert_node(list, input);
		}
	}

	free(file);

	return list;
}

void print_list(List list)
{
	if(list == NULL)
	{
		printf("\n");
		return;
	}

	printf("[%s|", list->word);

	if(list->next != NULL)
	{
		printf("·]->");
	}
	else
	{
		printf("/]\n");
	}

	print_list(list->next);
}

void free_list(List list)
{
	if(list == NULL)
	{
		return;
	}

	free_list(list->next);
	
	free(list->word);
	free(list);
}