#include <stdio.h>

int main() {
    int n, bt[10], wt[10], tat[10], completed[10]={0};
    int time=0, count=0, i, min;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    printf("Enter burst time:\n");
    for(i=0;i<n;i++)
        scanf("%d",&bt[i]);

    while(count < n) {
        min = -1;

        for(i=0;i<n;i++) {
            if(!completed[i] && (min==-1 || bt[i] < bt[min]))
                min = i;
        }

        wt[min] = time;
        time += bt[min];
        tat[min] = wt[min] + bt[min];
        completed[min] = 1;
        count++;
    }

    printf("\nBT\tWT\tTAT\n");
    for(i=0;i<n;i++)
        printf("%d\t%d\t%d\n", bt[i], wt[i], tat[i]);

    return 0;
}
