#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int run_command(const char *path, char* const argv[]){
    extern char** environ;
    int status;
    pid_t pid =fork();
    if(pid==0){
        int err=execve(path, argv, environ);
        return err;
    }
    else{
        waitpid(pid,&status,0);
        return WEXITSTATUS(status);
    }
}

int run_pipe(const char *path_a, char* const argv_a[], const char* path_b, char* const argv_b[]){
    extern char** environ;
    int status;
    int fd[2];
    pipe(fd);
    pid_t pid=fork();
    if(pid==0){
        close(fd[0]);
        dup2(fd[1],STDOUT_FILENO);
        int err=execve(path_a, argv_a, environ);
        close(fd[1]);
        return EXIT_SUCCESS;
    }
    else{
        close(fd[1]);
        waitpid(pid,&status,0);
        pid=fork();
        if(pid==0){
            dup(fd[0],STDINT_FILENO);
            int err=execve(path_b, argv_b, environ);
            close(fd[0]);
            return err;
        }
        else{
            close(fd[0]);
            waitpid(pid,&status,0);
            return WEXITSTATUS(status);
        }
    }
}

int run_and(const char* path_a, char* const argv_a[], const char* path_b, char* const argv_b[]){
    extern char** environ;
    int status;
    pid_t pid =fork();
    if(pid==0){
        int err=execve(path_a, argv_a, environ);
        return err;
    }
    else{
        waitpid(pid,&status,0);
        if(WEXITSTATUS(status)==0){
            pid=fork();
            if(pid==0){
                int err=execve(path_b, argv_b, environ);
                return err;
            }
            else{
                waitpid(pid,&status,0);
                return WEXISTATUS(status);
            }
        }
        else{
            return WEXITSTATUS(status)
    }
}

int run_redirected(const char *path, char* const argv[], const char* output_path){
    extern char** environ;
    int status;
    pid_t pid =fork();
    if(pid==0){
        freopen(output_path,"w", stdout);
        int err=execve(path, argv, environ);
        return err;
    }
    else{
        waitpid(pid, &status, 0);
        return WEXITSTATUS(status);
    }
}
