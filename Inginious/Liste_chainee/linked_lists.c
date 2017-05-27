#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value; /* valeur du nœud */
  struct node *next; /* pointeur vers l’élément suivant */
} node;

void reverse(node **list){
  node* head=NULL;
  node* next;
  node* current=*list;
  while(current !=NULL){
    next=current->next;
    current->next=head;
    head=current;
    current=next;
  }
  *list=head;
}

node *append(node *a, node *b){
  if(a==NULL) return b;
  if(b==NULL) return a;
  node* node_ret=a;
  while(a->next !=NULL) a=a->next;
  a->next=b;
  return node_ret;
}

void split(node *list, node **first_half, node **second_half){
  if(list == NULL){
    *first_half==NULL;
    *second_half==NULL;
    return;
  }

  int count1=0;
  node* next_node=list;
  while(next_node !=NULL){
    count1++;
    next_node=next_node->next;
  }

  *first_half=list;
  int half=(int)(((float)(count1)/2)+0.5);
  struct node* tmp = list;
  int i;
  for(i=0;i<half && list!=NULL;i++){
    list=list->next;
  }
  *second_half=list;
  for(i=1; i<half;i++)
  tmp = tmp->next;
  tmp->next = NULL;

}
