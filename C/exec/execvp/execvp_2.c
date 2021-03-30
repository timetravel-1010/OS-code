#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    argv[argc] = NULL;

    execvp(argv[1], argv+1);
    perror("Return from execvp() not expected.");

    return EXIT_FAILURE;
}
