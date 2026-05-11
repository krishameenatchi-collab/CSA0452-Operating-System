#include <stdio.h>

int main() {
    int n, block[50];

    printf("Enter number of blocks: ");
    scanf("%d", &n);

    printf("Enter blocks:\n");

    for(int i=0;i<n;i++)
        scanf("%d", &block[i]);

    printf("Linked Allocation:\n");

    for(int i=0;i<n-1;i++)
        printf("%d -> %d\n", block[i], block[i+1]);

    printf("%d -> NULL\n", block[n-1]);

    return 0;
}
