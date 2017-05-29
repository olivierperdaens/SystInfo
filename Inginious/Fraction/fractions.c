#include <stdio.h>
#include <stdlib.h>
#include "fractions.h"

int fraction_compare(const void * a, const void * b){
    fraction_t* frac1=(fraction_t*) a;
    fraction_t* frac2=(fraction_t*) b;
    float resultf1 = ((float) (frac1->numerateur)) / ((float) (frac1->denominateur));
    float resultf2 = ((float) (frac2->numerateur)) / ((float) (frac2->denominateur));
    if(resultf1 > resultf2){
        return 1;
    }
    else if(resultf1 < resultf2){
        return -1;
    }
    return 0;
}


void fraction_sort(fraction_t * tab, size_t len){
    qsort(tab, len, sizeof(fraction_t), fraction_compare);    
}

void fraction_sortIgnore3fl(fraction_t * tab, size_t len){
    fraction_t * tabF=fraction_t[len-6];
    int i;

    for(i=0;i<len-6;i++){
        tabF[i]=tab[i+3];
    }
    fraction_sort(tabF,len-6);

    for(i=0;i<len-6;i++){
        tab[i+3]=tabF[i];
    }
}


int main(void){
    fraction_t* f1=(fraction_t*) malloc(sizeof(fraction_t));
    fraction_t* f2=(fraction_t*) malloc(sizeof(fraction_t));
    f1->numerateur=1;
    f2->numerateur=1;
    f1->denominateur=2;
    f2->denominateur=3;
    int result=fraction_compare((const void *) f1, (const void*) f2);
    printf("%d \n",result);
    return EXIT_SUCCESS;
}
