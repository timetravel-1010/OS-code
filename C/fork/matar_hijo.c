#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <assert.h>

int main(int argc, char** argv) { 
    pid_t pid;
    printf("pid del proceso padre %d\n", getpid());
    pid = fork();

    assert(pid >= 0); /* condicion necesaria para continuar la ejecucion del codigo */

    if (pid == 0) { /* se trata del hijo */
        printf("pid del proceso recien creado %d\n", getpid());
        while(1);
    }
    else {
    //el padre no hace nada y continua la ejecucion.
    }

    return 0;
}

