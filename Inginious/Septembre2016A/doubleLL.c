#include<stdio.h>
#include<stdlib.h>

// Noeud de la liste chaînée
typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} node;

// La liste doublement chaînée. Cette liste comprend un premier
// noeud vide qui ne contient pas de donnée utile. Les données
// utiles sont stockées à partir du second noeud.

typedef struct List {
    node *start;  // pointe toujours vers le premier élément
    node *tail;   // pointe toujours vers le dernier élément
} list;

/*
 *  * @pre l!=NULL
 *   * @post a initialisé la liste doublement chaînée l. Une liste vide
 *    *       contient toujours un premier noeud qui est vide
 *     *       et dont les pointeurs next et prev pointent vers NULL
 *      *       retourne 0 en cas de succès, -1 en cas d'erreur
 *       */

int list_init(list *l) {

    l->start=malloc(sizeof(node));
    if(l->start==NULL)
        return -1;
    l->start->next=NULL;
    l->start->prev=NULL;
    l->start->data=-1;
    l->tail=l->start;
    return 0;
}

/*
 *  * @pre l!=NULL
 *   * @post insert à la fin de la liste un noeud content la donnée data
 *    *       retourne -1 en cas d'erreur, 0 sinon
 *     */
int insert(list *l, int data)
{
    node *pointer;
    pointer = (node *)malloc(sizeof(node));
    if(pointer==NULL)
        return -1;
    l->tail->next=pointer;
    pointer->prev=l->tail;
    l->tail=pointer;
    pointer->data = data;
    pointer->next = NULL;
    return 0;
}

/*
 *  * @pre l!=NULL
 *   * @post a retiré de la liste l tous les noeuds dont la donnée
 *    *       est key
 *     *       retourne le nombre de noeuds retirés, -1 en cas d'erreur
 *      */
int delete(list *l, int key){
    node* current=l->start;
    if (current==NULL) return -1;
    int count=0;

    while(current!=NULL){
        if(current->data==key){
            count++;
            if(current==l->start){
                l->start=current->next;
            }
            else{
                current->prev->next=current->next;
            }
            if(current==l->tail){
                l->tail=current->prev;
            }
            else{
                current->next->prev=current->prev;
            }
            free(current);
        }
        current=current->next;
        if(current==NULL) return count;
    }
    return count;

