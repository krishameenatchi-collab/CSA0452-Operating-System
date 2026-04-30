#include <stdio.h>

int main() {
    int b[10], p[10], i, j, nb, np;

    printf("Enter number of blocks: ");
    scanf("%d", &nb);
    for(i=0;i<nb;i++) scanf("%d",&b[i]);

    printf("Enter number of processes: ");
    scanf("%d", &np);
    for(i=0;i<np;i++) scanf("%d",&p[i]);

    for(i=0;i<np;i++) {
        for(j=0;j<nb;j++) {
            if(b[j] >= p[i]) {
                printf("Process %d allocated to block %d\n", i, j);
                b[j] -= p[i];
                break;
            }
        }
    }
}
