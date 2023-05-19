#include <stdio.h>
#include <stdlib.h>

int TauMu(int sayi,int a,int b){
    if(sayi%a==0 && sayi%b==0)
        return 1;
    else if()
        return 0;
    else
        return TauMu(a,b,c);
}

int main()
{
    int n,x,y;
    printf("Bir sayi giriniz: ");
    scanf("%d",&n);

    TauMu(n,x,y);

    return 0;
}
