#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

static Stack stack;

/* Initialize correctly the stack. */
void stack_init(void)
{
	stack.size = 0;
}

/* Returns the current size of the stack. */
int stack_size(void)
{
	return stack.size;
}

/* Returns 1 if the stack is empty, returns 0 otherwise. */
int stack_is_empty(void)
{
	if(stack.size == 0)
	{
		return 1;
	}else{
		return 0;
	}
}

/* Returns the element at the top of the stack. */
int stack_top(void)
{
	return stack.values[stack.size];
}

/* Pops the element at the top of the stack and returns it. */
int stack_pop(void)
{
	/* save value into val */
	int val = stack.values[stack.size - 1];

	stack.size -= 1;

	return val;
}

/* Pushes a given integer `n` at the top of the stack. */
void stack_push(int n)
{
	if(stack.size == MAX_SIZE){
		printf("stack overflow ... cannot add anymore values\n");
		return;
	}else{
		stack.values[stack.size] = n;
		stack.size += 1;
	}
}

/* Displays the content of the stack on the standard output. */
void stack_display(void)
{
	int i;

	for(i = stack.size; i >= 0; i--)
	{
		printf("value[%d] = %d\n", i, stack.values[i]);
	}
}

/* Returns the element at index `index` inside the stack. The user is
   responsible of the use of this function. The answers may be not
   relevant if a call is done outside the current size of the
   stack. */
int stack_get_element(int index)
{
	if(index > stack.size){
		printf("stack overflow\n");
		return -1;
	}else{
		return stack.values[index];
	}
}