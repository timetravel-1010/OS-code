#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    argv[argc] = NULL;
    char* args[argc];

    for (int i = 0; i<(argc-1); i++)
        args[i] = argv[i+1];

    args[argc-1] = NULL;

    execvp(args[0], args);
    perror("Return from execvp() not expected.");

    return EXIT_FAILURE;
}
