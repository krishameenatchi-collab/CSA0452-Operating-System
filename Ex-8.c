#include <stdio.h>
int main() {
    int n, bt[10], rem[10], tq, time=0, i, done;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    printf("Enter Burst Times:\n");
    for(i=0;i<n;i++) {
        scanf("%d",&bt[i]);
        rem[i] = bt[i];
    }
    printf("Enter Time Quantum: ");
    scanf("%d",&tq);
    do {
        done = 1;
        for(i=0;i<n;i++) {
            if(rem[i] > 0) {
                done = 0;
                if(rem[i] > tq) {
                    time += tq;
                    rem[i] -= tq;
                } else {
                    time += rem[i];
                    rem[i] = 0;
                }
            }
        }
    } while(!done);
    printf("Total Execution Time: %d\n", time);
    return 0;
}
