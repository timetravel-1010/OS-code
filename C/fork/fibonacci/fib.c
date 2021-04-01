#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int fibonacci(int num)
{
    if (num == 0)
        return 0;
    else if(num == 1)
        return 1;
    else
        return fibonacci(num-1)+fibonacci(num-2);
}


int main(int argc, char* argv[])
{
    printf("fibonacci(%s) = %d \n", argv[1], fibonacci(strtol(argv[1], NULL, 10)));

    return 0;
}
