#include <stdio.h>
#include <stdlib.h>

struct {
    int x;
    n*next;
};node;
typedef n node;

void enqueue(int x){
    if(root == NULL){
        root = (node*)malloc(sizeof(node));
        root->data =x;
        root->next = NULL;
        son = root;
    }
    else{
        son->next = (node*)malloc(sizeof(node));
        son->next->data = x;
        son = son->next;
        son->next = NULL;
    }
}
int dequeue(){
    if(root==NULL){
        printf("linked list bos");
        return -1;
    }
    int rvalue = root->data;
    node*temp = root;
    root = root ->next;
    free(temp);
    return rvalue;
    }

int main()
{

    for(int i=0; i<20; i++){
        enqueue(i*10);
    }
    for(int i=0; i<13; i++){
        printf("%d", dequeue());
    }
    for(int i=0; i<20; i++){
        enqueue(i*10);
    }
    for(int i=0; i<30; i++){
        printf("%d", dequeue());
    }
}
















