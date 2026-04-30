#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    int fd;
    char str[50];

    printf("Enter text: ");
    scanf("%s",str);

    fd=open("f.txt",O_CREAT|O_RDWR,0777);
    write(fd,str,sizeof(str));

    lseek(fd,0,0);
    read(fd,str,sizeof(str));

    printf("File content: %s\n",str);
    close(fd);
}
