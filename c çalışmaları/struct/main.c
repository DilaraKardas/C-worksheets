#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct kredi{
    float oran;
    int vadesayisi;
};
typedef struct kredi arackredi;


struct Arac
{
    char markamodel[50];
    int modelyili;
    int km;
    double fiyat;
    arackredi kredibilgi;
};
typedef struct Arac Araba;

int main()
{
    srand(time(0));
    int aracsayisi;
    printf("Galeride kac arac var?");
    scanf("%d",&aracsayisi);
    getchar();

    Araba* arabaptr;
    arabaptr=(Araba*)malloc(aracsayisi*sizeof(Araba));

    for(int i=0;i<aracsayisi;i++){
        printf("%d. aracin markamodeli:",i+1);
        gets(arabaptr[i].markamodel);
        printf("%d. aracin model yili:",i+1);
        scanf("%d",&arabaptr[i].modelyili);
        printf("%d. aracin kilometresi:",i+1);
        scanf("%d",&arabaptr[i].km);
        printf("%d. aracin fiyati:",i+1);
        scanf("%lf",&arabaptr[i].fiyat);
        getchar();
    }

    for(int i=0;i<aracsayisi;i++){
        arabaptr[i].kredibilgi.oran=(rand()%9+7)/100.0;
        arabaptr[i].kredibilgi.vadesayisi=rand()%49+12;
    }
    for(int i=0;i<aracsayisi;i++)
        printf("%s %d %d %.2lf Kredi Orani: %.2lf Kredi Vadesi: %d\n",arabaptr[i].markamodel,arabaptr[i].modelyili,arabaptr[i].km,arabaptr[i].fiyat,arabaptr[i].kredibilgi.oran,arabaptr[i].kredibilgi.vadesayisi);

        return 0;
    }
