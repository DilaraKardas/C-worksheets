#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct n
{
    int x;
    n *next;
};
typedef struct n node;


void bastir(node* r)
{
    node *iter = r; //art�k null yok, iter var. iter, bizim kontrol �art�m�z.
    //iter r a e�it olunca ba�l� listede bir tur atm���z demektir. Ama ilk ba�ta iterle r zaten e�it bu y�zden ilk eleman� bast�rmam�z gerek ki e�itlik bozulsun ve d�ng� �al��s�n
    printf("%d", iter->x);  // ilk eleman� bast�r�yoruz
    iter = iter->next;
    while(iter != r)
    { //tek tek t�m d���mleri bast�r�yoruz.
        printf("%d", iter -> x);
        iter = iter->next;
    }

}
void ekle(node* r, int x)
{
    node* iter =r;
    while(iter->next!= r)
        iter = iter -> next;


        iter -> next = (node*)malloc(sizeof(node));
        iter -> next -> x = x;
        iter -> next -> next = r;
}
node* ekleSirali(node* r, int x)
{
    if(r == NULL)  //linkedlist bo�sa
    {
        r = (node*)malloc(sizeof(node));
        r -> next = r; //tek eleman� olan ve kendisini g�steren bir linklist.
        r -> x = x;
        return r;
    }
    if(r ->x > x) //eklenecek de�er mevcut de�erden k���kse
        {
            //root de�i�iyor,eklenen yeni kutu yeni root oluyor
            node*temp = (node*)malloc(sizeof(node));
            temp -> x = x;
            temp -> next = r;
            node* iter = r;
            while(iter->next!=r)
                iter = iter->next;
            iter->next = temp;
            return temp;
        }
  /*  node* sil(node*r, int x)
    {
        node* temp;
        node*iter = r;
        if(r->x == x)
        {
            temp = r;
            r = r->next;
            free(temp);
            return r;
        }
    }*/

    node* iter = r; //root u de�i�tirmemek i�in iter kulland�k. iter linklistin ba��n� g�steriyordu ��nk�
    while(iter->next!= r && iter->next->x < x) //eklenecek d���m ilk de�erden b�y�k, ikinciden k���kken
    {
        iter = iter -> next;
    }

    node*temp = (node*)malloc(sizeof(node));
    temp->next= iter->next; //temp, bilinmeyen (bo� kutu) iter ise bilinen. Kutunun i�ine bilineni at.
    iter->next = temp;
    temp->x = x;
    return r;

int main()
{
    node* root;
    root = NULL;

    root = ekleSirali(root, 400);
    root = ekleSirali(root, 40);
    root = ekleSirali(root, 4);
    root = ekleSirali(root, 450);
    root = ekleSirali(root, 50);
    bastir(root);
    root = sil(root, 50);
    bastir(root);
    root = sil(root, 999);
    bastir(root);
    root = sil(root, 4);
    bastir(root);
    root = sil(root, 450);
    bastir(root);



    return 0;
}
