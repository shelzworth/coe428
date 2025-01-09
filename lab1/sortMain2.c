#include <stdio.h>
#include <stdlib.h>
#include "mySort.h"

int main(int argc, char * argv[])
{
    int data[10000]; 
    int i, nDataItems;
    nDataItems = argc;

    if(argc == 1)
        { 
        nDataItems = 4;
        data[0] = 10;
        data[1] = 230;
        data[2] = -130;
        data[3] = 10; 
    }
    else if(argc > 1)
    {
        for(int j = 0; j < argc; j++)
        {
            data[j] = atoi(argv[j]);
        }
    }

    mySort(data, nDataItems);

    for(i = 0; i < nDataItems; i++)
        {
            printf("%d \n", data[i]);
        }
    exit(0);
}