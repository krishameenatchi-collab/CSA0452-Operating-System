#include <stdio.h>

int main() {
    int pages[50], frame[10];
    int n, f, i, j, k, fault = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    for(i=0;i<n;i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i=0;i<f;i++)
        frame[i] = -1;

    for(i=0;i<n;i++) {
        int found = 0;

        for(j=0;j<f;j++) {
            if(frame[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if(!found) {
            int pos = -1, farthest = i + 1;

            for(j=0;j<f;j++) {
                int next = -1;

                for(k=i+1;k<n;k++) {
                    if(frame[j] == pages[k]) {
                        next = k;
                        break;
                    }
                }

                if(next == -1) {
                    pos = j;
                    break;
                }

                if(next > farthest) {
                    farthest = next;
                    pos = j;
                }
            }

            if(pos == -1)
                pos = 0;

            frame[pos] = pages[i];
            fault++;
        }
    }

    printf("Page Faults = %d\n", fault);

    return 0;
}
