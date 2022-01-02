#include <stdio.h>
#include <stdlib.h>

struct n{    
    int x;
   struct n* next;
}; 

typedef struct n node;

//printing added nodes to linked list

void bastir(node *r){
    while(r!=NULL){
        printf("%d ", r->x);
        r = r->next;
    }
}

//Adding ordered according to the size of the data the node has

node * ekleSirali(node * r, int x) {
    if(r == NULL) {  //if linked list is empty
        r = (node *)malloc(sizeof(node));
        r->next = NULL;
        r->x = x;
        return r; 
        }
        
    if(r->x > x) {   //case less than first element
        //root is changing
        node* temp =(node *)malloc(sizeof(node));
        temp->x =x;
        temp->next = r;
        return temp;
    }
    node * iter = r;  //or any other situation
    while(iter->next != NULL && iter->next->x < x ){
       iter = iter->next;
    }
    node * temp = (node *)malloc(sizeof(node));
    temp->next = iter->next;
    iter->next = temp;
    temp->x = x;
    return r;
}
//delete element from linked list

node * sil(node *r, int x){
    node *temp;
    node *iter = r;
    
    if(r->x == x){
        temp = r;
        r = r->next;
        free(temp);
        return r;
    }
    while (iter->next != NULL && iter->next->x != x) {
        iter = iter->next;
    }
     if(iter->next == NULL){
        printf("Sayi Bulunamadi");
        return r;
    }
    temp = iter->next;
    iter->next = iter->next->next;
    free(temp);
    return r;

}

int main(){
    node * root;
    root = NULL;
    root = ekleSirali(root,400);
    root = ekleSirali(root,40);
    root = ekleSirali(root,4);
    root = ekleSirali(root,450);
    root = ekleSirali(root,50);
    bastir(root);
    root = sil(root, 50);
    bastir(root);
    
}
