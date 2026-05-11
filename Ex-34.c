#include <stdio.h>

int main() {
    int start, length;

    printf("Enter starting block: ");
    scanf("%d", &start);

    printf("Enter file length: ");
    scanf("%d", &length);

    printf("Allocated Blocks:\n");

    for(int i=0;i<length;i++) {
        printf("%d ", start + i);
    }

    return 0;
}
