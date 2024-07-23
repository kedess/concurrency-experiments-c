#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

__attribute__((unused)) static __inline__ void waitall(void) {
    for(;;){
        int status;
        pid_t pid = wait(&status);
        if (pid == -1) {
            if (errno == ECHILD) {
                // Дочерних потоков больше нет
                break;
            }
            perror("Wait error: ");
            exit(EXIT_FAILURE);
        }
    }
}

__attribute__((unused)) static void fork_example(void) {
    pid_t pid = fork();
    if (pid == 0) {
        printf("This is child process\n");
    } else {
        if (pid < 0) {
            perror("Fork error: ");
            return;
        }
        printf("This is main process, created child process with pid = %d\n", pid);
        waitall();
    }
}
