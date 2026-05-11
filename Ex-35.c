#include <stdio.h>

int main() {
    int index[50], n;

    printf("Enter number of blocks: ");
    scanf("%d", &n);

    printf("Enter index blocks:\n");

    for(int i=0;i<n;i++)
        scanf("%d", &index[i]);

    printf("File Allocation:\n");

    for(int i=0;i<n;i++)
        printf("%d -> %d\n", i, index[i]);

    return 0;
}
