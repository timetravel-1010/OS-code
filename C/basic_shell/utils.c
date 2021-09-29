#include <stdio.h>
#include <string.h>

void read_command(char** argv)
{   
    char cadena[255];
    char* argc[255];
    int i = 0;

    fgets(cadena, sizeof(cadena), stdin);
    cadena[strlen(cadena)] = '\x0';

    argv[i] = strtok(cadena, " \n");

    while (argv[i] != NULL)
    {  
        i++;
        argv[i] = strtok(NULL, " \n");
    }
}
