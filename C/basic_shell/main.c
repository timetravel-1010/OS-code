#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <assert.h>
#include <stdbool.h>
#include "utils.h"

#define SIZE 255

int main(void)
{
    char* argv[SIZE];
    int status;
    pid_t pid;

    bzero(argv, sizeof(char)*SIZE); /* Para llenar de 0 el vector argv. */
    printf(":| &> ");

    do
    {
        read_command(argv);

        if (!strcmp(argv[0], "exit")) return 0;

        pid = fork();
        assert(pid >= 0);

        if (pid == 0)
        { /* El proceso hijo trata de ejecutar el comando */
            execvp(argv[0], argv);

            perror("Return from execvp() not expected.");
            return EXIT_FAILURE;
        }

        /* El proceso padre espera y recibe lo retornado por el hijo */
        wait(&status);
        if (WIFEXITED(status)) /* Se verifica que el estado es de salida. */
        {
            if (!WEXITSTATUS(status))
                printf(":) &> ");
            else
                printf(":( &> ");
        }
        else
            return 1;

    } while (true);

    return 0;
}
