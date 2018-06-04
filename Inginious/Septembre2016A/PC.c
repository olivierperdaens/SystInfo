#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

    
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
 *  * @pre sp!=NULL, n>0
 *   * @post a construit un buffer partagé contenant n slots
 *    */
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
 *  * @pre sp!=NULL
 *   * @post libère le buffer
 *    */
void sbuf_clean(sbuf_t *sp)
{
    free(sp->buf);
}

/* @pre sp!=NULL
 *  * @post ajoute item à la fin du buffer partagé. Ce buffer est géré
 *   *       comme une queue FIFO
 *    */
void sbuf_insert(sbuf_t *sp, int item){
    sem_wait(&sp->slots);
    sem_wait(&sp->mutex);
    sp->rear++;
    sp->buf[(sp->rear)%(sp->n)]=item;
    sem_post(&sp->mutex);
    sem_post(&sp->items);
}

int sbuf_remove(sbuf_t *sp){
    int ret;
    sem_wait(&sp->items);
    sem_wait(&sp->mutex);
    ret=sp->buf[(sp->front+1)%(sp->n)];
    sp->buf[(sp->front+1)%(sp->n)]=0;
    sp->front++;
    sem_post(&sp->mutex);
    sem_post(&sp->slots);
}
