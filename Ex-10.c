#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msg {
    long type;
    char text[50];
} m;

int main() {
    int msgid = msgget((key_t)1234, 0666 | IPC_CREAT);

    printf("Enter message: ");
    scanf("%s", m.text);
    m.type = 1;

    msgsnd(msgid, &m, sizeof(m), 0);
    msgrcv(msgid, &m, sizeof(m), 1, 0);

    printf("Received message: %s\n", m.text);
    return 0;
}
