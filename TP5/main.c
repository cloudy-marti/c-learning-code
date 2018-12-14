#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function declaration */
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

/* exercice 5 from tp3 for testing */
void bubbleSort(int* tab, int size);

/* An empty main to test the compilation of the allocation and free
functions. */
int main(int argc, char* argv[])
{
    int* array;
    array = fill_array();
    int size = array_size(array);
    printf("the size of your array = %d\n", size);
    print_array(array);

    int arrSize = size;

    int* sameArray;
    sameArray = copy_array(array);
    size = array_size(sameArray);
    printf("\ncopying array ...\n");
    printf("the size of your new array = %d\n", size);
    print_array(sameArray);

    int test;
    test = are_arrays_equal(array, sameArray);

    if(test == 1)
    {
        printf("arrays are equal\n");
    }else{
        printf("arrays are NOT equal\n");
    }

    int* randArray;
    randArray = random_array(size, 50);
    int randSize = array_size(randArray);
    printf("the size of your array = %d\n", randSize);
    print_array(randArray);

    test = are_arrays_equal(array, randArray);

    if(test == 1)
    {
        printf("arrays are equal\n");
    }else{
        printf("arrays are NOT equal\n");
    }

    int* concatArray;
    concatArray = concat_array(array, randArray);
    size = array_size(concatArray);
    printf("the size of your array = %d\n", size);
    print_array(concatArray);

    printf("sorting arrays ...\n");
    bubbleSort(array, arrSize);
    print_array(array);
    bubbleSort(randArray, randSize);
    print_array(randArray);

    int* mergedArr = merge_sorted_arrays(array, randArray);
    print_array(mergedArr);

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
    counter = 0;

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
    int i;

    for(i = 0; first[i] != -1; i++)
    {
        if(first[i] != second[i])
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

    newArray[size] = -1;

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

    array[size] = -1;

    return array;
}

int* random_array(int size, int max_entry)
{
	int i, nb;

	int* randArray;
	randArray = allocate_integer_array(size);

	srand(time(NULL));

	for(i = 0; i < size; i++)
	{
		nb = rand()%max_entry;
		randArray[i] = nb;
	}

	randArray[size] = -1;

	return randArray;
}

int* concat_array(int* first, int* second)
{
	int i, firstSize, secondSize, totalSize;
	int* newArray;

	firstSize = array_size(first);
	secondSize = array_size(second);

	totalSize = (firstSize + secondSize);

	newArray = allocate_integer_array(totalSize);

	for(i = 0; i <= totalSize; i++)
	{
		if(i < firstSize)
		{
			newArray[i] = first[i];
		}else
		{
			newArray[i] = second[i-firstSize];
		}
	}

	newArray[totalSize] = -1;

	return newArray;
}

/* Exercise 3 */
int* merge_sorted_arrays(int* first, int* second)
{
    int* newArray;
    int size = array_size(first) + array_size(second);
    printf("size = %d\n", size);

    newArray = allocate_integer_array(size);

    int i;

    for(i = 0; i < size; i++)
    {
        if(first[i] == second[i] || first[i] < second[i])
        {
            newArray[i] = first[i];
            newArray[i+1] = second[i];
        }else
        {
            newArray[i] = second[i];
            newArray[i+1] = first[i];
        }
        /*for(j = 0; j < size; j+=2)
        {
            if(first[i] == second[i])
            {
                newArray[j] = first[i];
                newArray[j+1] = second[i];
            }else if(first[i] < second[i])
            {
                newArray[j] = first[i];
                newArray[j+1] = second[i];
            }else
            {
                newArray[j] = second[i];
                newArray[j+1] = first[i];
            }
        }*/
    }

    newArray[size] = -1;

    return newArray;
}

/*int* merge_sorted_arrays_recursive(int* first, int* second)
{
    int* newArray;
    int size = array_size(first) + array_size(second) - 1;

    
    entrée ː deux tableaux triés A et B
    sortie : un tableau trié qui contient exactement les éléments des tableaux A et B
    fonction fusion(A[1, …, a], B[1, …, b])
      si A est le tableau vide
              renvoyer B
      si B est le tableau vide
              renvoyer A
      si A[1] ≤ B[1]
              renvoyer A[1] :: fusion(A[2, …, a], B)
      sinon
              renvoyer B[1] :: fusion(A, B[2, …, b])
    

    if(first[1] <= second[1])
    {
        newArray[]
        return merge_sorted_arrays_recursive(first+1, second);
    }else
    {
        return merge_sorted_arrays_recursive(first, second+1);
    }
}*/

void split_arrays(int* array, int** first, int** second)
{
    int size, firstSize, secondSize;

    size = array_size(array);
    firstSize = size / 2;
    secondSize = size - firstSize;

    *first = allocate_integer_array(firstSize);
    *second = allocate_integer_array(secondSize);

    int i, j;

    for(i = 0; i < firstSize; i++)
    {
        *first[i] = array[i];
    }

    for(j = secondSize; j < size; j++)
    {
        *second[i] = array[j];
    }
}

int* merge_sort(int* array)
{
    return 0;   
}

void bubbleSort(int* tab, int size)
{
    int i, j, tmp, oriSize;
    oriSize = size;

    for(j = 1; j < oriSize; j++)
    {
        for(i = 0; i < size-1; i++)
        {
            if(tab[i] > tab[i+1])
            {
                tmp = tab[i];
                tab[i] = tab[i+1];
                tab[i+1] = tmp;
            }
        }
        size--;
    }
}