#include <stdio.h>

#include "../headers/hash_manager.h"

int main(int argc, char** argv)
{
	if(argc < 2)
	{
		printf("file missing ...\n");
		return 0;
	}

	HashTable* hashTable = parse_file_hash_table(argv[1]);
	print_hashTable(hashTable);

	int size = get_size_of_hashtable(hashTable);

	free_hashTable(hashTable);

	printf("\nNumber of different words : %d\n", size);

	return 1;
}