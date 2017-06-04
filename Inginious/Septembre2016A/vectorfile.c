#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/*
 *  * Implementation de vecteurs en utilisation des fichiers
 *   * La donnée à l'indice zéro correspond aux sizeof(double)
 *    * premiers bytes du fichier, la deuxième aux suivantes, etc.
 *     * La taille d'un tel fichier est toujours un multiple
 *      * entier de sizeof(double)
 *       */

/*
 *  * @pre *filename!=NULL, size>0
 *   * @post construit un fichier contenant size double à la valeur val
 *    *       retourne le nombre de données écrites, -1 en cas d'erreur
 *     */
int create(char *filename, int size, double val) {

    int err;
    int fd=open(filename,O_RDWR|O_CREAT,S_IRUSR|S_IWUSR);
    if(fd==-1) {
        return -1;
    }
    for(int i=0; i<size; i++) {
        err=write(fd,(void *) &val, sizeof(double));
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
 *  * @pre filename!=NULL, 0 <= i*sizeof(double) < taille fichier,
 *   *       0 <= j*sizeof(double) < taille fichier
 *    * @post échange les données aux indices i et j dans
 *     *       le vectorfile (0 est le premier indice)
 *      *       retourne 0 en cas de succès, -1 si erreur
 *       */

int swap(char *filename, int i, int j) {
    if(i==j)return 0;
    int i2=0;
    int j2=0;
    int err=1;
    double* buffer=malloc(sizeof(double));
    if(buffer==NULL)return -1;
    int fd=open(filename,O_RDONLY);
    double iVal=0;
    double jVal=0;
    if(fd==-1) return -1;
    while(err !=0){
        err=read(fd,(void*)buffer,sizeof(double));
        if(err==-1)return -1;
        if(i==i2)iVal=*buffer;
        if(j==j2)jVal=*buffer;
        i2++;
        j2++;
    }
    if(close(fd)==-1) return -1;

    int max=i2;
    i2=0;
    j2=0;

    int fd2=open(filename,O_RDWR);
    if(fd2==-1) return -1;
    int err2=1;
    int count=0;
    double* buffer2=malloc(sizeof(double));
    if(buffer2==NULL) return -1;
    while(count<max){
        if(i2==i){
            err2=write(fd2,(void*)&jVal, sizeof(double));
            if(err2==-1) return -1;
        }
        else if(j2==j){
            err2=write(fd2, (void*) &iVal, sizeof(double));
            if(err2==-1)return -1;
        }
        else{
            err2=read(fd2, (void*) buffer2,sizeof(double));
            if(err2==-1) return -1;
        }
        i2++;
        j2++;
        count++;
    }
    if(close(fd2)==-1) return -1;
    free(buffer);
    free(buffer2);
    return 0;
}
