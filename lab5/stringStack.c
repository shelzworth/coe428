#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int top = 0;
static char * stack[100];
int switch1 = 0;

char *  pop()
{
  char * tempword = malloc(10 * sizeof(char));
  if(top != 0){
    top--;
    strcpy(tempword, stack[top]);
    for (int i = 0; i < 10; i++) 
      stack[top][i] = '\0';
    return tempword;
    
  }
  fprintf(stderr, "stack empty\n");
  exit(1);  
}

void push(char * thing2push)
{
  if(switch1 == 0)
  { 
    allocate_mem(stack);
    switch1++;
  }
  if(top == 100)
    fprintf(stderr, "stack full\n");
  else
  {
    top++;
    strcpy(stack[top - 1], thing2push);
    
  }
}

int isEmpty()
{
  if(top == 0)
    return -1;
  return 0;
}

void allocate_mem(char ** stack) 
{
  for(int i = 0; i < 100; i++) 
  {
    stack[i] = malloc(10 * sizeof(char));
  }
}