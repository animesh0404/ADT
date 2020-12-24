/*---------------------------
//Author:     Animesh Kahara
//Program:    Array ADT
//All rights reserved, Copyright 2020
*/

#include<iostream>
#include<stdlib.h>
#include "ArrayADT.h"

using namespace std;

//Driver Code
int main()
{
    char ch;
    int ele;
    int x,index;

    cout<<"\nEnter size of array: ";
    cin>>ele;

    Array arr(ele);

    do
    {
        cout<<"\n\nMenu\n";
        cout<<"1. Insert\n";
        cout<<"2. Delete\n";
        cout<<"3. Search\n";
        cout<<"4. Sum\n";
        cout<<"5. Display\n";
        cout<<"6. Average\n";
        cout<<"7. Exit\n";

        cout<<"enter you choice: ";
        cin>>ch;


        switch(ch)
        {
         case '1':
            cout<<"\nEnter (index,value): ";
            cin>>index>>x;
            arr.Insert(index,x);
            break;

         case '2':
            cout<<"Enter index ";
            cin>>index;
            x=arr.Delete(index);
            cout<<"Deleted Element is "<<x<<endl;
            break;

         case '3':
            cout<<"Enter element to search ";
            cin>>x;
            index=arr.LinearSearch(x);
            cout<<"Element index "<<index<<endl;
            break;

         case '4':
             cout<<"Sum is "<<arr.Sum()<<endl;
            break;

         case '5':
            arr.Display();
            break;

         case '6':
            cout<<"Avg is: "<<arr.Avg()<<endl;
            break;

         case '7':
            break;

         default:
            cout<<"\n\n\t\tWRONG INPUT";
            cin>>ele;
        }
    }while(ch!='7');

    return 0;
}


