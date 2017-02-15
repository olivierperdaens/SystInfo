#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

size_t strlen(const char *s){
    size_t i=0;
    while(*(s+i) != '\0')
        i++;
    return i;
}

char *strcat(char *dest, const char *src){
   size_t i,j;
   for(i=0; dest[i]!= '\0'; i++)
    ;
   
   for(j=0; src[j] != '\0'; j++)
    dest[i+j]=src[j];
   dest[i+j]='\0';
   return dest;
}

int main(int argc, const char *argv[]){
    char *str1="salut";
    char *str2=", ca va?";
    char *str3=(char*) malloc(100*sizeof(str1));
    str3=str1;
    char *str=strcat(str3, str2);
    printf("%s \n",str);
    free(str3);
    return EXIT_SUCCESS;
}
