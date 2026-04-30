#include <stdio.h>
int main(){
    int n,m,i,j,k,alloc[10][10],max[10][10],need[10][10],avail[10],f[10]={0},safe[10],c=0;

    printf("Enter processes and resources: ");
    scanf("%d%d",&n,&m);

    printf("Enter Allocation:\n");
    for(i=0;i<n;i++) for(j=0;j<m;j++) scanf("%d",&alloc[i][j]);

    printf("Enter Max:\n");
    for(i=0;i<n;i++) for(j=0;j<m;j++) scanf("%d",&max[i][j]);

    printf("Enter Available:\n");
    for(i=0;i<m;i++) scanf("%d",&avail[i]);

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            need[i][j]=max[i][j]-alloc[i][j];

    while(c<n){
        for(i=0;i<n;i++){
            if(!f[i]){
                for(j=0;j<m;j++) if(need[i][j]>avail[j]) break;
                if(j==m){
                    for(k=0;k<m;k++) avail[k]+=alloc[i][k];
                    safe[c++]=i; f[i]=1;
                }
            }
        }
    }

    printf("Safe sequence: ");
    for(i=0;i<n;i++) printf("P%d ",safe[i]);
}
