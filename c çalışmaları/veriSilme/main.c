#include <stdio.h>
#include <stdlib.h>

struct n{
 int x;
 struct n * next;
};

typedef struct n node;

void bastir( node * r){
 node*iter = r;
 printf("%d", iter->x); //ilk elemanı bastırıp iteri ilerletiyor ki iter = r şartı bozulsun ve döngü aksın
 while (iter != r){
  printf("%d ", iter->x);
  iter = iter -> next;
 }
 printf("\n");
}

void ekle( node*r, int x){
    node*iter = r;
 while(iter->next != r){
  iter = iter->next;
 }
 iter->next = ( node *) malloc (sizeof (node ) );
 iter->next->x = x;
 iter->next->next = r;

}

node * ekleSirali ( node * r, int x){
 if( r == NULL){ //link list boşsa
  r = (node *) malloc ( sizeof ( node) );
  r -> next = r; //bir tane düğüm var ve o elemanın nexti kendisini gösteriyor
  r -> x = x;
  return r;
 }
 if(r -> x > x){ // ilk elemandan küēük durumu
  // root dešižiyor
  node * temp = (node*)malloc(sizeof(node));
  temp -> x = x;
  temp -> next = r;
  r = temp;
  node*iter = r;
  while(iter->next != r)
    iter = iter->next;
  iter->next =temp;
  return temp;
 }
 node * iter = r;
 while( iter -> next != r && iter -> next -> x < x ){
  iter = iter -> next;
 }

 node * temp = (node*)malloc(sizeof(node));
 temp->next = iter->next;
 iter->next = temp;
 temp->x = x;
 return r;

}

node * sil(node *r, int x){//baştaki elemanın silinme ihtimali var (yani root un değişme ihtimali). o yüzden fonksiyonu node* aldık. -- bu fonksiyonda amaç int x değerini linkedlistten silmek.
 node *temp;
 node *iter = r;
 if( r->x == x){
        while(iter->next != r)
            iter = iter->next;
  iter->next = ext;
  free(r);
  return iter->next;
 }
 while ( iter->next != r && iter->next->x != x){ //silmek istediğin elemanı bulana kadar dön.
  iter = iter->next;
 }
 if ( iter->next == r){ //sona kadar gittin ve aradığın sayiyi hala bulamadın. demekki sayi listede yok
  printf( "Sayi bulunamadi!\n" );
  return r;
 }
 temp = iter->next; //silmek istediğin sayıyı buldun ve o sayıyı önce geçici düğüm haline getiriyorsun
 iter->next = iter->next->next; // ya da iter->next = temp->next
 free(temp);
 return r;
}

int main ()
{

 node * root;
 root = NULL;

 root = ekleSirali( root, 400);
 root = ekleSirali( root, 40);
 root = ekleSirali( root, 4);
 root = ekleSirali( root, 450);
 root = ekleSirali( root, 50);
 bastir(root);
 root = sil( root, 50);
 bastir(root);
 root = sil( root, 999);
 bastir(root);
 root = sil( root, 4);
 bastir(root);
 root = sil( root, 450);
 bastir(root);

 return 0;

}
