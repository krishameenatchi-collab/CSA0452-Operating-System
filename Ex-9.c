#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main() {
    int shmid;
    char *str;

    shmid = shmget((key_t)1234, 1024, 0666 | IPC_CREAT);
    str = (char*) shmat(shmid, NULL, 0);

    printf("Enter message: ");
    scanf("%s", str);

    printf("Written to memory: %s\n", str);

    shmdt(str);
    return 0;
}
