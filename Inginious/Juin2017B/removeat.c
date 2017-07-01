int removeat(char *fileName, off_t pos, size_t nbyte) {
    int fd=open(fileName,O_RDWR,00644);
    if(fd==-1)
        return -1;
    struct stat st;
    if(fstat(fd,&st)==-1)
        return -1;
    int size=st.st_size;//taile du fichier fileName
    if(size<pos)//pos plus grand que la taille du fichier
        return -1;

    char* buffer=malloc(nbyte);
    if(buffer==NULL)
        return -1;

    int sizeToMove=(size-pos)-nbyte;//la taille du fichier - la position pos - le nombre de bytes enlevés

    if(lseek(fd,pos+nbyte,SEEK_SET)<0)//on positionne le off_set apres la position+le nombre de byte à enlever
        return -1;

    if(read(fd,(void*)buffer,sizeToMove)<0)//on met dans buffer le contenu des bytes apres la zone enlevée
        return -1;

    if(lseek(fd,pos,SEEK_SET)<0)//on remet le offset à la position pos
        return -1;

    if(write(fd,(void*)buffer,sizeToMove)<0)//on ecrit les "sizeToMove" bytes à la position pos dans fileName
        return -1;

    if(ftruncate(fd,size-nbyte)==-1)//Une fois le fichier modifié, on reduit sa taille à "sa taille - les nbytes"
        return -1;
    if(close(fd)==-1)
        return -1;
    free(buffer);
    return nbyte;
}
