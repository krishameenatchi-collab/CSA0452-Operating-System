#include <stdio.h>

int main() {
    int users, files, i, j;

    printf("Enter number of users: ");
    scanf("%d", &users);

    for(i=0;i<users;i++) {
        printf("Enter number of files for user %d: ", i+1);
        scanf("%d", &files);

        for(j=0;j<files;j++) {
            printf("File %d of user %d\n", j+1, i+1);
        }
    }
    return 0;
}
