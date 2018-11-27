#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "stack.h"

void empty(void);

int main(int argc, char* argv[]){
  
    printf("Initializing stack program ...\n");

    stack_init();

    int n, i;
    printf("Please enter an integer value and finish with -1 ...\n");

    while(n != -1)
    {
        scanf("%d", &n);
        stack_push(n);
    }

    empty();

    for(i = stack_size(); i >= 0; i--)
    {
        printf("i = %d\nstack size = %d\n", i, stack_size());
        stack_pop();
    }

    empty();

    return 0;
}

void empty(void)
{
    int empty = stack_is_empty();
    if(empty == 1)
    {
        printf("your stack is empty.\n");
    }else{
        printf("your stack is not empty ; its size is %d\n", stack_size());
        printf("last value is %d\n", stack_top());
    }
}