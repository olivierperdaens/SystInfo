# asm2.c 
## Traduction de code assembleur
La fonction suivante a été écrite en assembleur. Traduisez la en une version équivalente en C. Votre fonction doit nécessairement avoir comme nom __mp__.

```assembly
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

```c
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


# snr.c
## Search and replace

Implémentez la fonction __sr__ dont les spécifications sont fournies ci-dessous.
```c
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

/*
 * @pre filename!=NULL, src!=NULL, dst!=NULL, len >0
 *      src et dst pointent vers des zones de tailles len
 *      le fichier filename a comme taille un multiple entier de len
 * @post modifie le contenu du fichier filename en remplaçant
 *       toutes les occurences des blocs de données src par dst.
 *       Le fichier est supposé découpé en blocs de taille len
 *       aux positions 0, len, 2*len, ...
 *       retourne le nombre de blocs remplacés et -1 en cas d'erreur
 *       Il est interdit d'utiliser mmap et vous devez utiliser malloc
 *       pour allouer la mémoire dont vous avez besoin. Pour accéder au fichier, vous pouvez uniquement utiliser open, read, lseek, write et close.
 */
int sr(char *filename, char *src, char *dst, ssize_t len) {
// insérez votre code ici sans terminer par }
```
