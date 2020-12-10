/*---------------------------
//Author:     Animesh Kahara
//Program:    Array ADT
//All rights reserved, Copyright 2020
*/

#include<stdio.h>
#include<stdlib.h>


//Declrations
struct Array{
    int A[10];
    int length;
    int szie;
};

void intSwap(int *,int *);
void Display(struct Array);
void Append(struct Array *,int);
void Insert(struct Array *,int,int);
int  Delete(struct Array *,int);
int  LinearSearch(struct Array,int);
int  LinearSearchv1(struct Array *,int);
int  LinearSearchv2(struct Array *,int);
int  BinarySearch(struct Array, int);
int  RBinSearch(struct Array,int,int,int);
int  Get(struct Array ,int);
void Set(struct Array *,int,int);
int  Max(struct Array);
int    Min(struct Array);
int    Sum(struct Array);
float  Avg(struct Array);
void Reverse(struct Array *);
void Reverse2(struct Array *);


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

    printf("\nGetting/Accessing value at index 3: %d",Get(arr,3));

    printf("\nSetting a value 99 at index 2\n");
    Set(&arr,2,99);
    Display(arr);

    printf("\nMaximum value in array is: %d", Max(arr));
    printf("\nMinimum value in array is: %d", Min(arr));
    printf("\nAvg. of all the elements: %f", Avg(arr));

    printf("\nReversing the array:");
    Reverse2(&arr);
    Display(arr);

    return 0;
}


//All Functions

//Function for traversing/Displaying the complete array.
void Display(struct Array a)
{
    int i;
    for(i=0;i<a.length;i++)
        printf("\n%d",a.A[i]);\
    printf("\n");
}

//Function to Append a key at the End.
void Append(struct Array *a,int x)
{
    if(a->length < a->szie)
    {
        a->A[ a->length++] = x;
        return;
    }
}

//Function to Insert a key at an valid index (0-length)
void Insert(struct Array *a,int index,int x)
{
    int i;
    if(index >=0 && index <= a->length)
    {
        for(i=a->length; i>index; i--)
            a->A[i] = a->A[i-1];
        a->A[index] = x;
        a->length++;
        return;
    }
}

//Function to Delete a key from any given valid index.
int Delete(struct Array *arr,int index)
{
 int x = 0;
 int i;
 if(index >= 0 &&  index < arr->length)
 {
  x  = arr -> A[index];

  for(i=index; i < arr->length-1;i++)
       arr->A[i] = arr->A[i+1];
  arr->length--;
  return x;
 }
 return 0;
}


//Function's to perform Searching in Linear Time
int LinearSearch(struct Array arr,int key)
{
    int i;
    for(i=0; i<arr.length; i++)
    {
        if(key==arr.A[i])
            return i;
    }
    return -1;
}

int LinearSearchv1(struct Array *arr,int key)
{
    //Improvement in search using Transposition
    //Gradually increases/decreases search time based on
    //frequency of the searched key.

    int i;
    for(i=0; i<arr->length; i++)
    {
        if(key==arr->A[i])
        {
         intSwap(&arr->A[i], &arr->A[i-1]);
         return i-1;
        }
    }
    return -1;
}

int LinearSearchv2(struct Array *arr,int key)
{
    //Improvement in search using Move to Head/Front
    //Constant time taken to return last searched key
    int i;
    for(i=0; i<arr->length; i++)
    {
        if(key==arr->A[i])
        {
         intSwap(&arr->A[i], &arr->A[0]);
         return 0;
        }
    }
    return -1;
}


//Function's to search using log(n) time
int BinarySearch(struct Array arr,int key)
{
    int l,mid,h;
    l = 0;
    h = arr.length - 1;
    while(l<=h)
    {
        mid = (l+h)/2;
        if(key == arr.A[mid])
            return mid;
        else if(key < arr.A[mid])
            h = mid -1;
        else
            l = mid +1;
    }
    return -1;
}

int RBinSearch(struct Array arr,int l,int h,int key)
{
    int mid;
    while(l<=h)
    {
        mid = (l+h)/2;
        if(key == arr.A[mid])
            return mid;
        else if(key < arr.A[mid])
            return RBinSearch(arr,l,mid-1,key);
        else
            return RBinSearch(arr,mid+1,h,key);
    }
    return -1;
}

//Function to swap any two integer values.
void intSwap(int *A,int *B)
{
    int temp = *A;
    *A = *B;
    *B = temp;
}

//Function to get a value from any valid index
int Get(struct Array a,int index)
{
    if(index>=0 && index<a.length)
        return a.A[index];
}

//Function to Set/Replace a value from any valid index
void Set(struct Array *a,int index,int x)
{
    if(index>=0 && index < a->length)
        a->A[index] = x;
}

//Function to return the maximum value
int Max(struct Array a)
{
    int i,mx = a.A[0];

    for(i=1;i<a.length;i++)
    {
        if(a.A[i] > mx)
            mx = a.A[i];
    }
    return mx;
}

//Function to return the minimum value
int Min(struct Array a)
{
    int i,mn = a.A[0];

    for(i=1;i<a.length;i++)
    {
        if(a.A[i] < mn)
            mn = a.A[i];
    }
    return mn;
}

//Function to return sum of all the elements
int Sum(struct Array a)
{
    int i,total = 0;
    for(i=0;i<a.length;i++)
        total += a.A[i];
    return total;
}

//Function to return avg values
float Avg(struct Array a)
{
    return (float) Sum(a) / a.length;
}

//Function to reverse array using aux. array.
void Reverse(struct Array *a)
{
    int *B;
    int i,j;

    B = (int *) malloc(a->length * sizeof(int));

    for(i=a->length-1, j=0; i>=0; i--,j++)
        B[j] = a->A[i];

    for(i=0;i<a->length;i++)
        a->A[i]=B[i];
}


//Function to reverse array.
void Reverse2(struct Array *a)
{
    int i,j;
    for(j=a->length-1, i=0; i < (a->length)/2 ; i++,j--)
        intSwap( &a->A[j], &a->A[i]);
}

