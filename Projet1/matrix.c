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
    struct matrix * mat_ret=(struct matrix *) malloc(sizeof(struct matrix));
    mat_ret->lines=NULL;
    mat_ret->nlines=nlines;
    mat_ret->ncols=ncols;
    return mat_ret;

}

/* matrix_
 * Fonction auxilliaire à matrix_add qui permet de créer une matrice de la bonne taille
 *
 * @m1 : premier opérande
 * @m2 : second opérande
 * @return : matrice nulle de taille suffisament grande pour supporter l'addition
 *
 * Préconditions : @m1 != NULL && @m2 != NULL
 * PostConditions : @m1 et @m2 inchangés.
 */
struct matrix * matrix_(const struct matrix *m1, const struct matrix *m2){
    size_t lines, cols;
    if(m1->nlines > m2->nlines) lines=m1->nlines;
    else lines=m2->nlines;

    if(m1->ncols > m2->ncols) cols=m1->ncols;
    else cols=m2->ncols;

    struct matrix * mat_ret=matrix_init(lines,cols);
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
    struct line *current=matrix->lines;
    while(current !=NULL){
        struct elem *celem = current->elems;
        while(celem != NULL){
            struct elem *buffer =celem->next;
            free(celem);
            celem=buffer;
        }
        struct line * cline=current->next;
        free(current);
        current=cline;
    }
    free(matrix);
}


/*
 * matrix_checkline
 * Vérifie si une line existe déja dans la matrice
 *
 * @matrix: Matrice
 * @i: numéro de ligne
 * @return: 1 si la ligne existe, 0 sinon
 * Préconditions: TODO
 * Postconditions: TODO
 */
int matrix_checkline(const struct matrix* matrix, unsigned int i){
    struct line* line = matrix->lines;
    while(line !=NULL){
        if (line->i==i) return 1;
        line=line->next;
    }
    return 0;
}


/*
 * line_checkelem
 * Vérifie si un elem existe déja dans la line
 *
 * @line : Line
 * @j: numéro de elem
 * @return: 1 si l'elem existe, 0 sinon
 * Préconditions: TODO
 * Postconditions: TODO
 */
int line_checkelem(const struct line* line, unsigned int j){
    struct elem* elem = line->elems;
    while(elem !=NULL){
        if (elem->j==j) return 1;
        elem=elem->next;
    }
    return 0;
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
    int line_exist=matrix_checkline(matrix, i);
    //la ligne existe déja
    if(line_exist==1){
        struct line* cline=matrix->lines;
        while(cline->i!=i){
            cline=cline->next;
        }
        //on est a la bonne ligne, on va chercher le bon element
        int elem_exist=line_checkelem(cline,j);
        //TODO J'EN SUIS ICI LOL

    }
    //la ligne n'existe pas
    else{
    
    }
    /*
    if(matrix->lines!=NULL){
        struct line* cline=matrix->lines;
        while(cline !=NULL){
            if(cline->i==i){
                //la ligne existe et on doit chercher le bon elem
            }
            else{
                //la cline n'est pas du bon index
                //on définit un pointeur vers la ligne suivante
                struct line* next_line=cline->next;
                //Si la ligne suivante est nulle alors la ligne i n'existe pas
                if(next_line ==NULL){
                    // on crée la ligne d'index i à la suite  et on ajoute l'element j avec la valeur val
                    struct line* line=(struct line*) malloc(sizeof(struct line));
                    line->i=i;
                    line->next=NULL;
                    struct elem* elem=(struct elem*) malloc(sizeof(struct elem));
                    elem->j=j;
                    elem->value=val;
                    line->elems=elem;

                }
                //la ligne suivante n'est pas nulle
                else{
                    if(cline->next->i>i){
                        
                    }
                }
            }
        }
    }
    else{
        if(val!=0){
            struct line* line=(struct line*) malloc(sizeof(struct line));
            line->i=i;
            line->next=NULL;
            struct elem* elem=(struct elem*) malloc(sizeof(struct elem));
            elem->j=j;
            elem->value=val;
            elem->next=NULL;
            line->elems=elem;
            matrix->lines=line;
        }
    }*/
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
    struct line* line=matrix->lines;
    struct elem* elem;
    int find =1;
    while(line!=NULL&&find ==1){
        if(i==line->i){
            elem=line->elems;
            find=0;

        }
        else{
            line=line->next;
        }
    }
    if(find==1) return 0;
    while(elem!=NULL){
        if(j==elem->j) return elem->value;
        else{
            elem=elem->next;
        }
    }         
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
    struct matrix * matrix=matrix_(m1, m2);
    size_t i,j;
    for(i=0;i<matrix->nlines;i++){
        for(j=0;j<matrix->ncols;j++){

            matrix_set(matrix,i,j,matrix_get(m1,i,j)+matrix_get(m2,i,j));
        }
    }
    return matrix;
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
    struct matrix * mat_ret = matrix_init(matrix->ncols, matrix->nlines);
    size_t i,j;
    // On parcourt la matrice en argument et on ajoute chaque élément dans
    // la nouvelle matrice avec les index i et j inversés.
    for(i=0;i<matrix->nlines;i++){
        for(j=0;j<matrix->ncols;j++){
            matrix_set(mat_ret,j,i,matrix_get(matrix,i,j));
        }
    }
    // On retourne la nouvelle matrice correctement transposée.
    return mat_ret;
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
    struct matrix * matrix = matrix_init(nlines,ncols);
    size_t i,j;
    // Pour chaque élément du tableau en index [i][j], on va l'ajouter à la
    // matrice en [i][j] en faisant attention à respecter les invariants
    for(i=0;i<nlines;i++){
        for(j=0;j<ncols;j++){
            matrix_set(matrix, i, j, array[i][j]);
        }
    }
    return matrix;
}

void print(const struct matrix *matrix){
    size_t k=matrix->nlines;
    size_t l=matrix->ncols;
    size_t i,j;
    for(i=0;i<k;i++){
        for(j=0;j<l;j++){

            int value=matrix_get(matrix,i,j);
            printf("%d ",value);
        }
        printf("\n");
    }    	
}

int main(){
    struct matrix * mat = matrix_init(5,4);
    int a=matrix_set(mat, 1,1,1);
    printf("a = %d\n",a);
    a=matrix_set(mat ,2,2,2);
    printf("a = %d\n",a);
    print(mat);
        //struct line* line1=mat->lines;
    //struct line* line2=line1->next;
    //printf("index of first line : %d, %d \n",line1->i,line1->elems->j);
    //printf("index of second line : %d, %d \n",line2->i,line2->elems->j);

    matrix_free(mat);
    //free(elem1);
    //free(line1);
    //free(mat);
    return EXIT_SUCCESS;

}
