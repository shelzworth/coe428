#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern int pop();
extern void push(int);
extern int isEmpty();
extern int heapDelete();
extern void addHeap(int);
extern int heapSize();
extern void Bigint(int [], int, int);
extern void fullMaxHeapify();
extern void heapSortPushStack();
extern void printNode(int, int); 

int main(int argc, char * argv[])
{
  int val;
  printf("enter an input\n");
  
  if(scanf("%d", &val) != 1){
	  fprintf(stderr, "enter some numbers");
	  exit(1);
  }
  
  while(val != EOF && val != 1){
	  addHeap(val);
	  
	    if(scanf("%d", &val) != 1){
	  fprintf(stderr, "enter some numbers");
	  exit(1);
  }
}

fullMaxHeapify();
printNode(heapSize(),0);
printf("\n");

printf("Descending: \n");
heapSortPushStack();
printf("Popped:\n");
for(int i = 0; i< heapSize(); i++){
	printf("%d\n", pop());
}

exit(0);
}