#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

static void * callback(__attribute__((unused))void * args) {
    int * value = (int*)malloc(sizeof(int));
    *value = 7;
    printf("Execution inside a thread\n");
    return value;
}

__attribute__((unused)) static __inline__ void create_thread(void) {
    int err;
    pthread_t tid;
    void * vp = NULL;
    if ((err = pthread_create(&tid, NULL, callback, NULL)) != 0) {
        fprintf(stderr, "Can't create thread %s", strerror(err));
        goto cleanup;
    }
    if ((err = pthread_join(tid, &vp)) != 0) {
        fprintf(stderr, "Can't create thread %s", strerror(err));
        goto cleanup;
    }
    printf("Received value = %d\n", *(int*)vp);
    cleanup:
        free(vp);
}
