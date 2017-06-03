#include <stdio.h>
#include <stdlib.h>

int fct(int a){
    if(a>0){
        int b=0;
        int c=a;
        a=0;
        int d=0;
        while(d<c){
            b+=2;
            a+=b;
            d++;
        }
        return a;
    }
    else{
        a=-1;
        return a;
    }

}
