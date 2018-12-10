#include <stdio.h>
#include <stdlib.h>

/* Funcion declaration */
int* allocate_integer_array(int size);
void free_integer_array(int* tab);

/* Exercise 1 */
int array_size(int* array);
void print_array(int* array);
int are_arrays_equal(int* first, int* second);
int* copy_array(int* array);

/* Exercise 2 */
int* fill_array(void);
int* random_array(int size, int max_entry);
int* concat_array(int* first, int* second);

/* Exercise 3 */
int* merge_sorted_arrays(int* first, int* second);
void split_arrays(int* array, int** first, int** second);
int* merge_sort(int* array);

/* An empty main to test the compilation of the allocation and free
functions. */
int main(int argc, char* argv[])
{
    return 0;
}

/* local function definition */

/* Allocate memory for an array which can contain `size`
integers. The returned C array has memory for an extra last
integer labelling the end of the array. */
int* allocate_integer_array(int size)
{
    int* new_tab;
    new_tab = (int*)malloc((size+1)*sizeof(int));

    if (new_tab == NULL)
    {
        fprintf(stderr, "Memory allocation error\n");
        return NULL;
    }

    return new_tab;
}

/* Free an integer array */
void free_integer_array(int* tab)
{
    free(tab);
}

/* Exercise 1 */
int array_size(int* array)
{
    int i, counter;

    for(i = 0; array[i] != -1; i++)
    {
        counter++;
    }

    return counter;
}

void print_array(int* array)
{
    int i, size;
    size = array_size(array);

    for(i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");
}

int are_arrays_equal(int* first, int* second)
{
    int i, test;

    for(i = 0; first[i] != -1; i++)
    {
        if(first[i] =! second[i])
        {
            return 0;
        }
    }

    return 1;
}

int* copy_array(int* array)
{
    int *newArray;

    int i, size;
    size = array_size(array);

    newArray = allocate_integer_array(size);

    for(i = 0; array[i] != -1; i++)
    {
        newArray[i] = array[i];
    }
    newArray[i+1] = -1;

    return newArray;
}

/* Exercise 2 */
int* fill_array(void)
{
    int *array;
    int nb, size, i;

    printf("Please enter the size of your array ...\n");
    scanf("%d", &size);

    array = allocate_integer_array(size);

    printf("Now enter some numbers ... \n");

    for(i = 0; i < size; i++)
    {
    	scanf("%d", &nb);
    	array[i] = nb;
    }

    array[i+1] = -1;

    return array;
}

int* random_array(int size, int max_entry)
{
	int i, nb;

	int* randArray;
	randArray = allocate_integer_array(size);

	srand(time(null));

	for(i = 0; i < size; i++)
	{
		nb = rand()%max_entry;
		randArray[i] = nb;
	}

	randArray[i+1] = -1;

	return randArray;
}

int* concat_array(int* first, int* second)
{
	int i, firstSize, secondSize, totalSize;
	int* newArray;

	firstSize = array_size(first);
	secondSize = array_size(second);

	totalSize = firstSize + secondSize;

	newArray = allocate_integer_array(totalSize);

	for(i = 0; i < totalSize; i++)
	{
		if(i <= firstSize)
		{
			newArray[i] = first[i];
		}else
		{
			newArray[i] = second[i-firstSize];
		}
	}

	newArray[i+1] = -1;

	return newArray;
}

/* Exercise 3 */
int* merge_sorted_arrays(int* first, int* second)
{

}

void split_arrays(int* array, int** first, int** second)
{

}

int* merge_sort(int* array)
{

}