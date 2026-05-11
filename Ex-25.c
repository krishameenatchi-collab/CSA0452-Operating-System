#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

int main() {
    int fd;
    char buf[100];

    fd = open("sample.txt", O_RDONLY);

    if(fd < 0) {
        printf("File not found\n");
        return 1;
    }

    printf("File opened successfully\n");

    lseek(fd, 5, SEEK_SET);
    read(fd, buf, 20);
    buf[20] = '\0';

    printf("Data after seek: %s\n", buf);

    struct stat st;
    stat("sample.txt", &st);

    printf("File Size: %ld bytes\n", st.st_size);

    DIR *d;
    struct dirent *dir;

    d = opendir(".");

    printf("\nDirectory Contents:\n");

    while((dir = readdir(d)) != NULL) {
        printf("%s\n", dir->d_name);
    }

    closedir(d);
    close(fd);

    return 0;
}
