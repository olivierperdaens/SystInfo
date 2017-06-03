# asm2.c 
## Traduction de code assembleur
Traduisez en langage C la fonction assembleur suivante

```assembly
fct:
    movl 4(%esp), %eax
    cmpl $0,%eax
    jg n
    movl $-1,%eax
    ret
n:  movl $0,%ebx
    movl %eax, %ecx
    movl $0, %eax
    movl $0, %edx
l:  addl $2, %ebx
    addl %ebx, %eax
    addl $1, %edx
    cmpl %ecx, %edx
    jl l
    ret
```

# run_redir.c
## Redirection des flux de sortie et d'erreur standards
La fonction reverse, dont les spécifications sont reprises ci-dessous, permet de manipuler les données dans un fichier.

```c
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/*
 * @pre filename!=NULL
 * @post Modifie le contenu du fichier filename en echangeant :
 *  - le premier byte du fichier avec le dernier
 *  - le deuxieme byte avec l'avant dernier
 *  - ...
 * Apres modification, le fichier est ferme.
 * retourne 0 en cas de succes, -1 en cas d'erreur.
 * L'implementation ne peut pas utiliser, fopen, read, write, fread, fwrite, fgetc, fgets, ... open et mmap sont obligatoires.
 */

int reverse(char *filename) {
```
