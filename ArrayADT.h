#ifndef ARRAYADT_H_INCLUDED
#define ARRAYADT_H_INCLUDED



//Declrations
class Array{

   private:
    int *A;
    int length;
    int szie;

   public:
           Array(int);
           Array();
           ~Array();
    void   intSwap(int &,int &);
    void   Display();
    void   Append(int);
    void   Insert(int,int);
    int    Delete(int);
    int    LinearSearch(int);
    int    LinearSearchv1(int);
    int    LinearSearchv2(int);
    int    BinarySearch(int);
    int    RBinSearch(int,int,int);
    int    Get(int);
    void   Set(int,int);
    int    Max();
    int    Min();
    int    Sum();
    float  Avg();
    void   Reverse();
    void   Reverse2();
    void   LShift();
    void   LRotate();
    void   RShift();
    void   RRotate();

    void  InsertinSortedArray(int);
    int   isSorted();
    void  Rearrange();

//    struct Array* Merge(struct Array *,struct Array *);
//    struct Array* Union(struct Array *,struct Array *);
//    struct Array* Intersection(struct Array *,struct Array *);
//    struct Array* Difference(struct Array *,struct Array *);

};
#endif // ARRAYADT_H_INCLUDED
