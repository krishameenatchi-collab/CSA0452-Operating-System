#include <stdio.h>
int rc=0,mutex=1,wrt=1;

void wait(int *s){(*s)--;}
void signal(int *s){(*s)++;}

int main(){
    wait(&mutex); rc++;
    if(rc==1) wait(&wrt);
    signal(&mutex);
    printf("Reader reading\n");

    wait(&wrt);
    printf("Writer writing\n");
    signal(&wrt);

    wait(&mutex); rc--;
    if(rc==0) signal(&wrt);
    signal(&mutex);
}
