#include <stdio.h>
#include <stdlib.h>

int main()
{
//malloc
    int sayi,toplam,ekstra;
    printf("kac adet sayi gireceksiniz? ");
    scanf("%d", &sayi);

    int *dizi = (int*)malloc(sizeof(int));

    printf("dizinin elemanlarini giriniz: \n");

    for(int i=0;i<sayi;i++){
        printf("Dizi[%d]= ",i);
        scanf("%d",(dizi+i)); //burda i�aret�i aritmeti�i yapt�k
    }
    for(int i=0;i<sayi;i++){
        toplam += *(dizi+i);
    }
    printf("toplam = %d\n", toplam);
//-----------------------------------------------------------------------
//realloc
    printf("kac eleman eklemek istiyorsunuz? "); //ekstra yer a�aca��z
    scanf("%d",&ekstra);

    dizi=(int*)realloc(dizi,(sayi+ekstra)*sizeof(int));//atamay� yapaca��n pointer� farkl� bir pointer da se�ebiliridin ama gerek yok

    for(int i=sayi;i<sayi+ekstra;i++){
        printf("dizi[%d]= ",i);
        scanf("%d",(dizi+i));
    }
    printf("\nyeni toplam hesabi: \n");
    toplam=0;
    for(int i=0;i<sayi+ekstra;i++){
        toplam += *(dizi+i);
    }
    printf("yeni toplam = %d\n", toplam);

    return 0;
}
