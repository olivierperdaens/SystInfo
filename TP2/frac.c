#include <stdio.h>
#include <stdlib.h>

struct fract_t{
    int num;
    int denum;
};

void swap(struct fract_t *a, struct fract_t *b){
    struct fract_t temp=*a;
    *a=*b;
    *b=temp;
}

int main(int argc, char *argv[]){
    struct fract_t f1={1,2};
    struct fract_t f2={3,4}; 
    printf("Les valeurs de la fraction f1 sont : %d %d \n", f1.num, f1.denum);
    printf("Les valeurs de la fraction f2 sont : %d %d \n", f2.num, f2.denum);
    swap(&f1, &f2);
    printf("Les valeurs de la fraction f1 sont : %d %d \n", f1.num, f1.denum);
    printf("Les valeurs de la fraction f2 sont : %d %d \n", f2.num, f2.denum);

    return EXIT_SUCCESS;
}
