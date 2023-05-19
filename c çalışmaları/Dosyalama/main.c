#include <stdio.h>
#include <stdlib.h>

typedef struct ogrenci_data
{
    int No;
    char Ad[51];
    int Not;
} Ogrenci;

Ogrenci* ogrenciler;
int ogrenci_sayisi;

void DosyaYaz()
{
    printf("OGRENCI BILGILERINI GIRINIZ:\n-------------------------------\n");

    for(int i=0; i<ogrenci_sayisi; i++)
    {
        printf("%d. Ogrenci No: ",i+1);
        scanf("%d", &ogrenciler[i].No);
        printf("%d. Ogrenci Adi: ",i+1);
        scanf("%s", &ogrenciler[i].Ad);
        printf("%d. Ogrenci Notu: ",i+1);
        scanf("%d", &ogrenciler[i].Not);
        printf("\n");
    }
    FILE* fptr=fopen("ogrenci_bilgi.txt","w");
    if(fptr==NULL)
        printf("Dosya acilamadi!!");
    else
    {
        for(int i=0; i<ogrenci_sayisi; i++)
        {
            fprintf(fptr,"%d\t%s\t%d\n", ogrenciler[i].No,ogrenciler[i].Ad,ogrenciler[i].Not);
        }
        fclose(fptr);
        printf("Ogrenci bilgileri kaydedildi!!\n\n");
    }
}
void DosyaOku()
{
    printf("Ogrenci bilgileri dosyadan okunuyor\n\n");
    printf("Ogrenci Bilgileri\n-------------------------------------\n");

    int numara,notu;
    char ismi[51];

    FILE *fptr = fopen("ogrenci_bilgi.txt","r");

    if(fptr==NULL)
        printf("dosya acilamadi!");
    else
    {
        for(int i=0; i<ogrenci_sayisi; i++){
            fscanf(fptr,"%d\t%s\t%d\n",&numara,ismi,&notu);
            printf("No: %d\nAd: %s\nNot: %d\n\n",numara,ismi,notu);
        }
        fclose(fptr);
    }
}
int main()
{
    printf("Kac ogrenci var?");
    scanf("%d", &ogrenci_sayisi);

    ogrenciler = (Ogrenci*)malloc(ogrenci_sayisi*sizeof(Ogrenci));

    DosyaYaz();
    DosyaOku();
    return 0;
}
