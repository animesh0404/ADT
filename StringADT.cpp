#include"StringADT.h"
#include<stdlib.h>
#include<stdio.h>


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

int valid(struct String str)
{
   int i;
   for(i=0; str.A[i] != '\0'; i++)
   {
       if(   ! (str.A[i] >= 'A' && str.A[i] <= 'Z')   &&
             ! (str.A[i] >= 'a' && str.A[i] <= 'z' ) &&
             ! (str.A[i] >='0'  && str.A[i] <= '9' )    )
       {
          return 0;
       }
   }
  return 1;
}

int palindrome(struct String str)
{
    int i,j;
    for(i = 0, j = str.length-1; i < (str.length/2); i++,j--)
    {
        if(str.A[i] != str.A[j])
        {
            return 0;
        }
    }
    return 1;
}


int Reverse(struct String src,struct String *des)
{
    int i,j;
    char temp[src.length];
    for(i=src.length-1, j=0; i >= 0; i--,j++)
    {
        temp[i] = src.A[j];
    }
    temp[src.length] = '\0';

    setString(des, temp);
    return 0;
}
