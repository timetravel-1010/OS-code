#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
    pid_t pid;
    int val = 0;
    printf("Proceso principal: %d \n", getpid());

    for (int i = 0; i<3; i++)
    {
        pid = fork();
        if (pid > 0) /* proceso principal */
             wait(NULL);
        else if (pid == 0) /* subproceso */
            printf("Subproceso: %d \n", getpid());
        else /* error al realizar el fork() */
            exit(1);
    }
    return 0;
}

