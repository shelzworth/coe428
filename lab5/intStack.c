#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
static int top = 0;
static int stack[100];

int pop()
{
	if(top != 0)
	{
		top = top - 1; 
		return stack[top];
	}
	
	else
	{
		fprintf(stderr,"Stack is empty");
		exit(1);
	}
	
}

/**
 *  push(thing2push) adds the "thing2push" to the top of the stack.
 *
 *  If there is no more space available on the Stack, an error
 *  message is printed to stderr.
 */
void push(int thing2push)
{
	if( top == 100)
	{
		fprintf(stderr,"Stack is full.");
	}
	else
	{
		top++;
		stack[top - 1] = thing2push;
	}
}

/**
 * isEmpty() returns a non-zero integer (not necessarily 1) if the
 * stack is empty; otherwise, it returns 0 (zero).
 *
 */
int isEmpty()
{
	if(top == 0)
	{
		return 1;
	}
	else
	{
	return 0;
	}
}
