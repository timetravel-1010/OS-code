#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char** argv) {
    pid_t pid; /* tipo de dato pid_t */

    printf("%d\n", getpid());
    while(1);

    return 0;
}
