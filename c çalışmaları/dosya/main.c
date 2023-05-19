#include <stdio.h>
#include <stdlib.h>


int main()
{
    FILE* fptr1 = fopen("dosya.txt","r");
    if(fptr1==NULL)
        printf("dosya acilamadi!!");
    else{
        FILE* fptr2 = fopen("dosya2.txt", "w");
        if(fptr2==NULL)
            printf("dosya acilamadi!!");
        else{ //kopyalanacak karakteri temp diye bir deðiþkene atayýp ordan hedef dosyaya(yani fptr2 ye) kopyaladýk.  temp i oluþturma sebebimiz fgetc ve fputc fonksiyonlarýnýn kullanýlma yöntemleri
            char temp;
            while(!feof(fptr1))
            {
                temp=fgetc(fptr1);
                fputc(temp,fptr2);
            }
            fclose(fptr2);
        }
       fclose(fptr1);
    }

    return 0;
}
