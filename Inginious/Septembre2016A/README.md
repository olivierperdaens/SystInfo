# asm3.c 
## Traduction de code assembleur
La fonction suivante a été écrite en assembleur. Traduisez la en une version équivalente en C. Votre fonction doit nécessairement avoir comme nom mp.

```assembly
mp:
  subl $8, %esp
  movl 16(%esp), %edx
  movl 12(%esp), %ecx
  movl %ecx,%eax
  addl %ecx,%ecx
  addl %eax,%ecx
  cmpl %edx,%ecx
  jle m1
  movl %edx, %eax
  addl $8, %esp
  ret
 m1:
  movl %ecx, %eax
  addl $8, %esp
  ret
```

# PC.c
## Producteurs/Consommateurs
Une librairie supportant un buffer partagé utilisé pour résoudre le problème des "Producteurs/Consommateurs" est implémentée comme suit.

```c
typedef struct {
    int *buf;          /* Buffer partagé */
    int n;             /* Nombre de slots dans le buffer */
    int front;         /* buf[(front+1)%n] est le premier élément */
    int rear;          /* buf[rear%n] est le dernier */
    sem_t mutex;       /* Protège l'accès au buffer */
    sem_t slots;       /* Nombre de places libres */
    sem_t items;       /* Nombre d'items dans le buffer */
} sbuf_t;

/*

Stockage d'un vecteur de réels dans un fichier
 * @pre sp!=NULL, n>0
 * @post a construit un buffer partagé contenant n slots
 */
void sbuf_init(sbuf_t *sp, int n)
{
    sp->buf = calloc(n, sizeof(int));
    sp->n = n;                       /* Buffer content les entiers */
    sp->front = sp->rear = 0;        /* Buffer vide si front == rear */
    sem_init(&sp->mutex, 0, 1);      /* Exclusion mutuelle */
    sem_init(&sp->slots, 0, n);      /* Au début, n slots vides */
    sem_init(&sp->items, 0, 0);      /* Au début, rien à consommer */
}

/*
 * @pre sp!=NULL
 * @post libère le buffer
 */
void sbuf_clean(sbuf_t *sp)
{
    free(sp->buf);
}

/* @pre sp!=NULL
 * @post ajoute item à la fin du buffer partagé. Ce buffer est géré
 *       comme une queue FIFO
 */
void sbuf_insert(sbuf_t *sp, int item)
{
  // à compléter
```

# DoubleLL.c
## Liste doublement chaînée
Une liste doublement chaînée est implémentée comme suit. Notez que suite à l'implémentation de la fonction list_init, le premier noeud de la liste est toujours vide et ne contient aucune donnée. Vous devez implémenter la fonction delete dont les spécifications vous sont fournies.
```c
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
 * @pre l!=NULL
 * @post a initialisé la liste doublement chaînée l. Une liste vide
 *       contient toujours un premier noeud qui est vide
 *       et dont les pointeurs next et prev pointent vers NULL
 *       retourne 0 en cas de succès, -1 en cas d'erreur
 */

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
 * @pre l!=NULL
 * @post insert à la fin de la liste un noeud content la donnée data
 *       retourne -1 en cas d'erreur, 0 sinon
 */
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
 * @pre l!=NULL
 * @post a retiré de la liste l tous les noeuds dont la donnée
 *       est key
 *       retourne le nombre de noeuds retirés, -1 en cas d'erreur
 */
int delete(list *l, int key)
{
```

# Vectorfile.c
## Stockage d'un vecteur de réels dans un fichier
Afin de compléter une librairie permettant de stocker et de manipuler des vecteurs contenant des réels en les plaçant dans des fichiers plutôt qu'en mémoire, vous devez implémenter la fonction swap en utilisant uniquement les appels systèmes suivants: open, read, write et close. Le code de la fonction create de la librairie vous est fournie.
```c
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/*
 * Implementation de vecteurs en utilisation des fichiers
 * La donnée à l'indice zéro correspond aux sizeof(double)
 * premiers bytes du fichier, la deuxième aux suivantes, etc.
 * La taille d'un tel fichier est toujours un multiple
 * entier de sizeof(double)
 */

/*
 * @pre *filename!=NULL, size>0
 * @post construit un fichier contenant size double à la valeur val
 *       retourne le nombre de données écrites, -1 en cas d'erreur
 */
int create(char *filename, int size, double val) {

  int err;
  int fd=open(filename,O_RDWR|O_CREAT,S_IRUSR|S_IWUSR);
  if(fd==-1) {
    return -1;
  }
  for(int i=0; i<size; i++) {
    err=write(fd,(void *) &val, sizeof(double));
    if(err<0) {
       err=close(fd);
       return(-1);
     }
   }
   err=close(fd);
   if(err==-1)
     return err;
   else
     return size;
 }

/*
 * @pre filename!=NULL, 0 <= i*sizeof(double) < taille fichier,
 *       0 <= j*sizeof(double) < taille fichier
 * @post échange les données aux indices i et j dans
 *       le vectorfile (0 est le premier indice)
 *       retourne 0 en cas de succès, -1 si erreur
 */

int swap(char *filename, int i, int j) {
```
