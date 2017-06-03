#include <stdio.h>      /* Standard Library of Input and Output */
#include <stdlib.h>
#include <complex.h>    /* Standard Library of Complex Numbers */
/*
 *  * @pre *filename!=NULL, size>0
 *   * @post construit un fichier contenant size nombre complexes contenant les
 *    *       valeurs 1+i, 1+2i, 1+3i, ... 1+size*i
 *     *       retourne size en cas de succès et -1 en cas d'erreur
 *      */
int create(char *filename, int size) {

    int err;
    int fd=open(filename,O_RDWR|O_CREAT,S_IRUSR|S_IWUSR);
    if(fd==-1) {
        return -1;
    }
    for(int i=1; i<=size; i++) {
        complex val;
        val.r=1;
        val.i=i;
        err=write(fd,(void *) &val, sizeof(complex));
        if(err<0) {
            err=close(fd);
            return(-1);
        }
    }
    err=close(fd);
    if(err==-1)
        return err;
    else
        return size;
}

/*
 *  * @pre filename1!=NULL, filename2!=NULL
 *   *      Les deux fichiers contiennent un nombre entier de complexes,
 *    *      Tous les nombres complexes se trouvant dans un fichier sont
 *     *      différents.
 *      *
 *       * @post retourne le nombre de complexes qui se trouvent à
 *        *       la fois dans le fichier filename1 et le fichier filename2
 *         *       -1 si erreur
 *          *
 *           * Contrainte: Vous pouvez uniquement utiliser les fonctions open,
 *            *             read, write, close, mmap et munmap pour accéder aux
 *             *             fichiers
 *              */

int count_same(char *filename1, char *filename2) {
    int i=1;
    int j=1;
    int count=0;
    struct stat st1;
    struct stat st2;
    int err1=1;
    int err2=1;

    int fd1=open(filename1,O_RDONLY);
    if(fd==-1) return -1;
    if(fd==0) return 0;
    
    if(fstat(fd1,&st1)<0)return -1;
    
    int size1=st1.st_size/sizeof(complex);
    if(size1==0) return 0;
    while(i<=size1 | err1 !=0){
        complex* valTab1=malloc(sizeof(complex));
        err1=read(fd1,(void*)valTab1, sizeof(complex));
        if(err1==-1) return -1;
        int fd2=open(filename2, O_RDONLY);
        if(fd2==-1) return -1;
        if(fd2==0) return 0;
        if(fstat(fd2, &st2)<0) return -1;
        int size2=st2.st_size/sizeof(complex);
        if(size2==0) return 0;
        j=1;
        err2=1;
        while(j<=size2 || err2!=0){
            complex* valTab2=malloc(sizeof(complex));
            err2=read(fd2,(void*)valTab2,sizeof(complex));
            if(err2==-1) return -1;
            if(valTab1->r==valTab2->r){
                if(valTab1->i==valTab->i){
                    count++;
                }
            }
            free(valTab2);
            j++;
        }
        if(close(fd2)==-1)return -1;
        free(valTab1);
        i++;
    }
    if(close(fd1)==-1) return -1;

    return count;
}
