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

    printf("new arrays :\n");
    split_arrays(mergedArr, &randArray, &sameArray);
    print_array(randArray);
    print_array(sameArray);

    printf("\nA random array of lenght 20 whose entries are lower than 100 : \n\n");
    int *newnewRand, *res;
    newnewRand = random_array(20, 100);
    print_array(newnewRand);

    printf("\nusing a merge sort, we get :\n");

    res = merge_sort(newnewRand);
    print_array(res);

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
    int* mergedArr;
    int firstSize, secondSize, totalSize, i, j, k;

    j = k = 0;

    firstSize = array_size(first);
    secondSize = array_size(second);
    totalSize = firstSize + secondSize;

    mergedArr = allocate_integer_array(totalSize);

    if(first == NULL)
    {
        return second;
    }
    else if(second == NULL)
    {
        return first;
    }
    else if(first == NULL || second == NULL)
    {
        return NULL;
    }
    else
    {
        for (i = 0; i < totalSize; i++)
        {
            if(j < firstSize && k < secondSize)
            {
                if(first[j] < second[k])
                {
                    mergedArr[i] = first[j];
                    j++;
                }
                else
                {
                    mergedArr[i] = second[k];
                    k++;
                }
            }
            else if(j == firstSize)
            {
                mergedArr[i] = second[k];
                k++;
            }
            else
            {
                mergedArr[i] = first[j];
                j++;
            }
        }
    }
    mergedArr[totalSize] = -1;

    return mergedArr;
}

void split_arrays(int* array, int** first, int** second)
{
    int size, firstSize, secondSize;

    size = array_size(array);
    firstSize = size / 2;
    secondSize = size - firstSize;

    *first = allocate_integer_array(firstSize);
    *second = allocate_integer_array(secondSize);

    int i;

    for(i = 0; i < size; i++)
    {
        if(i < firstSize)
        {
            (*first)[i] = array[i];
        }
        else
        {
            (*second)[i - firstSize] = array[i];
        }
    }

    (*first)[firstSize] = -1;
    (*second)[secondSize] = -1;
}

int* merge_sort(int *array)
{
    int *newArray;
    int *first, *second, *tmpFirst, *tmpSecond;
    int size = array_size(array);
    
    if(array == NULL)
    {
        return NULL;
    }
    else if(size == 1)
    {
        newArray = allocate_integer_array(size);

        newArray[0] = array[0];
        newArray[size] = -1;

        return newArray;
    }
    else
    {
        printf("\nsplit array in two part :\n");
        split_arrays(array, &first, &second);
        print_array(array);
        print_array(first);
        print_array(second);

        tmpFirst = merge_sort(first);
        tmpSecond = merge_sort(second);

        free(first);
        free(second);

        printf("\nmerge the two following ones :\n");
        newArray = merge_sorted_arrays(tmpFirst, tmpSecond);
        print_array(tmpFirst);
        print_array(tmpSecond);
    }

    return newArray;   
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