#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

char * my_strsep(char ** stringp, const char * delim){
    if(stringp == 0) return '\0';
    else if(*stringp == '\0') return '\0';
    else if(*delim == '\0'){
        char * ret=*stringp;
        *stringp='\0';
        return ret;
    }
    else{
        char* tmp = *stringp;
        char* ret = *stringp;
        while(*tmp != '\0'){
            if(*tmp==*delim){
                *tmp='\0';
                *stringp=tmp+1;
                return ret;
            }
            tmp++;
        }
        *stringp='\0';
        return ret;
    }

}

int main(){
    const char string[]="Hello, it is me -- I was wondering";
    const char delimiters[] =" .,;:!-";
    char *running;
    char *token;

    running=strdupa(string);

    token=my_strsep(&running, delimiters);
    printf("%s \n", token);
    return EXIT_SUCCESS;
}
