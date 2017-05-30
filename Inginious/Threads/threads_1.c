#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void * fthread(void * n){
    if(n==NULL) return NULL; 
    size_t size= (size_t) n;
    int *tab = tab_init(size);
    pthread_exit(tab);
}

int * getThreadRet(pthread_t th){
    void * ptr ;
    int err = pthread_join(th, &ptr) ;
    if(err != 0)
    {
            return NULL ;
    }
    return (int *)ptr ;
}

int runThread(pthread_t * th, unsigned int *n){
    int err=pthread_create(th, NULL, &fthread, &n);
    return err;
}
