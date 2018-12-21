#include <stdio.h>

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