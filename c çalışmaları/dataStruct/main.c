#include <stdio.h>
#include <stdlib.h>

typedef struct kapsul{
    char veri;
    struct kapsul* ptr;
} dugum;

int main()
{
    dugum A,B,C;
    A.veri='A';
    B.veri='B';
    C.veri='C';

    A.ptr=&B;
    B.ptr=&C;
    C.ptr=NULL;

    printf("A veri: %c\nB veri: %c\nC veri: %c\n",A.veri,B.veri,C.veri);
    printf("A adres: %p, B adres: %p, C adres: %p\n",&A,&B,&C);
    printf("A nin pointeri: %p, B nin pointeri: %p, C nin pointeri: %p, ", A.ptr,B.ptr,C.ptr);


    //printf("A nin bir otesindeki veri: %c\n", (*(A.ptr)).veri);
    printf("\n\nA nin bir otesindeki veri: %c\n", A.ptr->veri);

    //printf("A nin iki otesindeki veri: %c\n", (*((*(A.ptr)).ptr)).veri);
    printf("A nin iki otesindeki veri: %c\n", A.ptr->ptr->veri);
    return 0;
}
