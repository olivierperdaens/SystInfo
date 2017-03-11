#include <stdio.h>
#include <stdlib.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "matrix.h"

struct matrix* matrix=NULL;
struct matrix* matrix2=NULL;
struct matrix* matrix3=NULL;


void test_init(void){
    matrix=matrix_init(3,4);
    CU_ASSERT_EQUAL(matrix->nlines,3);
    CU_ASSERT_EQUAL(matrix->ncols,4);
    CU_ASSERT_PTR_NULL(matrix->lines);
}
void test_convert(void){
    int *array[2];

    int arr_1[2] = { 1, 2};
    int arr_2[2] = { 3, 4};

    array[0] = arr_1;
    array[1] = arr_2;


    matrix=matrix_convert((const int**)array,2,2);
    struct line* line=matrix->lines;
    struct elem* elem=line->elems;
    struct line* line2=line->next;
    struct elem* elem2=line2->elems;
    CU_ASSERT_EQUAL(elem->value,array[0][0]);
    CU_ASSERT_EQUAL(elem->next->value,array[0][1]);
    CU_ASSERT_EQUAL(elem2->value,array[1][0]);
    CU_ASSERT_EQUAL(elem2->next->value,array[1][1]);

}

void test_add(void){
    int *array[2];

    int arr_1[2] = { 1, 2};
    int arr_2[2] = { 3, 4};

    int arr_3[2] = { 2, 3};
    int arr_4[2] = { 4, 5};

    array[0] = arr_1;
    array[1] = arr_2;
    
    int *array2[2];

    array2[0] = arr_3;
    array2[1] = arr_4;
    matrix=matrix_convert((const int**)array,2,2);
    matrix2=matrix_convert((const int**)array2,2,2);
    matrix3=matrix_add((const struct matrix*)matrix, (const struct matrix*)matrix2);
    struct line* line=matrix3->lines;
    struct elem* elem=line->elems;
    struct line* line2=line->next;
    struct elem* elem2=line2->elems;
    CU_ASSERT_EQUAL(elem->value,3);
    CU_ASSERT_EQUAL(elem->next->value,5);
    CU_ASSERT_EQUAL(elem2->value,7);
    CU_ASSERT_EQUAL(elem2->next->value,9);


}

void test_transpo(void){
    int *array[2];

    int arr_1[2] = { 1, 2};
    int arr_2[2] = { 3, 4};
    array[0] = arr_1;
    array[1] = arr_2;

    matrix=matrix_convert((const int**)array,2,2);
    matrix2=matrix_transpose((const struct matrix*)matrix);
    struct line* line=matrix2->lines;
    struct elem* elem=line->elems;
    struct line* line2=line->next;
    struct elem* elem2=line2->elems;

    CU_ASSERT_EQUAL(elem->value,1);
    CU_ASSERT_EQUAL(elem->next->value,3);
    CU_ASSERT_EQUAL(elem2->value,2);
    CU_ASSERT_EQUAL(elem2->next->value,4);


}


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

int setup(void){
    return 0;
}

int teardown(void){
    matrix_free(matrix);
    matrix_free(matrix2);
    matrix_free(matrix3);
    return 0;
}


int main(void){
    if(CUE_SUCCESS !=CU_initialize_registry())
        return CU_get_error();

    CU_pSuite pSuite=NULL;
    //CU_pSuite pSuite2=NULL;

    pSuite=CU_add_suite("matrix", setup, teardown);

    if(NULL==pSuite){
        CU_cleanup_registry();
        return CU_get_error();
    }
    if(NULL==CU_add_test(pSuite, "test_init", test_init)||
            NULL==CU_add_test(pSuite,"test_convert",test_convert)||
            NULL==CU_add_test(pSuite,"test_add",test_add)||
            NULL==CU_add_test(pSuite,"test_transpo",test_transpo)){
        
        CU_cleanup_registry();
        CU_get_error();
    }

    //lancement des tests
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_basic_show_failures(CU_get_failure_list());
    printf("\n\n");
    CU_cleanup_registry();

    return CU_get_error();
}
