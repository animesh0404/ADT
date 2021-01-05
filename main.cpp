/*---------------------------
//Author:     Animesh Kahara
//Program:    Array ADT
//All rights reserved, Copyright 2020
*/

#include<stdio.h>
#include<stdlib.h>

struct String {
       char *A;
       int length;
       int szie;
};

//using namespace std;
int getLength(struct String);
void initString(struct String *);
void initString(struct String *,int);
void setString(struct String *, char[],int);
void getString(struct String);

int main()
{
    struct String name,msg;
    char *temp;
    initString(&name);
    initString(&msg);

    setString(&name, "Animesh",7);

//    printf("\n Please enter your meassage: ");
//    scanf("%s",&temp);
//    setString(&name,temp);

    printf("\n\nLength: %d",getLength(name));

    getString(name);
//    getString(msg);

//    getString(name);

    return 0;
}

void initString(struct String *a)
{
    a->A = "";
    a->length = 0;
    a->szie = 10;
}

void initString(struct String *a,int s)
{
    a->A = (char *)malloc(s * sizeof(struct String));
    a->length = 0;
    a->szie = s;
}


int getLength(struct String n)
{
 return n.length;
}

void setString(struct String *a,char n[],int l)
{
    a->A = n;
    a->length = l;
}

void getString(struct String a)
{
    printf("\n%s", a.A);
}
////Driver Code
//int main()
//{
//    char ch;
//    int ele;
//    int x,index;
//
//    cout<<"\nEnter size of array: ";
//    cin>>ele;
//
//    Array arr(ele);
//
//    do
//    {
//        cout<<"\n\nMenu\n";
//        cout<<"1. Insert\n";
//        cout<<"2. Delete\n";
//        cout<<"3. Search\n";
//        cout<<"4. Sum\n";
//        cout<<"5. Display\n";
//        cout<<"6. Average\n";
//        cout<<"7. Exit\n";
//
//        cout<<"enter you choice: ";
//        cin>>ch;
//
//
//        switch(ch)
//        {
//         case '1':
//            cout<<"\nEnter (index,value): ";
//            cin>>index>>x;
//            arr.Insert(index,x);
//            break;
//
//         case '2':
//            cout<<"Enter index ";
//            cin>>index;
//            x=arr.Delete(index);
//            cout<<"Deleted Element is "<<x<<endl;
//            break;
//
//         case '3':
//            cout<<"Enter element to search ";
//            cin>>x;
//            index=arr.LinearSearch(x);
//            cout<<"Element index "<<index<<endl;
//            break;
//
//         case '4':
//             cout<<"Sum is "<<arr.Sum()<<endl;
//            break;
//
//         case '5':
//            arr.Display();
//            break;
//
//         case '6':
//            cout<<"Avg is: "<<arr.Avg()<<endl;
//            break;
//
//         case '7':
//            break;
//
//         default:
//            cout<<"\n\n\t\tWRONG INPUT";
//            cin>>ele;
//        }
//    }while(ch!='7');
//
//    return 0;
//}
//
//
