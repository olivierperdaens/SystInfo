#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 *  * @pre 0<n<strlen(str), str!=NULL, str se termine par '\0'
 *   * @post dans un tableau deux pointeurs vers deux chaînes de caractères
 *    *       terminées par '\0'. La première (indice 0) contient
 *     *       les caractères en positions 0 à n-1 dans str.
 *      *       La seconde le reste de la chaîne str.
 *       *       En cas d'erreur, retourne NULL en ayant libéré correctement
 *        *       tout mémoire allouée avant l'erreur.
 *         *
 *          * Contrainte : la seule fonction de manipulation des chaînes de caractères
 *           *              que vous pouvez utiliser est strlen. Les autres (e.g.
 *            *              strcat, strncat, strstr, ...) sont interdites. Vous pouvez
 *             *              bien entendu utiliser malloc et free.
 *              */

char** strsplit(const char *str, int n) {
    int size=strlen(str);
    char** ret=(char**) malloc(sizeof(char*));
    ret[0]=(char*)malloc(sizeof(char)*n);
    ret[1]=(char*)malloc(sizeof(char)*(size-n));
    int i;
    for(i=0;i<size;i++){
        if(i<n){
            ret[0][i]=str[i];
        }   
        else{
            ret[1][i-n]=str[i];
        }
    }
    return ret;
}

int main(){
    char* str=(char*) malloc(100*sizeof(char));
    str="Segmentation";
    char** strret=strsplit((const char*) str, 4);

    printf("%s devient :%s - %s \n",str, strret[0],strret[1]);
    free(str);
    free(strret[0]);
    free(strret[1]);
    return EXIT_SUCCESS;
}
