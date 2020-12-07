/*---------------------------
//Author:     Animesh Kahara
//Program:    Array ADT
*/

#include <iostream>
#include <string.h>

using namespace std;

struct Array{
    int A[10];
    int length;
    int szie;
};


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
    Delete(&arr,2);
    printf("\nAfter Deletion:");
    Display(arr);



    return 0;
}





