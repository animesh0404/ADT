#ifndef STRING_H
#define STRING_H



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
int countV(struct String);
int countW(struct String);
int valid(struct String);
int palindrome(struct String);
int Reverse(struct String,struct String *);

#endif // STRING_H
