/*
 *
 *  * Un employé d'une entreprise
 *   */

typedef struct employe {
    char *name;  // nom de l'employé
    unsigned int age; // âge de l'employé
} Employe;
/*
 *  * Un noeud de la liste
 *   */
typedef struct node {
    void *data; // pointeur vers la donnée stockée
    struct node *next; // pointeur vers le noeud suivant
} Node;

/*
 *  * @pre list!=NULL
 *   * @post initialise la liste chaînée
 *    */
void initializeList(LinkedList *list) {
    list->head=NULL;
    list->tail=NULL;
}

/*
 *  * @pre list!=NULL, data!=NULL, data pointe vers Employe
 *   * @post Crée un noeud contenant un pointeur vers data
 *    *       et l'ajoute en début de liste
 *     *       retourne un pointeur vers le noeud créé, NULL en cas d'erreur
 *      */
Node * addHead(LinkedList *list, void *data) {
    Node *node= (Node *) malloc(sizeof(Node));
    if(node==NULL)
        return NULL;
    node->data=data;
    if(list->head==NULL) {
        list->tail=node;
        node->next=NULL;
    } else {
        node->next=list->head;
    }
    list->head=node;
    return node;
}

/*
 *  * @pre list!=NULL, age>0
 *   * @post retire de la liste tous les employés strictement plus jeunes
 *    *       que age. Retourne le nombre d'employés retirés de la
 *     *       liste, -1 en cas d'erreur.
 *      */
int deleteAllYounger(LinkedList *list, int age) {
    if(list->head==NULL) return 0;
    Node* prev;
    Node* current= list->head;
    int age2;
    int count=0;
    Employe* empl;
    while(current!=NULL){
        empl=(Employe*) current->data;
        age2=empl->age;
        if(age2<age){
            if(current=list->head){
                list-head=current->next;
            }
            if(current=list->tail){
                list->tail=prev;
            }
            count++;
            prev->next=current->next;
            free(current);
            current=prev->next;
        }
        else{
            prev=current;
            current=current->next;
        }
    }

    if(list->head==NULL){
        list->tail=NULL;
    }
    return count;
}
