#include <stdio.h>
#include <pthread.h>

void *fun() {
    printf("Thread running\n");
    return NULL;
}

int main() {
    pthread_t t1;
    pthread_create(&t1, NULL, fun, NULL);
    pthread_join(t1, NULL);
    printf("Main thread\n");
    return 0;
}
