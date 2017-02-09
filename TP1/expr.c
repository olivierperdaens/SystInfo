
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int bar(int a, int b){
    if(a==0) return b;
    return a;
}

int and(int a, int b){
    if(a==0){
        if (b==0) return 0;
        return a;
    }
    return a;
}
 
int eq(int a, int b){
    if(a==b) return 0;
    return 1;
}

int ge(int a, int b){
    if(a>=b) return 0;
    return 1;
}

int gt(int a, int b){
    if(a>b) return 0;
    return 1;
}

int le(int a, int b){
    if(a<=b) return 0;
    return 1;
}

int lt(int a, int b){
    if(a<b) return 0;
    return 1;
}

int ne(int a, int b){
    if(a==b) return 1;
    return 0;
}

int plus(int a, int b){
    int c=a+b;
    return c;
}

int minus(int a, int b){
    int c=a-b;
    return c;
}

int prod(int a, int b){
    int c=a*b;
    return c;
}

int quot(int a, int b){
    div_t c=div(a, b);
    return c.quot;
}

int mod(int a, int b){
    int c=a % b;
    return c;
}

int main(int argc, const char *argv[]){
    if(strcmp(argv[2], "-eq")==0){
        return eq(atoi(argv[1]), atoi(argv[3]));
    }
    if(strcmp(argv[2], "-ge")==0){
        return ge(atoi(argv[1]), atoi(argv[3]));
    }
    if(strcmp(argv[2], "-gt")==0){
        return gt(atoi(argv[1]), atoi(argv[3]));
    }
    if(strcmp(argv[2], "-le")==0){
        return le(atoi(argv[1]), atoi(argv[3]));
    }
    if(strcmp(argv[2], "-lt")==0){
        return lt(atoi(argv[1]), atoi(argv[3]));
    }
    if(strcmp(argv[2], "-ne")==0){
        return ne(atoi(argv[1]), atoi(argv[3]));
    }
    if(strcmp(argv[2], "|")==0){
        return bar(atoi(argv[1]), atoi(argv[3]));
    }
    if(strcmp(argv[2], "&")==0){
        return and(atoi(argv[1]), atoi(argv[3]));
    }
    if(strcmp(argv[2], "+")==0){
        return plus(atoi(argv[1]), atoi(argv[3]));
    } 
    if(strcmp(argv[2], "-")==0){
        return minus(atoi(argv[1]), atoi(argv[3]));
    }
    if(strcmp(argv[2], "*")==0){
        return prod(atoi(argv[1]), atoi(argv[3]));
    }
    if(strcmp(argv[2], "/")==0){
        return quot(atoi(argv[1]), atoi(argv[3]));
    }
    if(strcmp(argv[2], "%")==0){
        return mod(atoi(argv[1]), atoi(argv[3]));
    }





    return EXIT_FAILURE;
}

