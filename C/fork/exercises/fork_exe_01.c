#include <stdio.h> 
#include <sys/types.h>
#include <unistd.h>
#include <assert.h>

int main(int argc, char** argv) {
    pid_t pid;
    int contador = 1;
    
    pid = fork(); /* El fork() le retorna al proceso padre el pid del nuevo
                   proceso hijo, y al hijo se le retorna 0.*/

    assert(pid >= 0);

    if (pid > 0) /* Es el padre */
        contador += 2;
    else /* Es el proceso hijo */
        contador += 5;

    printf("contador = %d \n", contador);
    return 0;
}
