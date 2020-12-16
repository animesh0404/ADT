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
    struct Array arr = {{-6,3,-8,10,5,-7,-9,12,-4,2},10,10};

//    printf("\nAppending 34 at the end");
//    Append(&arr,34);
//    printf("\nAfter Appending");
    Display(arr);
//
//    printf("\nInserting 21 at index 2");
//    Insert(&arr,2,21);
//    Display(arr);

//    printf("\nDeleting key at index 2");
//    printf("\nElement deleted: %d",Delete(&arr,2));
//    printf("\nAfter Deletion:");
//    Display(arr);
//
//    printf("\nRight Rotate array:");
//    RRotate(&arr);
//    Display(arr);

//     InsertinSortedArray(&arr,3);
//     Display(arr);
//
//     isSorted(arr) ? printf("\nSorted") : printf("\n Not Sorted");

     Rearrange(&arr);
     Display(arr);

    return 0;
}


