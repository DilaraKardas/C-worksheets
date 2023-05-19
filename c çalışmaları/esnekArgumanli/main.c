#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>


void mesafeler(int n, ...){
    va_list liste;
    va_start (liste,n);
                          // 100 nokta say�s�, 2 koordinat. (x ve y koordinatlar�)
    int noktalar[100][2]; //bu dizi n tane noktay� tutacak ama c dilinde b�yle bir yaz�m m�mk�n de�il. bu y�zden kendim 100 elemanl�k yer ay�rd�m.

    for(int i=0; i<n; i++)
    {
        noktalar[i][0] = va_arg(liste,int);  //x koordinat�
        noktalar[i][1] = va_arg(liste,int);  //y koordinat�
    }

    va_end(liste);
    float mes;
    for(int i=0; i<n-1; i++){

        for(int j=i+1; j<n; j++){
            mes = sqrt(pow((noktalar[i][0] - noktalar[j][0]),2.0) + pow((noktalar[i][1] - noktalar[j][1]),2.0));
            printf("nokta %d ile nokta %d arasindaki mesafe: %f kadardir.\n", i+1,j+1,mes);
        }
    }
}


int main()
{
    //mesafeler(2,5,8,-4,9); //parametreler s�ras�yla: n,x,y,x,y
    mesafeler(3,5,8,-4,9,20,12);
    //mesafeler(4,5,8,-4,9,20,12,10,-7);
    //mesafeler(5,5,8,-4,9,20,12,10,-7,6,2);


    return 0;
}
