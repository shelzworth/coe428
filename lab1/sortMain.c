#include <stdio.h>
#include <stdlib.h>
#include "mySort.h"

int main(int argc, char * argv[])
{
    int data[10000]; 
    int i, nDataItems;
    nDataItems = 4;
    data[0] = 10;
    data[1] = 230;
    data[2] = -130;
    data[3] = 10; 

    mySort(data, nDataItems);
    for(i = 0; i < nDataItems; i++)
    {
        printf("%d\n", data[i]);
    }
    exit(0);
}
