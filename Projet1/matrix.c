#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"



/* matrix_init
 * Créer une nouvelle matrice creuse.
 *
 * @nlines: nombre de lignes
 * @ncols: nombre de colonnes
 * @return: pointeur vers la matrice ou NULL si erreur
 *
 * Préconditions: @nlines > 0 && @ncols > 0
 * Postconditions: s éléments de la nouvelle matrice sont initialisés à 0.
 *		   @m->nlines > 0 && @m->ncols > 0
 */
struct matrix *matrix_init(unsigned int nlines, unsigned int ncols){
    //create the return matrix, currently NULL, with enough memory space
    struct matrix * mat_ret=(struct matrix *) malloc(sizeof(struct line)*nlines);
    struct line * head_l=(struct line *) malloc(sizeof(struct elem)*ncols);
    head_l=NULL;
    printf("Creation de head et mat_ret\n");
    size_t k;

    for(k=nlines;k>0;k--){    
        struct line* new_l =(struct line*) malloc(sizeof(struct elem)*ncols); 
        new_l->i=k-1;
        //Do a loop to add ncols elem to this line
        struct elem* head_e=(struct elem*) malloc(sizeof(struct elem));
        size_t l;
        for(l=ncols;l>0;l--){
            struct elem* new_e =(struct elem*) malloc(sizeof(struct elem));
            new_e->j=l-1;
            new_e->value=0;
            new_e->next=head_e;
            head_e=new_e;
            printf("Ajout d'une nouvelle cologne d'indice %d \n",l-1);
        }
        new_l->next=head_l;
        new_l->elems=head_e;
        head_l=new_l;
        printf("Ajout d'un nouvelle ligne d'indice %d \n",k-1);
    }
    mat_ret->nlines=nlines;
    mat_ret->ncols=ncols;
    mat_ret->lines=head_l;
    printf("Finalisation de la matrice\n");
    return mat_ret;
}

/* matrix_free
 * Libère la mémoire allouée à une matrice.
 *
 * @matrix: Matrice à libérer.
 *
 * Préconditions: /
 * Postconditions: La mémoire de @matrix est libérée.
 */
void matrix_free(struct matrix *matrix){
    //TODO
}

/* matrix_set
 * Défini la valeur d'un élément de la matrice.
 *
 * @matrix: Matrice
 * @i: numéro de ligne
 * @j: numéro de colonne
 * @val: valeur à définir
 * @return: -1 si erreur, 0 sinon
 *
 * Préconditions: 0 <= @i < @matrix->nlines && 0 <= @j < @matrix->ncols
 * Postconditions: L'élément (@i,@j) de la matrice @matrix vaut @val.
 */
int matrix_set(struct matrix *matrix, unsigned int i, unsigned int j, int val){
    //TODO
    return 0;   
}

/* matrix_get
 * Récupère la valeur d'un élément de la matrice.
 *
 * @matrix: Matrice
 * @i: numéro de ligne
 * @j: numéro de colonne
 * @return: valeur de l'élément (@i,@j) de la matrice
 *
 * Préconditions: 0 <= @i < @matrix->nlines && 0 <= @j < @matrix->ncols
 * Postconditions: @matrix est inchangé.
 */
int matrix_get(const struct matrix *matrix, unsigned int i, unsigned int j){
    //TODO
    return 0;
}

/* matrix_add
 * Additionne deux matrices.
 *
 * @m1: premier opérande
 * @m2: deuxième opérande
 * @return: Matrice creuse résultant de l'addition de @m1 et @m2,
 *	    ou NULL si erreur
 *
 * Préconditions: @m1 != NULL && @m2 != NULL
 * Postconditions: @m1 et @m2 inchangés.
 */
struct matrix *matrix_add(const struct matrix *m1, const struct matrix *m2){
    //TODO
    return NULL;
}

/* matrix_transpose
 * Calcule la transposée d'une matrice.
 *
 * @matrix: opérande
 * @return: Matrice creuse étant la transposée de @matrix
 *
 * Préconditions: @matrix != NULL
 * Postconditions: @matrix est inchangé.
 */
struct matrix *matrix_transpose(const struct matrix *matrix){
    //TODO
    return NULL;
}

/* matrix_convert
 * Transforme un tableau bidimensionnel en une matrice creuse.
 *
 * @array: tableau de valeurs à transformer
 * @nlines: nombre de lignes du tableau
 * @ncols: nombre de colonnes du tableau
 * @return: matrice creuse correspondante au tableau ou NULL si erreur
 *
 * Préconditions: array != NULL && 0 <= i < @nlines => array[i] != NULL
 * Postconditions: array est inchangé && 0 <= i < @nlines, 0 <= j < @ncols
 *		   => matrix_get(@return, i, j) == array[i][j]
 */
struct matrix *matrix_convert(const int **array, unsigned int nlines,
			      unsigned int ncols){
    //TODO
    return NULL;
}

int main(){
    struct matrix * mat = matrix_init(5,4);
    struct line* line1=mat->lines;
    struct line* line2=line1->next;
    printf("index of first line : %d, %d \n",line1->i,line1->elems->j);
    printf("index of second line : %d, %d \n",line2->i,line2->elems->j);

    return EXIT_SUCCESS;

}
