#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ortaklaribul(int x[], int y[], int z[], int n){
    int i,j,k,sayac=0;

    for(i=0; i<n; i++){

        for(k=0; k<i; k++)
            if(x[k] == x[i])
                break;
        if(k!=i) //yani break çalýþtýysa ya da x[i] daha önce aranmýþsa
            continue;
        for(j=0; j<n; j++){
            if(x[i] == y[j])
                break;
        }
        if(j!=n) //eþleþme varsa
            z[sayac++] = x[i];
    }
}

int main()
{
    srand(time(0));
    int a[50], b[50], c[51];
    int n=50;

    for(int i=0; i<n; i++)
    {
        a[i] = (rand()%1000)+1;
        b[i] = (rand()%1000)+1;
    }
    printf("ilk dizi: ");
    for(int i=0; i<n; i++)
        printf("%d ", a[i]);

    printf("\n\nikinci dizi: ");
    for(int i=0; i<n; i++)
        printf("%d ", b[i]);

    for(int i=0; i<n+1; i++)
        c[i] = -1;

    ortaklaribul(a,b,c,n);

    if(c[0] == -1)
        printf("\n\nOrtak eleman bulunamadi!!!");
    else{
        printf("\n\nBulunan ortak elemanlar: ");
        int e=0;
        while(c[e] != -1){
            printf("%d ", c[e++]);
        }

    }
    return 0;
}
