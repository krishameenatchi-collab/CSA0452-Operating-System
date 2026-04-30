#include <stdio.h>
int main(){
    int b[10],p[10],nb,np,i,j;

    printf("Enter blocks and processes: ");
    scanf("%d%d",&nb,&np);

    printf("Enter block sizes: ");
    for(i=0;i<nb;i++) scanf("%d",&b[i]);

    printf("Enter process sizes: ");
    for(i=0;i<np;i++) scanf("%d",&p[i]);

    for(i=0;i<np;i++){
        for(j=0;j<nb;j++)
            if(b[j]>=p[i]){
                printf("P%d->B%d\n",i+1,j+1);
                b[j]-=p[i]; break;
            }
        if(j==nb) printf("P%d not allocated\n",i+1);
    }
}
