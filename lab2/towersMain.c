#include <stdio.h>
#include <stdlib.h>
#include "towers.h"

int main(int argc, char ** argv)
{
    int check, n = 3, from = 1, dest = 2;
   if (argc == 1)
   {

   }
   else if (argc == 2)
   {
        n = atoi(argv[1]);
   }
   else if (argc == 4) 
   {
        n = atoi(argv[1]);
        from = atoi(argv[2]);
        check = atoi(argv[3]);

        if(check != from)
        {
            dest = check;

            if(from < 1 || from > 3)
            { 
                fprintf(stderr, "Invalid input for , please choose between towers 1, 2 or 3.");
                 exit(0);
            }
            else if(dest < 1 || dest > 3)
            { 
                fprintf(stderr, "Invalid input for , please choose between towers 1, 2 or 3.");
                 exit(0);
            }
        }
        else
        {
            fprintf(stderr, "Invalid input, you are moving to the same tower you are taking from.");
            exit(0);
        }
    }
    else
    {
        fprintf(stderr, "Invalid input, too many or too little arguments");
        exit(0);
    }
    towers(n, from, dest);
    exit(0);
}

