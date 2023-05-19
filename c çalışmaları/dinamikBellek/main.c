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
        scanf("%d",(dizi+i)); //burda iþaretçi aritmetiði yaptýk
    }
    for(int i=0;i<sayi;i++){
        toplam += *(dizi+i);
    }
    printf("toplam = %d\n", toplam);
//-----------------------------------------------------------------------
//realloc
    printf("kac eleman eklemek istiyorsunuz? "); //ekstra yer açacaðýz
    scanf("%d",&ekstra);

    dizi=(int*)realloc(dizi,(sayi+ekstra)*sizeof(int));//atamayý yapacaðýn pointerý farklý bir pointer da seçebiliridin ama gerek yok

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
