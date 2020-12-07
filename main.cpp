#include <iostream>
#include <string.h>

using namespace std;

struct Array{
    int A[10];
    int length;
    int szie;
};

void Display(struct Array a)
{
    int i;
    for(i=0;i<a.length;i++)
        printf("\n%d",a.A[i]);
}


int main()
{
    struct Array arr = {{2,4,6,7,8},5,10};

    Display(arr);

    return 0;
}





