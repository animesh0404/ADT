#ifndef ARRAYADT_H_INCLUDED
#define ARRAYADT_H_INCLUDED

//Declrations
struct Array{
    int A[10];
    int length;
    int szie;
};

void   intSwap(int *,int *);
void   Display(struct Array);
void   Append(struct Array *,int);
void   Insert(struct Array *,int,int);
int    Delete(struct Array *,int);
int    LinearSearch(struct Array,int);
int    LinearSearchv1(struct Array *,int);
int    LinearSearchv2(struct Array *,int);
int    BinarySearch(struct Array, int);
int    RBinSearch(struct Array,int,int,int);
int    Get(struct Array ,int);
void   Set(struct Array *,int,int);
int    Max(struct Array);
int    Min(struct Array);
int    Sum(struct Array);
float  Avg(struct Array);
void   Reverse(struct Array *);
void   Reverse2(struct Array *);
void   LShift(struct Array *);
void   LRotate(struct Array *);
void   RShift(struct Array *);
void   RRotate(struct Array *);

void  InsertinSortedArray(struct Array *,int);
int   isSorted(struct Array );
void  Rearrange(struct Array *);
struct Array* Merge(struct Array *,struct Array *);
struct Array* Union(struct Array *,struct Array *);
struct Array* Intersection(struct Array *,struct Array *);
struct Array* Difference(struct Array *,struct Array *);
#endif // ARRAYADT_H_INCLUDED
