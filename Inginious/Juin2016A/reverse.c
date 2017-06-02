#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/*
 *  * @pre filename!=NULL
 *   * @post Modifie le contenu du fichier filename en echangeant :
 *    *  - le premier byte du fichier avec le dernier
 *     *  - le deuxieme byte avec l'avant dernier
 *      *  - ...
 *       * Apres modification, le fichier est ferme.
 *        * retourne 0 en cas de succes, -1 en cas d'erreur.
 *         * L'implementation ne peut pas utiliser, fopen, read, write, fread, fwrite, fgetc, fgets, ... open et mmap sont obligatoires.
 *          */

int reverse(char *filename) {
    char* src;
    int fd=open(filename,O_RDWR,S_IRUS | S_IWUSR);
    if(fd==-1) return -1;
    struct stat st;
    if(fstat(fd,&st)<0) return -1;
    int size=st.st_size;
    if((src=mmap(NULL, size,PROT_WRITE | PROT_READ, MAP_SHARED,fd,0))==NULL) return -1;
    int i;
    int j=0;
    char* inter=malloc(size);
    for(i=size-1;i>=0;i--){
        inter[i]=src[i];
        j++;
    }
    memcpy(inter,src,size+1);
    if(msync(src,size+1,MS_SYNC)<0) return -1;
    if(munmap(src,size)<0) return -1;
    if(close(fd)==-1) return -1;
    return 0;
}

