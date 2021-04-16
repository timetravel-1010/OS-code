#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

int main(void)
{
    char* argv[256];

    printf(":| &> ");
    read_command(argv);
    
    execvp(argv[0], argv);
    
    return 0;
}