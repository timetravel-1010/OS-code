#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char** argv) 
{
    	int pid;
    	printf("inicio\n");
    	pid = fork();

    	if (pid > 0) {
            	printf("Soy padre %d y el id de mi padre es %d\n",getpid(),getppid());
            	wait(NULL);
    	} else if (pid < 0) {
            	printf("Error en la invocacion del 'fork()'\n");
            	return 1;
    	} else {
            	int ppid = getppid();
            	int _pid;
            	sleep(1);
            	printf("Soy el hijo con pid %d y el id de mi padre es %d\n", getpid(), ppid);
            	_pid = fork();
            	if (_pid < 0) {
                    	printf("error en la ejecucion del fork()\n");
                    	return 1;
            	} else if (_pid > 0) {
                    	printf("soy el hijo-padre\n");
			wait(NULL);
            	} else {
                    	printf("soy el hijo-hijo %d y el id de mi abuelo es %d\n", getpid(), ppid);
            	}

    	}
    	printf("fin\n");
    	return 0;
}
