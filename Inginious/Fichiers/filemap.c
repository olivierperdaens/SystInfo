#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int count(char *filename, char c) {
    int count_char=0;
    int cha;
    FILE* file=fopen(filename,"r");
    struct stat st;
    int result=stat(filename,&st);
    if(result<0){return 0;}
    if(file){
        while((cha=getc(file))!=EOF){
            if(c==cha) count_char++;
        }
        fclose(file);
        return count_char;
    }
    return 0;
}

int main(){
    char a='a';
    int count_c=count("test.txt",a);
    printf("Il y a %d fois le char %c dans test.txt \n",count_c,a);
    return EXIT_SUCCESS;
}
