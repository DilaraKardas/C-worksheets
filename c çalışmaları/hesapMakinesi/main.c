#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int islem;
    float a,b, sonuc;

    if(argc == 4) //main fonksiyonunun 4 tane parametresi var. bu if koþuluyla parametre kontrolünü yapýyoruz.
    {/* //4 parametrenin ilki dosya adý, ikincisi yapýlacak iþlem,
        son ikisiyse iþleme sokulacak sayýlar.
        */

       islem = atoi(argv[1]);//diziyi 1 den baþlatýyoruz çünkü dosya adýyla bir iþimiz yok.
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
