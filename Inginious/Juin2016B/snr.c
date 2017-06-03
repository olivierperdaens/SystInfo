#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

/*
 *  * @pre filename!=NULL, src!=NULL, dst!=NULL, len >0
 *   *      src et dst pointent vers des zones de tailles len
 *    *      le fichier filename a comme taille un multiple entier de len
 *     * @post modifie le contenu du fichier filename en remplaçant
 *      *       toutes les occurences des blocs de données src par dst.
 *       *       Le fichier est supposé découpé en blocs de taille len
 *        *       aux positions 0, len, 2*len, ...
 *         *       retourne le nombre de blocs remplacés et -1 en cas d'erreur
 *          *       Il est interdit d'utiliser mmap et vous devez utiliser malloc
 *           *       pour allouer la mémoire dont vous avez besoin. Pour accéder au fichier, vous pouvez uniquement utiliser open, read, lseek, write et close.
 *            */
int sr(char *filename, char *src, char *dst, ssize_t len) {
    int fd=open(filename, O_RDWR);
    if(fd==-1)return -1;
    int i=0;
    int err;
    int count=0;
    char* buf=malloc(len);
    if(buf==NULL) return -1;
    while((err=read(fd,&buf,len))>0){
        if(err==-1) return -1;
        if(strncmp(buf,src,len)==0){
            err=lseek(fd,(i)*len,SEEK_SET);
            if(err==-1) return -1;
            err=write(fd,(void*)dst,len);
            if(err==-1) return -1;
            count++;
        }
        i++;
    }
    if(close(fd)==-1) return -1;
    free(buf);
    return count;
}

