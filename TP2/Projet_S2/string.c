#include <stdio.h>
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
int strcasecmp(const char *s1, const char *s2){
    char str1[strlen(s1)];
    char str2[strlen(s2)];
    size_t i,j,k;
    for(i=0; i<strlen(s1)+1; i++){
	if(s1[i]>='A' && s1[i]<='Z') str1[i]='a'+s1[i]-'A';
	else str1[i]=s1[i];
    }
    for(j=0; j<strlen(s2)+1; j++){
	if(s2[j]>='A' && s2[j]<='Z') str2[j]='a'+s2[j]-'A';
	else str2[j]=s2[j];
    }
    printf("%s \n%s \n",str1, str2);
    for(k=0; k<strlen(s1)+1; k++){
	if(str1[k]<str2[k]) return -1;
	if(str1[k]>str2[k]) return 1;
    }
    return 0;
}

int main(int argc, const char *argv[]){	
    char *str1="CANON";
    char *str2="CANON";
    //char *str3=(char*) malloc(100*sizeof(char));
    //size_t i;
    //for(i=0;i<strlen(str1);i++){
//	str3[i]=str1[i];
  //  }
    //char *str=strcat(str3, str2);
    int i=strcasecmp(str1,str2);
    printf("%d \n",i);
    //free(str3);
    return EXIT_SUCCESS;
}
