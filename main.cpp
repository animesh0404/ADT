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
void setString(struct String *, char[]);
void getString(struct String);
//void chCaseAlt(struct String *);
int countC(struct String);
int countV(struct String str);
int countW(struct String str);

int main()
{
    struct String name,msg;
    char *temp;
     int i;
    initString(&name);
    initString(&msg);

    setString(&name, "If you practice everyday your hand becomes fine in whatever art you choose.");

//    printf("\n Please enter your meassage: ");
//    scanf("%s",&temp);
//    setString(&name,temp);

    printf("\n\nLength: %d",getLength(name));

    getString(name);
//    chCaseAlt(&name);
    printf("\n\nConsonant Count: %d",countC(name));

    printf("\n\nVowel Count: %d",countV(name));

    printf("\n\nWord Count: %d",countW(name));
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

//Change Case to Alternative Case.
//void chCaseAlt(struct String *str)
//{
//    int i;
//    for(i=0; str->A[i] != '\0';i++)
//    {
//        if(str->A[i] >= 'A' && str->A[i] <= 'Z')
//        {
//            str->A[i] = str->A[i] + 32;
//        }
//        else if(str->A[i] >= 'a' && str->A[i] <= 'z')
//        {
//            str->A[i] = str->A[i] - 32;
//        }
//    }
//}

int getLength(struct String n)
{
 return n.length;
}

void setString(struct String *a,char n[])
{
    int l;
    a->A = n;
    for(l=0;a->A[l] != '\0';l++);
    a->length = l;
}

void getString(struct String a)
{
    printf("\n%s", a.A);
}

int countC(struct String str)
{
 int i,cCount = 0;
 for(i=0;str.A[i] != '\0';i++)
 {
     if(str.A[i] == 'a'||str.A[i] == 'e'||str.A[i] == 'i'||str.A[i] == 'o'||str.A[i] == 'u'||
        str.A[i] == 'A'||str.A[i] == 'E'||str.A[i] == 'I'||str.A[i] == 'O'||str.A[i] == 'U') {}

     else if((str.A[i] >= 'A' && str.A[i] <='Z')||(str.A[i] >= 'a' && str.A[i] <= 'z'))
     {
         cCount++;
     }
 }
 return cCount;
}

int countV(struct String str)
{
 int i,vCount = 0;
 for(i=0;str.A[i] != '\0';i++)
 {
     if(str.A[i] == 'a'||str.A[i] == 'e'||str.A[i] == 'i'||str.A[i] == 'o'||str.A[i] == 'u'||
        str.A[i] == 'A'||str.A[i] == 'E'||str.A[i] == 'I'||str.A[i] == 'O'||str.A[i] == 'U')
        {
            vCount++;
        }
     else if((str.A[i] >= 'A' && str.A[i] <='Z')||(str.A[i] >= 'a' && str.A[i] <= 'z')){}
 }
 return vCount;
}

int countW(struct String str)
{
 int i,wCount = 0;
 for(i=0;str.A[i] != '\0';i++)
 {
    if(str.A[i] == ' ' && str.A[i-1] != ' ')
        wCount++;
 }
 wCount++;
 return wCount;
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
