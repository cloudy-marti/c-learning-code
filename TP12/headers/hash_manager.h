#ifndef __HASH_MANAGER_H
#define __HASH_MANAGER_H

#include "simple_list_manager.h"

#define NB_PACK 4096

typedef struct _hashTable
{
	List hashTable[NB_PACK];
	int size;
}
HashTable;

HashTable* create_hashtable();

int get_size_of_hashtable(HashTable* hashTable);

HashTable* parse_file_hash_table(const char* pathToFile);

int is_word_in_hash_table(List* table, char* word);

int get_hash(char* word);

void print_hashTable(HashTable* hashTable);

void free_hashTable(HashTable* hashTable);

#endif