#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define N 40                   /* taille du buffer */
static pthread_mutex_t mutex;  /* mutex du buffer */
static sem_t empty;            /* si &gt; 0 alors il y a des places libres dans le buffer */
static sem_t full;             /* si &gt; 0 alors il y a des données dans le buffer */

void init(){
    int ret1 = pthread_mutex_init(&mutex, NULL);
    int ret2 = sem_init(&empty,0,N);
    int ret3 = sem_init(&full,0,0);
    if(ret1 !=0 || ret2 !=0 || ret3 !=0) return;

}

void produceur(int max){
    int i;
    int item;
    for(i=0; i<max; i++){
        item=produce();
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        insert(item);
        pthread_mutex_unlock(&mutext);
        sem_post(&full);
        
    }
}
