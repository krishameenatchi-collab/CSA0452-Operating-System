#include <stdio.h>
#include <stdlib.h>

int main() {
    int req[50], n, head, seek = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    for(int i=0;i<n;i++)
        scanf("%d", &req[i]);

    printf("Enter head position: ");
    scanf("%d", &head);

    for(int i=0;i<n;i++) {
        seek += abs(req[i] - head);
        head = req[i];
    }

    printf("C-SCAN Seek Time = %d\n", seek);

    return 0;
}
