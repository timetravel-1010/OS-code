#include <stdio.h>
#include <string.h>

void read_command(char** argv)
{   
    char cadena[255];
    char* argc[255];
    int i = 0;

    fgets(cadena, sizeof(cadena), stdin);
    cadena[strlen(cadena)] = '\x0';

    argc[i] = strtok(cadena, " \n");

    while (argc[i] != NULL)
    {
        i++;
        argc[i] = strtok(NULL, " \n");
    }

    for (int j = 0; j < i; j++)
        argv[j] = argc[j];

    argv[i] = NULL;
}