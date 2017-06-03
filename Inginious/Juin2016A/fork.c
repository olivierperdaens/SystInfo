#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

/*
 *  * @pre : prog!=null, arg!=null
 *   * @post: exécute le programme prog en lui passant
 *    *       arg comme arguments et sans environnement.
 *     *       Retourne
 *      *       -1 si le programme n'est pas exécutable
 *       *       ou a retourné une valeur de retour >0
 *        *       0 si il s'exécute correctement et retourne une valeur de retour = 0
 *         *       -2 si il s'exécute et est interrompu par la réception d'un signal
 *          */
int run(char *prog, char *arg[]) {
    int status;
    extern char** environ;
    pid_t pid=fork();
    if(pid<0) exit(EXIT_FAILURE);

    if(pid==0){//fils
        fflush(stdout);
        int err=execve(prog, arg, environ);
        if(err!=0)exit(-1);

    }
    else{//pere
        int fils=waitpid(pid, &status,0);
        if(fils==-1)exit(-1);
        if(WIFEXITED(status)){
            if(WEXITSTATUS(status)==0) return 0;
            else if(WEXITSTATUS(status)>0) return -1;
        }
        else{
            if(WIFSIGNALED(status))return -2;
            else exit(-1);
        }
        fflush(stdout);
    }
    return EXIT_SUCCESS;
}
