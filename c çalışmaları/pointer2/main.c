#include <stdio.h>
#include <stdlib.h>

void carp(int y[], int s, int n){
    for(int i=0; i<n; i++)
        y[i] *= s;
}

int main()
{
    int dizi[50];
    int n = 50;

    srand(time(0));

    for(int i=0; i<50; i++){
        dizi[i] = (rand()%100)+1;
        printf("%d ", dizi[i]);
    }

    printf("\n\n\ndizi [0] in adresi: %d\n", &dizi[0]);
    printf("dizi pointerinin degeri: %d", dizi);

    carp(dizi,5,n);
    printf("\n\nCarpimdan sonraki durum:\n\n");

    for(int i=0; i<n; i++)
        printf("%d ", dizi[i]);

    return 0;
}

