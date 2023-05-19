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
    node *iter = r; //artýk null yok, iter var. iter, bizim kontrol þartýmýz.
    //iter r a eþit olunca baðlý listede bir tur atmýþýz demektir. Ama ilk baþta iterle r zaten eþit bu yüzden ilk elemaný bastýrmamýz gerek ki eþitlik bozulsun ve döngü çalýþsýn
    printf("%d", iter->x);  // ilk elemaný bastýrýyoruz
    iter = iter->next;
    while(iter != r)
    { //tek tek tüm düðümleri bastýrýyoruz.
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
    if(r == NULL)  //linkedlist boþsa
    {
        r = (node*)malloc(sizeof(node));
        r -> next = r; //tek elemaný olan ve kendisini gösteren bir linklist.
        r -> x = x;
        return r;
    }
    if(r ->x > x) //eklenecek deðer mevcut deðerden küçükse
        {
            //root deðiþiyor,eklenen yeni kutu yeni root oluyor
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

    node* iter = r; //root u deðiþtirmemek için iter kullandýk. iter linklistin baþýný gösteriyordu çünkü
    while(iter->next!= r && iter->next->x < x) //eklenecek düðüm ilk deðerden büyük, ikinciden küçükken
    {
        iter = iter -> next;
    }

    node*temp = (node*)malloc(sizeof(node));
    temp->next= iter->next; //temp, bilinmeyen (boþ kutu) iter ise bilinen. Kutunun içine bilineni at.
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
