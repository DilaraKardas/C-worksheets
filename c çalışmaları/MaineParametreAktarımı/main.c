#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[])
{
    int islem;
    float a, b, sonuc;

    if(argc == 4)
    {
       islem = atoi(argv[1]);
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
        printf("sonuc: %f", sonuc);
    }
    else
        printf("Eksik parametre!!");
    return 0;
}
