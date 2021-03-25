#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
  unsigned int key;
  struct node *next;
  struct node *prev;
};

typedef struct node * NodePointer;

NodePointer nil;

NodePointer listSearch(int key){
  /* your code */
  NodePointer p;
  for(p=nil->next;p!=nil;p=p->next){
      if(p->key==key)return p;
  }
}

void init(){
  nil = malloc(sizeof(struct node));
  nil->next = nil;
  nil->prev = nil;
}

void printList(){
  NodePointer cur = nil->next;
  int isf = 1;
  while(1){
    if ( cur == nil ) break;
    if ( isf == 0)  printf(" ");
    printf("%d", cur->key);
    cur = cur->next;
    isf = 0;
  }
  printf("\n");
}

void deleteNode(NodePointer t){
  /* your code */
  t->prev->next=t->next;
  t->next->prev=t->prev;
  free(t);
}

void deleteFirst(){
  NodePointer t = nil->next;
  if ( t == nil ) return;
  deleteNode(t);
}

void deleteLast(){
  /* your code */
  NodePointer t = nil->prev;
  if ( t == nil ) return;
  deleteNode(t);
}

void delete(int key){
  /* your code */
  NodePointer p;
  p=listSearch(key);
  deleteNode(p);
}


void insert(int key){
    NodePointer x;
    x = malloc(sizeof(struct node));
    x->key = key;
    /* 
    your code 
    */
    x->prev=nil;
    x->next=nil->next;
    nil->next->prev=x;
    nil->next=x;
}

int main(){
  int key, n, i;
  int size = 0;
  char com[20];
  int np = 0, nd = 0;
  scanf("%d", &n);
  init();
  for ( i = 0; i < n; i++ ){
    scanf("%s%d", com, &key);
    if ( com[0] == 'i' ) {                         //intsert x
        insert(key); np++; size++;
    }else if ( com[0] == 'd' ) {                   //delete~
        if (strlen(com) > 6){
	        if ( com[6] == 'F' ) deleteFirst();    //deleteFirst
	        else if ( com[6] == 'L' ) deleteLast();//deletelast
        }else{
	        delete(key); nd++; //delete x
        }
        size--;
    }
  }

  printList();
  return 0;
}