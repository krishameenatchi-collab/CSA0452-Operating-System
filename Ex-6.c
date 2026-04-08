#include <stdio.h>
int main() {
    int n, bt[10], pr[10], rem[10], t=0, completed=0, i, highest;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    printf("Enter Burst Time and Priority:\n");
    for(i=0;i<n;i++) {
        scanf("%d%d",&bt[i],&pr[i]);
        rem[i]=bt[i];
    }
    while(completed < n) {
        highest = -1;

        for(i=0;i<n;i++) {
            if(rem[i] > 0 && (highest==-1 || pr[i] < pr[highest])) {
                highest = i;
            }
        }
        rem[highest]--;
        t++
        if(rem[highest]==0)
            completed++;
    }
    printf("Execution completed\n");
    return 0;
}
