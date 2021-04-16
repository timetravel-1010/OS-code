#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"


int main(void)
{   
    char* argv[255];
    int i = 0;

    printf(":| &> ");
    read_comand(argv);
    printf("argv[2] = %s \n", argv[2]);
    while (argv[i] != NULL)
    {
        printf("%s \n", argv[i]);
        i++;
    }
    
    /*do
    {
        
    } while (true);
    */

    return 0;
}