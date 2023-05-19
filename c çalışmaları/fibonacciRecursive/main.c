#include <stdio.h>
#include <stdlib.h>

long int fibonacci (int x){
    if(x==0)
        return 0;
    else if(x==1)
        return 1;
    else
        return fibonacci(x-1)+fibonacci(x-2);
}

int main()
{
    int n;
    long int sonuc;
    printf("Fibonaccinin kacinci elemanini istiyorsunuz?");
    scanf("%d",&n);

    sonuc=fibonacci(n);

    printf("Sonuc: %ld",sonuc);
    return 0;
}
