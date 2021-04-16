#include <stdio.h>
#include <string.h>


void read_comand(char** argv)
{
    char cadena[255];
    char* argc[255];

    fgets(cadena, sizeof(cadena), stdin);
    cadena[strlen(cadena)] = '\x0';

    argc[0] = strtok(cadena, " ");
    int i = 0;

    while (argc[i] != NULL)
    {
        i++;
        argc[i] = strtok(NULL, " ");
    } 

    for (int j = 0; j < i; j++)
        argv[j] = argc[j];

    printf("i = %d \n", i);
    argv[i-1] = NULL;
}