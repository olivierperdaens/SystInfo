#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int value;
    struct node *next;
}node;

size_t length(node *list){
    size_t count=0;
    struct node *head=list;
    while(head!= NULL){
        count++;
        head=head->next;
    }
    return count;
}

size_t count(node *list, int value){
    size_t count=0;
    struct node *head=list;
    while(head!=NULL){
    if ((*head).value==value) count++;
        head=head->next;
    }
    return count;
}
int push(node **list, int value){
    struct node *new;
    new=(struct node*)malloc(sizeof(struct node));
    if(new==NULL) return -1;
    new->value=value;
    new->next=*list;
    *list=new;
    return 0;
}
int pop(node ** list){
    node *next_node=(*list)->next;
    int val=(*list)->value;
    free(*list);
    *list=next_node;
    return val;
}
void free_list(node *list){
        
        free(list);
    
}
int main(int argc, char *argv[]){
    struct node *n1=(struct node *)malloc(sizeof(struct node));
    struct node *n2=(struct node *)malloc(sizeof(struct node));
    
    n1->value=1;
    n1->next=NULL;
    n2->value=2;
    n2->next=n1;
    struct node **np=&n2;

    printf("This list has %d elements \n",length(*np));
    printf("This list has %d occurences of %d \n",count(n2, 3),3);

    int p=push(np,0);
    if(p==0)printf("Succes\n");
    else printf("Echec\n");
    printf("This list has %d elements \n",length(*np));
    
    int pp=pop(np);
    printf("The pop element is %d \n",pp);
    printf("This list has %d elements \n",length(*np));

    free_list(*np);
    return EXIT_SUCCESS;
}
