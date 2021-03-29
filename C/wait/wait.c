#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int pid_subproceso = fork();
    if (pid_subproceso < 0) 
    { /* ha fallado el fork */
        exit(1);
    }
    else if (pid_subproceso == 0) 
    { /* proceso hijo */
        printf("Soy el subproceso %d\n", getpid());
    }
    else 
    { /* proceso padre */
        int pid_wait = wait(NULL); /* espera la finalizacion del proceso hijo */
        printf("Soy el proceso %d padre de %d\n", getpid(), pid_subproceso);
    }
    return 0;
}
