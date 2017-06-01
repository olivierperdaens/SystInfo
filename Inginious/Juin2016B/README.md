# asm2.c 
## Traduction de code assembleur
La fonction suivante a été écrite en assembleur. Traduisez la en une version équivalente en C. Votre fonction doit nécessairement avoir comme nom __mp__.

``` 
mp:
    subl $8, %esp
    movl 16(%esp), %edx
    movl 12(%esp), %ecx
    addl %ecx, %ecx
    cmpl %edx,%ecx
    jle mp1
    movl %edx, %eax
    addl $8, %esp
    ret
mp1: movl %ecx, %eax
    addl $8, %esp
    ret 
```

# run_redir.c
## Redirection des flux de sortie et d'erreur standards
Implémentez la fonction run_redir dont les spécifications sont fournies ci-dessous. Il est interdit d'utiliser la fonction __system__ de la librairie standard.

```
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>


/*
 * @pre prog!=NULL, argv!=NULL, file!=NULL
 * execute le programme prog avec les arguments argv
 * en redirigeant la sortie standard et l'erreur standard
 * vers le fichier file. Retourne la valeur de retour
 * du programme et -1 en cas d'erreur d'exécution du programme
 * ou d'accès au fichier
 */
int run_redir(char *prog, char* argv[], char *file) {
// insérez ici le code sans terminer par }
```
