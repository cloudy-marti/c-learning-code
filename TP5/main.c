#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "headers/exo0.h"
#include "headers/exo1.h"
#include "headers/exo2.h"
#include "headers/exo3.h"

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