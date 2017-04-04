#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int * tab;

void * fthread(void * n){
    size_t size= (size_t) n;
    int *tab = tab_init(size);
    return tab;
}

int * getThreadRet(pthread_t th){
    pthread_t * thread;
    void * ret;
    pthread_join(&th,&ret) ;
    return (int *) ret; 
}

int runThread(pthread_t *th, unsigned int *n){
    int err;
    err=pthread_create(th, NULL, fthread, (void *) n);
    if(err !=0){
        return EXIT_FAILURE;
    }

}
