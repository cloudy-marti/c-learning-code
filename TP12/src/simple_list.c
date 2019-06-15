#include <stdio.h>

#include "../headers/simple_list_manager.h"

int main(int argc, char** argv)
{
	if(argc < 2)
	{
		printf("file missing ...\n");
		return 0;
	}

	List list = parse_file(argv[1]);
	print_list(list);

	int size = get_size_of_list_opti(list);

	free_list(list);

	printf("\nNumber of different words : %d\n", size);
	return 1;
}