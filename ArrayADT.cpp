#include "ArrayADT.h"
#include "String.h"
#include<iostream>
#include<stdlib.h>

//All Functions

//Default Constructor
Array::Array()
{
    szie = 10;
    length = 0;
    A = new int[szie];
}
//Parameterized Constructor
Array::Array(int sz)
{
    szie = sz;
    length = 0;
    A = new int[szie];
}


//Destructor
Array::~Array()
{
    delete []A;
}

//Function for traversing/Displaying the complete array.
void Array::Display()
{
    int i;
    for(i=0;i<length;i++)
        printf(" %d ",A[i]);
    printf("\n");
}

//Function to Append a key at the End.
void Array::Append(int x)
{
    if(length < szie)
    {
        A[length++] = x;
        return;
    }
}

//Function to Insert a key at an valid index (0-length)
void Array::Insert(int index,int x)
{
    int i;
    if(length== 0)
    {
        A[index] = x;
        length++;
    }

    else if(index >=0 && index <= length)
    {
        for(i=length; i>index; i--)
            A[i] = A[i-1];
        A[index] = x;
        length++;
        return;
    }
}

//Function to Delete a key from any given valid index.
int Array::Delete(int index)
{
 int x = 0;
 int i;
 if(index >= 0 &&  index < length)
 {
  x = A[index];

  for(i=index; i < length-1;i++)
       A[i] = A[i+1];
  length--;
  return x;
 }
 return 0;
}


//Function's to perform Searching in Linear Time
int Array::LinearSearch(int key)
{
    int i;
    for(i=0; i<length; i++)
    {
        if(key==A[i])
            return i;
    }
    return -1;
}

int Array::LinearSearchv1(int key)
{
    //Improvement in search using Transposition
    //Gradually increases/decreases search time based on
    //frequency of the searched key.

    int i;
    for(i=0; i<length; i++)
    {
        if(key==A[i])
        {
         intSwap(A[i],A[i-1]);
         return i-1;
        }
    }
    return -1;
}

int Array::LinearSearchv2(int key)
{
    //Improvement in search using Move to Head/Front
    //Constant time taken to return last searched key
    int i;
    for(i=0; i<length; i++)
    {
        if(key==A[i])
        {
         intSwap(A[i],A[0]);
         return 0;
        }
    }
    return -1;
}


//Function's to search using log(n) time
int Array::BinarySearch(int key)
{
    int l,mid,h;
    l = 0;
    h = length - 1;
    while(l<=h)
    {
        mid = (l+h)/2;
        if(key == A[mid])
            return mid;
        else if(key < A[mid])
            h = mid -1;
        else
            l = mid +1;
    }
    return -1;
}

int Array::RBinSearch(int l,int h,int key)
{
    int mid;
    while(l<=h)
    {
        mid = (l+h)/2;
        if(key == A[mid])
            return mid;
        else if(key < A[mid])
            return RBinSearch(l,mid-1,key);
        else
            return RBinSearch(mid+1,h,key);
    }
    return -1;
}

//Function to swap any two integer values.
void Array::intSwap(int &A,int &B)
{
    int temp = A;
    A = B;
    B = temp;
}

//Function to get a value from any valid index
int Array::Get(int index)
{
    if(index>=0 && index<length)
        return A[index];
}

//Function to Set/Replace a value from any valid index
void Array::Set(int index,int x)
{
    if(index>=0 && index < length)
        A[index] = x;
}

//Function to return the maximum value
int Array::Max()
{
    int i,mx = A[0];

    for(i=1;i<length;i++)
    {
        if(A[i] > mx)
            mx = A[i];
    }
    return mx;
}

//Function to return the minimum value
int Array::Min()
{
    int i,mn = A[0];

    for(i=1;i<length;i++)
    {
        if(A[i] < mn)
            mn = A[i];
    }
    return mn;
}

//Function to return sum of all the elements
int Array::Sum()
{
    int i,total = 0;
    for(i=0;i<length;i++)
        total += A[i];
    return total;
}
//
////Function to return avg values
float Array::Avg()
{
    return (float) ( (this->Sum()) / length);
}

//Function to reverse array using aux. array.
void Array::Reverse()
{
    int *B;
    int i,j;

    B = new int[length];

    for(i=length-1, j=0; i>=0; i--,j++)
        B[j] = A[i];

    for(i=0;i<length;i++)
        A[i]=B[i];
}


//Function to reverse array.
void Array::Reverse2()
{
    int i,j;
    for(j=length-1, i=0; i < (length)/2 ; i++,j--)
        intSwap(A[j],A[i]);
}


//Function for Left shifting of elements
void Array::LShift()
{
    int i;
    int l = length;

    if(l == 1)
        A[l-1] = 0;

    else if(l > 1)
    {
        for(i=1; i<l; i++)
            A[i-1] = A[i];

        A[l-1] = 0;
    }
}

