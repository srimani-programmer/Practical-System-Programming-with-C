#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    // Prints the Current Running Process ID.
    printf("Current Process  ID: %d\n", getpid());
    exit(0);
    printf("This line will not execute.\n");

    return 0;
}