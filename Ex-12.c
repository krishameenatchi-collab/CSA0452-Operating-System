#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t chopstick[5];

void *philosopher(void *num) {
    int id = *(int*)num;

    sem_wait(&chopstick[id]);
    sem_wait(&chopstick[(id+1)%5]);

    printf("Philosopher %d is eating\n", id);

    sem_post(&chopstick[id]);
    sem_post(&chopstick[(id+1)%5]);

    return NULL;
}

int main() {
    pthread_t p[5];
    int i, a[5];

    for(i=0;i<5;i++)
        sem_init(&chopstick[i],0,1);

    for(i=0;i<5;i++) {
        a[i]=i;
        pthread_create(&p[i],NULL,philosopher,&a[i]);
    }

    for(i=0;i<5;i++)
        pthread_join(p[i],NULL);

    return 0;
}
