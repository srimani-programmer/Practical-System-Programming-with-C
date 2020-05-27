#include<stdio.h>
#include<unistd.h>
#include<signal.h>

int main(){

    printf("My PID: %d\n",getpid());
    sleep(2);
    kill(getpid(), SIGQUIT);
    return 0;
}