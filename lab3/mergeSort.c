#include "mySort.h"
#include "metrics.h"

void merge(int array[], unsigned int first, unsigned int mid, unsigned int last) 
{
    unsigned int i, j, k;
    unsigned int num1 = mid - first + 1;
    unsigned int num2 = last - mid;

    int leftArray[num1];
    int rightArray[num2];

    for (i = 0; i < num1; i++)
        myCopy(&array[first + i], &leftArray[i]);
    for (j = 0; j < num2; j++)
        myCopy(&array[mid + 1 + j], &rightArray[j]);

    i = 0;
    j = 0; 
    k = first; 
    while (i < num1 && j < num2) 
    {
        if (myCompare(leftArray[i], rightArray[j]) <= 0) 
        {
            myCopy(&leftArray[i], &array[k]);
            i++;
        } else 
        {
            myCopy(&rightArray[j], &array[k]);
            j++;
        }
        k++;
    }


    while (i < num1) 
    {
        myCopy(&leftArray[i], &array[k]);
        i++;
        k++;
    }

    while (j < num2) 
    {
        myCopy(&rightArray[j], &array[k]);
        j++;
        k++;
    }
}

void mySort(int array[], unsigned int first, unsigned int last) 
{
    if (first < last) 
    {
        unsigned int mid = first + (last - first) / 2;
        mySort(array, first, mid);
        mySort(array, mid + 1, last);
        merge(array, first, mid, last);
    }
}
