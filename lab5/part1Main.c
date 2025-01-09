#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
extern char * pop();
extern void push(char *);
extern int isEmpty();
extern void allocate_mem(char ** stack);

int main(int argc, char * argv[])
{
  char ch; 
  char chNext;
  char * topWord = malloc(10 * sizeof(char));; 
  char * word = malloc(10 * sizeof(char));; 

  while ((ch = getchar()) != EOF){

    if(ch == '\n') 
      break;
    if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/')) 
      continue;
    
    if(ch == '<')
    { 
      chNext = getchar();
      if(chNext == '/')
      { 
        int a = 0;
        chNext = getchar();
        do{
          word[a] = chNext;
          a++;
          chNext = getchar();
        }while(chNext != '>');

        topWord = pop();
        if (strcmp(word, topWord) != 0) 
        { 
          fprintf(stderr, "%s\n", word);
          fprintf(stderr, "%s\n", topWord);
          fprintf(stderr, "Incorrect.\n");
          exit(1); 
        }
        fprintf(stdout, "%s\n", word);

      }
      else
      { 
        
      int a = 0;
        do
        {
          word[a] = chNext;
          a++;
          chNext = getchar();
          
        }
        while(chNext != '>');
        push(word);
      }

    for (int i = 0; i < 10; i++) 
      word[i] = '\0';
    
    }
    
  }

  if (isEmpty())
  { 
        fprintf(stdout, "Valid \n");
        exit(0); 
    } else 
    {
        fprintf (stderr, "Invalid \n");
        exit(1);
    }
  return 0;
}