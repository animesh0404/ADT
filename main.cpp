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
//    struct Array arr1 = {{2,6,10,15,25},10,10};
//    struct Array arr2 = {{3,4,7,18,20},10,10};
//    struct Array *arr3;
  // struct Array arr = {{-6,3,-8,10,5,-7,-9,12,-4,2},10,10};

//    printf("\nAppending 34 at the end");
//    Append(&arr,34);
//    printf("\nAfter Appending");
//    Display(arr);
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
////     isSorted(arr) ? printf("\nSorted") : printf("\n Not Sorted");


//
//    arr3 = Merge(&arr1,&arr2);
//
//    int i;
//    for(i=0;i<arr3->length;i++)
//        printf(" %d ",arr3->A[i]);

        struct Array arr1={{2,9,21,28,35},10,5};
struct Array arr2={{2,3,9,18,28},10,5};
struct Array *arr3;

arr3 = Difference(&arr1,&arr2);
    int i;
    for(i=0;i<arr3->length;i++)
        printf(" %d ",arr3->A[i]);


    return 0;
}


