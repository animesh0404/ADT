#include"ArrayADT.h"
#include<stdio.h>
#include<stdlib.h>

//All Functions

//Function for traversing/Displaying the complete array.
void Display(struct Array a)
{
    int i;
    for(i=0;i<a.length;i++)
        printf(" %d ",a.A[i]);
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


//Function for Left shifting of elements
void LShift(struct Array *a)
{
    int i;
    int l = a->length;

    if(l == 1)
        a->A[l-1] = 0;

    else if(l > 1)
    {
        for(i=1; i<l; i++)
            a->A[i-1] = a->A[i];

        a->A[l-1] = 0;
    }
}

//Function for Left rotation of elements
void LRotate(struct Array *a)
{
    int i,temp;
    int l = a->length;

    temp = a->A[0];

    if(l > 0)
    {
        for(i=1; i<l; i++)
            a->A[i-1] = a->A[i];

        a->A[l-1] = temp;
    }
}

//Function for Right shifting of elements
void RShift(struct Array *a)
{
    int i;
    int l = a->length;

    if(l == 1)
        a->A[0] = 0;

    else if(l > 1)
    {
        for(i=l-2; i>=0; i--)
            a->A[i+1] = a->A[i];

        a->A[0] = 0;
    }
}

//Function for Right rotation of elements
void RRotate(struct Array *a)
{
    int i,temp;
    int l = a->length;

    temp = a->A[l-1];

    if(l > 0)
    {
        for(i=l-2; i>=0; i--)
            a->A[i+1] = a->A[i];

        a->A[0] = temp;
    }
}

//Function to insert element in a sorted array.
void InsertinSortedArray(struct Array *arr,int x)
{
    int i = arr->length - 1;

    //Check for Overflow
    if(arr->length == arr->szie)
      return;

    while( i>=0 && arr->A[i] > x)
    {
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = x;
    arr->length++;
}

//Function for checking if the Array is sorted.
int isSorted(struct Array a)
{
    int i;
    for(i=0;i< a.length-1;i++)
    {
        if(a.A[i] > a.A[i+1])
            return 0;
    }
    return 1;
}


//Function to arrange -ve elements to left.
void Rearrange(struct Array *a)
{
    int i,j;
    i = 0;
    j = a->length - 1;

    while(i<j)
    {
        while(a->A[i] < 0) i++;
        while(a->A[j] > 0) j--;
        if(i<j)            intSwap(&a->A[i], &a->A[j]);
    }
}

// Function to Merge two arrays
struct Array* Merge(struct Array *arr1,struct Array *arr2)
{
 int i,j,k;
 i=j=k=0;

 struct Array *arr3 = (struct Array *) malloc(sizeof(struct Array));

 while(i<arr1->length && j<arr2->length)
 {
     if(arr1->A[i] < arr2->A[j])
        arr3->A[k++] = arr1->A[i++];
     else
        arr3->A[k++] = arr2->A[j++];
 }

  while(i<arr1->length)
  {
      arr3->A[k++] = arr1->A[i++];
  }
  while(j<arr2->length)
  {
      arr3->A[k++] = arr1->A[j++];
  }

  arr3->length = k;
  arr3->szie = 10;

  return arr3;
}


//Function to Union to arrays
struct Array* Union(struct Array *arr1,struct Array *arr2)
{
  int i,j,k;
  i=j=k=0;
  struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

  while(i<arr1->length && j<arr2->length)
  {
   if(arr1->A[i]<arr2->A[j])
     arr3->A[k++]=arr1->A[i++];
   else if(arr2->A[j]<arr1->A[i])
     arr3->A[k++]=arr2->A[j++];
   else
   {
     arr3->A[k++]=arr1->A[i++];
     j++;
   }
  }
  for(;i<arr1->length;i++)
       arr3->A[k++]=arr1->A[i];
  for(;j<arr2->length;j++)
       arr3->A[k++]=arr2->A[j];

  arr3->length=k;
   arr3->szie=10;
return arr3;
}


//Function to perform Interstion
struct Array* Intersection(struct Array *arr1,struct Array *arr2)
{
   int i,j,k;
   i=j=k=0;
   struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));

  while(i<arr1->length && j<arr2->length)
  {
   if(arr1->A[i]<arr2->A[j])
        i++;
   else if(arr2->A[j]<arr1->A[i])
        j++;
   else if(arr1->A[i]==arr2->A[j])
   {
    arr3->A[k++]=arr1->A[i++];
    j++;
   }
  }
  arr3->length=k;
  arr3->szie=10;
  return arr3;
}


struct Array* Difference(struct Array *arr1,struct Array *arr2)
{
  int i,j,k;
  i=j=k=0;

  struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));

  while(i<arr1->length && j<arr2->length)
  {
   if(arr1->A[i]<arr2->A[j])
     arr3->A[k++]=arr1->A[i++];
   else if(arr2->A[j]<arr1->A[i])
     j++;
   else
    {
      i++;
      j++;
    }

  }

  for(;i<arr1->length;i++)
    arr3->A[k++]=arr1->A[i];

  arr3->length=k;
  arr3->szie=10;
  return arr3;
}

