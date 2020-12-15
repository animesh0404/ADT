/*---------------------------
//Author:     Animesh Kahara
//Program:    Array ADT
//All rights reserved, Copyright 2020
*/

#include<stdio.h>
#include "ArrayADT.h"


//Driver Code
int main()
{
    struct Array arr = {{2,4,6,7,8},5,10};

    printf("\nAppending 34 at the end");
    Append(&arr,34);
    printf("\nAfter Appending");
    Display(arr);

    printf("\nInserting 21 at index 2");
    Insert(&arr,2,21);
    Display(arr);

    printf("\nDeleting key at index 2");
    printf("\nElement deleted: %d",Delete(&arr,2));
    printf("\nAfter Deletion:");
    Display(arr);

    printf("\nRight Rotate array:");
    RRotate(&arr);
    Display(arr);

    return 0;
}



