#include <stdio.h>
#include <stdlib.h>

//circular linked list (dairesel bağlı liste)
 
struct n{
 int x;
 struct n * next;
};

typedef struct n node;

void bastir( node * r){
  node * iter=r;
  printf("%d ", iter->x);
  iter = iter -> next;
 while (iter != r){
  printf("%d ", iter->x);
  iter = iter -> next;
 }
 printf("\n");
}


void ekle( node * r, int x){
  node * iter=r;
 while( iter -> next != r){
  iter =iter -> next;
 }
 iter->next=( node * ) malloc ( sizeof ( node ) );
 iter->next->x=x;
 iter->next->next=r;
}


node * ekleSirali ( node * r, int x){
 if( r == NULL){      //if circular linked list is empty
  r = (node *) malloc ( sizeof ( node) );
  r -> next = r;
  r -> x = x;
  return r;
 }
 if(r->x > x){ 
  node * temp = ( node * ) malloc ( sizeof ( node ) );
  temp -> x = x;
  temp -> next = r;
  node * iter=r;
  while(iter->next!=r){
    iter=iter->next;
  }
  iter->next=temp;
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


node * sil(node *r, int x){
 node *temp;
 node *iter = r;
 if( r->x == x){
   while(iter->next!=r){
     iter=iter->next;
   }
   iter->next=r->next;
   free(r);
   return iter->next;
 }
 
 while ( iter->next != r && iter->next->x != x){
  iter = iter->next;
 }
 if ( iter->next == r){
  printf( "Sayi bulunamadi!\n" );
  return r;
 }
 temp = iter->next;
 iter->next = iter->next->next; 
 free (temp);
 return r;
}


int main ()
{
 node * root;
 root = NULL;
 root = ekleSirali( root, 400);
  bastir(root);
 root = ekleSirali( root, 40);
   bastir(root);
 root = ekleSirali( root, 4);
   bastir(root);
 root = ekleSirali( root, 450);
   bastir(root);
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
}
