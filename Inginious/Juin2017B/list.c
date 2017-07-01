struct node {
    int data;          // donnée stockée
    struct node* prev;  // prédécesseur
    struct node* next;  // successeur
};

struct double_linked_list{
    struct node* head;
    struct node* tail;
};

/*
 * @pre list!=NULL
 * @post retire de la liste tous les éléments ayant la valeur data
 * @return le nombre d'éléments retirés de la liste, -1 en cas
 *          d'erreur suite à l'échec d'un appel système
 */
int remove_all(struct double_linked_list *list, int data) {
    if(list->head==NULL) //liste vide
        return 0;
    if(list->tail==NULL) //liste vide
        return 0;


    int count=0;

    struct node* current=list->head;
    while(current!=NULL){
        if(list->head==list->tail){//un seul élément dans la liste
            if(list->head->data==data){
                free(list->head);
                list->head=NULL;
                list->tail=NULL;
                count++;
            }
            return count;
        }
        struct node* temp=current;
        if(current->data==data){//on doit enlever cet element de la liste
            count++; //on a trouvé un element à retirer
            if(current==list->head){ //il s'agit de la tête
                current->next->prev=NULL; //le deuxieme element aura comme prev NULL
                list->head=current->next; //la tête devient le deuxieme élément
            }
            else if(current==list->tail){//il s'agit de la queue
                current->prev->next=NULL;
                list->tail=current->prev;
            }
            else{
                current->prev->next=current->next;
                current->next->prev=current->prev;
            }
            current=current->next;
            free(temp);
        }
        else{
            current=current->next;
        }
    }
    return count;
}

int add_after_first_matching(struct double_linked_list *list, int data, int (*match_func)(int)) {
    struct node* new=(struct node*)malloc(sizeof(struct node));
    if(new==NULL)
        return -1;
    new->data=data;

    struct node* current=list->head;
    if(current==NULL){
        new->prev=NULL;
        new->next=NULL;
        list->head=new;
        list->tail=new;
        return 0;
    }
    while(1){
        if(list->tail==current){
            current->next=new;
            new->prev=current;
            new->next=NULL;
            list->tail=new;
            return 0;
        }
        else{
            if(match_func(current->data)==1){
                new->next=current->next;
                new->prev=current;
                current->next->prev=new;
                current->next=new;
                return 0;
            }
            else{
                current=current->next;
            }
        }
    }
    return -1;
}

