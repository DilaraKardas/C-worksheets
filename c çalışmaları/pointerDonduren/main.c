#include <stdio.h>
#include <stdlib.h>
/*
int* fonk(){ //fonksiyonun kendi içindeki adresleri ve yerel deðiþkenleri geri döndüremezsin.
    int temp = 55; //Bu yüzden kodu aþaðýdaki gibi düzenledik.
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
