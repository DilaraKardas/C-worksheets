#include <stdio.h>
#include <stdlib.h>
/*
int* fonk(){ //fonksiyonun kendi i�indeki adresleri ve yerel de�i�kenleri geri d�nd�remezsin.
    int temp = 55; //Bu y�zden kodu a�a��daki gibi d�zenledik.
    return &temp;
}

int main()
{
    int *ptr;
    ptr = fonk();
    printf("%d", *ptr);
    return 0;
}
*/


int* fonk(int *x){
    *x = 55;
    return x;
}

int main()
{
    int temp;
    int *ptr;
    ptr = fonk(&temp);
    printf("%d", *ptr);

    return 0;
}
