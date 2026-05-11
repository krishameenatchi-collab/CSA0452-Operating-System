#include <stdio.h>
#include <sys/stat.h>

int main() {
    struct stat fileStat;

    if(stat("sample.txt", &fileStat) < 0) {
        printf("Unable to get file information.\n");
        return 1;
    }

    printf("File Access Permissions:\n\n");

    printf("Owner Permissions:\n");
    printf("Read   : %s\n", (fileStat.st_mode & S_IRUSR) ? "Yes" : "No");
    printf("Write  : %s\n", (fileStat.st_mode & S_IWUSR) ? "Yes" : "No");
    printf("Execute: %s\n\n", (fileStat.st_mode & S_IXUSR) ? "Yes" : "No");

    printf("Group Permissions:\n");
    printf("Read   : %s\n", (fileStat.st_mode & S_IRGRP) ? "Yes" : "No");
    printf("Write  : %s\n", (fileStat.st_mode & S_IWGRP) ? "Yes" : "No");
    printf("Execute: %s\n\n", (fileStat.st_mode & S_IXGRP) ? "Yes" : "No");

    printf("Others Permissions:\n");
    printf("Read   : %s\n", (fileStat.st_mode & S_IROTH) ? "Yes" : "No");
    printf("Write  : %s\n", (fileStat.st_mode & S_IWOTH) ? "Yes" : "No");
    printf("Execute: %s\n", (fileStat.st_mode & S_IXOTH) ? "Yes" : "No");

    return 0;
}
