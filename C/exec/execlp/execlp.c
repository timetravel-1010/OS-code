#include <unistd.h> // execlp()
#include <stdio.h>  // perror()
#include <stdlib.h> // EXIT_SUCCESS, EXIT_FAILURE

int main(void) {
  execlp("ls", "cat", "exec_1.c", NULL);
  printf("Después del exec\n");
  perror("Return from execlp() not expected");
  exit(EXIT_FAILURE);
}

