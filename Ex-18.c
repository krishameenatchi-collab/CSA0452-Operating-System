#include <stdio.h>
int mutex=1,full=0,empty,x=0;

void wait(int *s){(*s)--;}
void signal(int *s){(*s)++;}

int main(){
    int n,i;
    printf("Enter buffer size and operations: ");
    scanf("%d%d",&empty,&n);

    for(i=0;i<n;i++){
        wait(&empty); wait(&mutex);
        printf("Produced %d\n",++x);
        signal(&mutex); signal(&full);

        wait(&full); wait(&mutex);
        printf("Consumed %d\n",x--);
        signal(&mutex); signal(&empty);
    }
}
