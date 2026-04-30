#include <stdio.h>
int main(){
    int b[10],p[10],nb,np,i,j,idx;

    printf("Enter blocks and processes: ");
    scanf("%d%d",&nb,&np);

    printf("Enter block sizes: ");
    for(i=0;i<nb;i++) scanf("%d",&b[i]);

    printf("Enter process sizes: ");
    for(i=0;i<np;i++) scanf("%d",&p[i]);

    for(i=0;i<np;i++){
        idx=-1;
        for(j=0;j<nb;j++)
            if(b[j]>=p[i] && (idx==-1 || b[j]>b[idx])) idx=j;

        if(idx!=-1){ printf("P%d->B%d\n",i+1,idx+1); b[idx]-=p[i]; }
        else printf("P%d not allocated\n",i+1);
    }
}
