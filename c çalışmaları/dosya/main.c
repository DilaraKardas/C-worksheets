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
        else{ //kopyalanacak karakteri temp diye bir de�i�kene atay�p ordan hedef dosyaya(yani fptr2 ye) kopyalad�k.  temp i olu�turma sebebimiz fgetc ve fputc fonksiyonlar�n�n kullan�lma y�ntemleri
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
