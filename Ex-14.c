#include <stdio.h>
#include <string.h>

int main() {
    char files[10][20];
    int n, i;

    printf("Enter number of files: ");
    scanf("%d", &n);

    for(i=0;i<n;i++) {
        printf("Enter file %d: ", i+1);
        scanf("%s", files[i]);
    }

    printf("Files are:\n");
    for(i=0;i<n;i++)
        printf("%s\n", files[i]);

    return 0;
}
