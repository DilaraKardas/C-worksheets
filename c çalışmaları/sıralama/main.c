#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int sayilar[101];
    int sirali[101];
    srand(time(0));

    for(int i=0; i<101; i++)
        sayilar[i]=rand()%1000+1;

    int enkucuk, enkucuk_indis;

    for(int i=0; i<=50; i++){
        enkucuk = 1001; //int max gibi
        enkucuk_indis = -1;
        for(int j=0; j<101; j++)
            if(sayilar[j]<enkucuk){
                enkucuk = sayilar[j];
                enkucuk_indis = j;
            }
            sayilar[enkucuk_indis] = 1001;
    }
    printf("medyan: %d\n", enkucuk);
    return 0;
}
