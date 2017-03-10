#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"



void print(const struct matrix *matrix){
    size_t k=matrix->nlines;
    size_t l=matrix->ncols;
    size_t i,j;
    for(i=0;i<k;i++){
        for(j=0;j<l;j++){

            int value=matrix_get(matrix,i,j);
            if(value!=0)printf("%d ",value);

        }
        printf("\n");
    }    	
}


int main(){

    int *array[3];
    int arr_1[4] = { 0, 2, 3, 4, };
    int arr_2[4] = { 5, 0, 7, 8, };
    int arr_3[4] = { 9, 10, 11, 12, };

    array[0] = arr_1;
    array[1] = arr_2;
    array[2] = arr_3;
    struct matrix* mat=matrix_convert((const int**)array,3,4);

    print(mat);
   
    //int a=matrix_set(mat,0,2,0);
    //if(a==0)print(mat);
    matrix_free(mat);
    /*struct matrix * mat = matrix_init(5,4);
    int a=matrix_set(mat, 1,2,1);
    printf("a = %d\n",a);
    print(mat);
    a=matrix_set(mat ,1,1,3);
    printf("\n");
    print(mat);
    a=matrix_set(mat,2,1,1);
    printf("\n");

    print(mat);
    //struct line* line1=mat->lines;
    //struct line* line2=line1->next;
    //printf("index of first line : %d, %d \n",line1->i,line1->elems->j);
    //printf("index of second line : %d, %d \n",line2->i,line2->elems->j);

    matrix_free(mat);*/
    return EXIT_SUCCESS;
}
