#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "fibfun.h"

int main(void)
{
    pid_t pid;
    pid = fork();

    if (pid == 0)
        printf("fibonacci(50) = %ld \n", fibonacci(50));
    else if (pid > 0)
        wait(NULL); /* El padre espera que termine el hijo. */
    else
    {
        printf("Ha fallado el fork()");
        exit(1);
    }

    return 0;
}
