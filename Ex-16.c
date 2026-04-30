#include <stdio.h>

struct emp {
    int id;
    char name[20];
} e;

int main() {
    FILE *fp;
    int n, i;

    fp = fopen("emp.dat","w");

    printf("Enter number of employees: ");
    scanf("%d",&n);

    for(i=0;i<n;i++) {
        printf("Enter id and name: ");
        scanf("%d %s",&e.id,e.name);
        fwrite(&e,sizeof(e),1,fp);
    }

    fclose(fp);

    fp = fopen("emp.dat","r");

    printf("Records:\n");
    while(fread(&e,sizeof(e),1,fp))
        printf("%d %s\n",e.id,e.name);

    fclose(fp);
    return 0;
}
