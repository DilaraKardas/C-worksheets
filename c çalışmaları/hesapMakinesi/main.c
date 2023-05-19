#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int islem;
    float a,b, sonuc;

    if(argc == 4) //main fonksiyonunun 4 tane parametresi var. bu if ko�uluyla parametre kontrol�n� yap�yoruz.
    {/* //4 parametrenin ilki dosya ad�, ikincisi yap�lacak i�lem,
        son ikisiyse i�leme sokulacak say�lar.
        */

       islem = atoi(argv[1]);//diziyi 1 den ba�lat�yoruz ��nk� dosya ad�yla bir i�imiz yok.
       a = atof(argv[2]);
       b = atof(argv[3]);
       switch(islem)
       {
       case 1:
        sonuc = a+b;
        break;
        case 2:
        sonuc = a-b;
        break;
        case 3:
        sonuc = a*b;
        break;
        case 4:
        sonuc = a/b;
        break;
        default:
            sonuc = -1;
       }
       printf("Sonuc: %f", sonuc);

    }
    else
        printf("Hatali sayida parametre!");
    return 0;
}
