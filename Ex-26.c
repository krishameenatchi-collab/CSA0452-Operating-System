#include <stdio.h>

int main() {
    FILE *fp;
    char data[100];

    fp = fopen("file.txt", "w");
    printf("Enter text: ");
    gets(data);

    fputs(data, fp);
    fclose(fp);

    fp = fopen("file.txt", "r");

    fgets(data, 100, fp);

    printf("File Content: %s\n", data);

    fclose(fp);

    remove("file.txt");

    printf("File deleted successfully\n");

    return 0;
}
