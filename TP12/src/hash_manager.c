#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/simple_list_manager.h"
#include "../headers/hash_manager.h"

HashTable* create_hashtable()
{
	HashTable* hashTable = (HashTable*)malloc(sizeof(HashTable));

	int index = 0;

	for(index = 0; index < NB_PACK; ++index)
	{
		hashTable->hashTable[index] = NULL;
	}

	hashTable->size = 0;

	return hashTable;
}

int get_size_of_hashtable(HashTable* hashTable)
{
	return hashTable->size;
}

HashTable* parse_file_hash_table(const char* pathToFile)
{
	FILE* file;
	file = fopen(pathToFile, "r");
	
	if(file == NULL)
	{
		fprintf(stderr, "File \"%s\" not found ...\n", pathToFile);
		return NULL;
	}

	HashTable* hashTable = create_hashtable();

	char input[64];

	while(1)
	{
		if(fscanf(file, "%s", input) == EOF)
		{
			break;
		}

		if(!is_word_in_hash_table(hashTable->hashTable, input))
		{
			int hash = get_hash(input);

			hashTable->hashTable[hash] = insert_node(hashTable->hashTable[hash], input);
			hashTable->size += 1;
		}
	}

	return hashTable;
}

int is_word_in_hash_table(List* table, char* word)
{
	if(table == NULL)
	{
		return 0;
	}

	int hash = get_hash(word);

	List tmpList = table[hash];

	if(tmpList == NULL)
	{
		return 0;
	}
	
	return is_word_in_list(word, table[hash]);
}

int get_hash(char* word)
{
	int hash = 0;

	int size = strlen(word);
	int index;

	for(index = 0; index < size; ++index)
	{
		hash += (index + 1) * (word[index]);
	}

	if(hash < 0)
	{
		hash -= (hash*2);
	}

	hash %= NB_PACK;

	return hash;
}

void print_hashTable(HashTable* hashTable)
{
	int index;

	for(index = 0; index < NB_PACK; ++index)
	{
		if(hashTable->hashTable[index] != NULL)
		{
			printf("[%d]\t->\t", index);
			print_list(hashTable->hashTable[index]);
		}
	}
}

void free_hashTable(HashTable* hashTable)
{
	int index;

	for(index = 0; index < NB_PACK; ++index)
	{
		free_list(hashTable->hashTable[index]);
	}

	free(hashTable);
}