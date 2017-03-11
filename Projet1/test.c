#include <stdio.h>
#include <stdlib.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "matrix.h"

struct matrix* matrix=NULL;
struct matrix* matrix2=NULL;
struct matrix* matrix3=NULL;

// @matrix:test_init => [la fonction ne crée pas correctement la matrice]
void test_init(void){
    matrix=matrix_init(3,4);
    CU_ASSERT_EQUAL(matrix->nlines,3);
    CU_ASSERT_EQUAL(matrix->ncols,4);
    CU_ASSERT_PTR_NULL(matrix->lines);
}

// @matrix:test_get => [la fonction ne renvoit pas les valeurs correcte]]
void test_get(void){
    int *array[2];

    int arr_1[2] = { 1, 2};
    int arr_2[2] = { 3, 4};

    array[0] = arr_1;
    array[1] = arr_2;

    matrix=matrix_convert((const int**)array,2,2);
    int a=matrix_get(matrix,0,0);
    int b=matrix_get(matrix,0,1);
    int c=matrix_get(matrix,1,0);
    int d=matrix_get(matrix,1,1);
    CU_ASSERT_EQUAL(a,1);
    CU_ASSERT_EQUAL(b,2);
    CU_ASSERT_EQUAL(c,3);
    CU_ASSERT_EQUAL(d,4);
}

// @matrix:test_set => [la fonction n'attribue pas correctement les valeurs dans la matrice]
void test_set(void){
    matrix=matrix_init(2,2);
    int a=matrix_set(matrix, 0,0,1);
    int b=matrix_set(matrix,0,1,2);
    int c=matrix_set(matrix,1,0,3);
    int d=matrix_set(matrix,1,1,4);
    struct line* line=matrix->lines;
    struct elem* elem=line->elems;
    struct line* line2=line->next;
    struct elem* elem2=line2->elems;
    if(a==0 && b==0 && c==0 &&d==0){
        CU_ASSERT_EQUAL(elem->value,1);
        CU_ASSERT_EQUAL(elem->next->value,2);
        CU_ASSERT_EQUAL(elem2->value,3);
        CU_ASSERT_EQUAL(elem2->next->value,4);
    }
    else{
        CU_ASSERT_EQUAL(a,0);
        CU_ASSERT_EQUAL(b,0);
        CU_ASSERT_EQUAL(c,0);
        CU_ASSERT_EQUAL(d,0);
    }
}

// @matrix:test_convert => [la fonction ne converti pas correctement le tableau en matrice]
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

// @matrix:test_add => [la fonction n'additionne pas correctement deux matrices]
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
    matrix_free(matrix2);
    matrix_free(matrix3);

}

// @matrix:test_transpo => [la fonction ne fait pas correctement la transposée]
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
    matrix_free(matrix2);

}

/*
 *
 *
 */
void print(const struct matrix *matrix){
   struct line* line=matrix->lines;
   while(line!=NULL){
        struct elem* elem=line->elems;
        while(elem!=NULL){
            printf("%d ",elem->value);
            elem=elem->next;
        }
        printf("\n");
        line=line->next;
   }
}

//Fonction d'initialisation
int setup(void){
    return 0;
}
//Fonction de destruction
int teardown(void){
    matrix_free(matrix);
    return 0;
}


int main(void){
    if(CUE_SUCCESS !=CU_initialize_registry())
        return CU_get_error();

    CU_pSuite pSuite=NULL;
    
    //Initialisation de la suite de tests
    pSuite=CU_add_suite("matrix", setup, teardown);

    if(NULL==pSuite){
        CU_cleanup_registry();
        return CU_get_error();
    }
    
    //Ajout des test dans la suite
    if(NULL==CU_add_test(pSuite,"test_get", test_get)||
            NULL==CU_add_test(pSuite, "test_init", test_init)||
            NULL==CU_add_test(pSuite,"test_convert",test_convert)||
            NULL==CU_add_test(pSuite,"test_add",test_add)||
            NULL==CU_add_test(pSuite,"test_transpo",test_transpo)||
            NULL==CU_add_test(pSuite,"test_set",test_set)
    ){
        
        CU_cleanup_registry();
        return CU_get_error();
    }

    //Lancement des tests
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_basic_show_failures(CU_get_failure_list());
    printf("\n\n");
    CU_cleanup_registry();

    return CU_get_error();
/*
    int *array[3];

    int arr_1[4] = { 1, 2, 3, 4 };
    int arr_2[4] = { 5, 6, 7, 8 };
    int arr_3[4] = { 9, 10, 11, 12 };

    array[0] = arr_1;
    array[1] = arr_2;
    array[2] = arr_3;
    
    matrix=matrix_convert((const int**)array,3,4);
    int a=matrix_set(matrix,0,0,0);
    a=matrix_set(matrix,0,1,0);
    a=matrix_set(matrix,0,2,0);
    a=matrix_set(matrix, 0,3,0);
 a=matrix_set(matrix,1,0,0);
    a=matrix_set(matrix,1,1,0);
    a=matrix_set(matrix,1,2,0);
    a=matrix_set(matrix, 1,3,0);
 a=matrix_set(matrix,2,0,0);
    a=matrix_set(matrix,2,1,0);
    a=matrix_set(matrix,2,2,0);
    a=matrix_set(matrix, 2,3,0);



    print(matrix);

    matrix_free(matrix);



    return a;
    //return EXIT_SUCCESS;
*/
}
