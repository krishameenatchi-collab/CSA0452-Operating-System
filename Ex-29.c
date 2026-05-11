#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t empty, full, mutex;
int item = 0;

void *producer() {
    for(int i=1;i<=5;i++) {
        sem_wait(&empty);
        sem_wait(&mutex);

        item = i;
        printf("Produced: %d\n", item);

        sem_post(&mutex);
        sem_post(&full);

        sleep(1);
    }
}

void *consumer() {
    for(int i=1;i<=5;i++) {
        sem_wait(&full);
        sem_wait(&mutex);

        printf("Consumed: %d\n", item);

        sem_post(&mutex);
        sem_post(&empty);

        sleep(1);
    }
}

int main() {
    pthread_t p, c;

    sem_init(&empty, 0, 1);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);

    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);

    pthread_join(p, NULL);
    pthread_join(c, NULL);

    return 0;
}
