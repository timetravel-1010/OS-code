#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdbool.h>

int main(int argc, char** argv) {
    pid_t pid;
    int a = 5;
    printf("Soy el padre con pid %d\n", getpid());
    pid = fork(); /* el fork() le retorna al proceso padre el pid del nuevo
                   proceso hijo, y al hijo se le retorna 0.*/

    if (pid < 0) {
        printf("Ha fallado el fork()");
        exit(1);
    }
    if (pid > 0) { /* es el padre */
        a = a + 10;
        printf("Soy el padre %d y a es %d\n", getpid(), a);
        /*while(1);*/
        /*exit(1); termina el proceso del padre.*/
    }
    else {
        a = a+5;
        printf("Soy el hijo %d y a es %d\n", getpid(), a);
    }

    return 0;
}
