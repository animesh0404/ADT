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


//Function for traversing/Displaying the complete array
void Display(struct Array a)
{
    int i;
    for(i=0;i<a.length;i++)
        printf("\n%d",a.A[i]);
}

void Append(struct Array *a,int x)
{
    if(a->length < a->szie)
    {
        a->A[ a->length++] = x;
        return;
    }
}

int main()
{
    struct Array arr = {{2,4,6,7,8},5,10};

    Append(&arr,34);
    Display(arr);

    return 0;
}





