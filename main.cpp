/*---------------------------
//Author:     Animesh Kahara
//Program:    Array ADT
//All rights reserved, Copyright 2020
*/

#include<stdio.h>
#include<stdlib.h>
#include "StringADT.h"


int main()
{
    struct String name1,name2,na;

    initString(&name1);
    initString(&name2);

    setString(&name1,"Dev");
    setString(&na, "Dev is a learner");

    Reverse(name1,&name2);
    printf("No. of words: %d", countW(na));

    getString(name1);P
    getString(name2);
    return 0;
}

////Driver Code
//int main()
//{
//    struct Array arr1;
//    char ch;
//    int x,index;
//
//    printf("Enter Size of Array: ");
//    scanf("%d",&arr1.szie);
//
//
//    arr1.A = (int *)malloc(arr1.szie*sizeof(int));
//    arr1.length=0;
//
//    do
//    {
//        printf("\n\nMenu\n");
//        printf("1. Insert\n");
//        printf("2. Delete\n");
//        printf("3. Search\n");
//        printf("4. Sum\n");
//        printf("5. Display\n");
//        printf("6. Exit\n");
//
//        printf("enter you choice: ");
//        scanf("%d",&ch);
//
//
//        switch(ch)
//        {
//         case 1:
//            printf("\nEnter (index,value): ");
//            scanf("%d%d",&index,&x);
//            Insert(&arr1,index,x);
//            break;
//
//         case 2:
//            printf("Enter index ");
//            scanf("%d",&index);
//            x=Delete(&arr1,index);
//            printf("Deleted Element is %d\n",x);
//            break;
//
//         case 3:printf("Enter element to search ");
//            scanf("%d",&x);
//            index=LinearSearch(arr1,x);
//            printf("Element index %d",index);
//            break;
//
//         case 4:printf("Sum is %d\n",Sum(arr1));
//            break;
//
//         case 5:
//            Display(arr1);
//            break;
//        }
//    }while(ch != 6);
//    return 0;
//}


