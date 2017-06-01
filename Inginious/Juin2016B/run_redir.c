#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>


/*
 *  * @pre prog!=NULL, argv!=NULL, file!=NULL
 *   * execute le programme prog avec les arguments argv
 *    * en redirigeant la sortie standard et l'erreur standard
 *     * vers le fichier file. Retourne la valeur de retour
 *      * du programme et -1 en cas d'erreur d'exécution du programme
 *       * ou d'accès au fichier
 *        */
int run_redir(char *prog, char* argv[], char *file) {
        int status,err;
        extern char** environ;
        
        //Creation du fils
        pid_t pid=fork();
        if(pid==-1) return -1;

        if(pid==0){ //Fils
            int fd=open(file, O_WRONLY | O_CREAT | O_TRUNC, 00644);
            if(fd==-1){
                close(fd);
                exit(-1);
            }
            err=dup2(fd,1);
            if(err==-1){
                close(fd);
                exit(-1);
            }
            err=dup2(fd,2);
            if(err==-1){
                close(fd);
                exit(-1);
            }
            
            err=execve(prog, argv, environ);
            if(err==-1){
                close(fd);
                exit(-1);
            }

        }//Fils
        else{//Pere
            int fils=waitpid(pid,&status,0);
            if(fils==-1) return -1;
            if(WIFEXITED(status)){
                if(WEXITSTATUS(status)==255) return -1;
                else return WEXITSTATUS(status);

            }
            else return -1;
        }
        return EXIT_SUCCESS;
}