//Function for Left rotation of elements
void Array::LRotate()
{
    int i,temp;
    int l = length;

    temp = A[0];

    if(l > 0)
    {
        for(i=1; i<l; i++)
            A[i-1] = A[i];

        A[l-1] = temp;
    }
}

//Function for Right shifting of elements
void Array::RShift()
{
    int i;
    int l = length;

    if(l == 1)
        A[0] = 0;

    else if(l > 1)
    {
        for(i=l-2; i>=0; i--)
            A[i+1] = A[i];

        A[0] = 0;
    }
}

//Function for Right rotation of elements
void Array::RRotate()
{
    int i,temp;
    int l = length;

    temp = A[l-1];

    if(l > 0)
    {
        for(i=l-2; i>=0; i--)
            A[i+1] = A[i];

        A[0] = temp;
    }
}

//Function to insert element in a sorted array.
void Array::InsertinSortedArray(int x)
{
    int i = length - 1;

    //Check for Overflow
    if(length == szie)
      return;

    while( i>=0 && A[i] > x)
    {
        A[i+1] = A[i];
        i--;
    }
    A[i+1] = x;
    length++;
}

//Function for checking if the Array is sorted.
int Array::isSorted()
{
    int i;
    for(i=0;i< length-1;i++)
    {
        if(A[i] > A[i+1])
            return 0;
    }
    return 1;
}


//Function to arrange -ve elements to left.
void Array::Rearrange()
{
    int i,j;
    i = 0;
    j = length - 1;

    while(i<j)
    {
        while(A[i] < 0) i++;
        while(A[j] > 0) j--;
        if(i<j)            intSwap(A[i], A[j]);
    }
}

//// Function to Merge two arrays
//struct Array* Merge(struct Array *arr1,struct Array *arr2)
//{
// int i,j,k;
// i=j=k=0;
//
// struct Array *arr3 = (struct Array *) malloc(sizeof(struct Array));
//
// while(i<arr1->length && j<arr2->length)
// {
//     if(arr1->A[i] < arr2->A[j])
//        arr3->A[k++] = arr1->A[i++];
//     else
//        arr3->A[k++] = arr2->A[j++];
// }
//
//  while(i<arr1->length)
//  {
//      arr3->A[k++] = arr1->A[i++];
//  }
//  while(j<arr2->length)
//  {
//      arr3->A[k++] = arr1->A[j++];
//  }
//
//  arr3->length = k;
//  arr3->szie = 10;
//
//  return arr3;
//}
//
//
////Function to Union to arrays
//struct Array* Union(struct Array *arr1,struct Array *arr2)
//{
//  int i,j,k;
//  i=j=k=0;
//  struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
//
//  while(i<arr1->length && j<arr2->length)
//  {
//   if(arr1->A[i]<arr2->A[j])
//     arr3->A[k++]=arr1->A[i++];
//   else if(arr2->A[j]<arr1->A[i])
//     arr3->A[k++]=arr2->A[j++];
//   else
//   {
//     arr3->A[k++]=arr1->A[i++];
//     j++;
//   }
//  }
//  for(;i<arr1->length;i++)
//       arr3->A[k++]=arr1->A[i];
//  for(;j<arr2->length;j++)
//       arr3->A[k++]=arr2->A[j];
//
//  arr3->length=k;
//   arr3->szie=10;
//return arr3;
//}
//
//
////Function to perform Interstion
//struct Array* Intersection(struct Array *arr1,struct Array *arr2)
//{
//   int i,j,k;
//   i=j=k=0;
//   struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));
//
//  while(i<arr1->length && j<arr2->length)
//  {
//   if(arr1->A[i]<arr2->A[j])
//        i++;
//   else if(arr2->A[j]<arr1->A[i])
//        j++;
//   else if(arr1->A[i]==arr2->A[j])
//   {
//    arr3->A[k++]=arr1->A[i++];
//    j++;
//   }
//  }
//  arr3->length=k;
//  arr3->szie=10;
//  return arr3;
//}
//
//
//struct Array* Difference(struct Array *arr1,struct Array *arr2)
//{
//  int i,j,k;
//  i=j=k=0;
//
//  struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));
//
//  while(i<arr1->length && j<arr2->length)
//  {
//   if(arr1->A[i]<arr2->A[j])
//     arr3->A[k++]=arr1->A[i++];
//   else if(arr2->A[j]<arr1->A[i])
//     j++;
//   else
//    {
//      i++;
//      j++;
//    }
//
//  }
//
//  for(;i<arr1->length;i++)
//    arr3->A[k++]=arr1->A[i];
//
//  arr3->length=k;
//  arr3->szie=10;
//  return arr3;
//}

