#include<stdio.h>   // Standard I/O Routines Library
#include<unistd.h>  // Unix Standard Library
#include<pthread.h> // POSIX Thread Creation Library

// A simple thread function to say greetings.
void *say_greetings(){
    
    for(int i = 0; i < 10; i++){
        printf("Hello From Thread function.\n");
        usleep(1);
    }
    return NULL;
}

int main(){

    pthread_t thread1;  // Thread Descriptor
    pthread_create(&thread1, NULL, say_greetings, NULL);    // Inbuilt thread function to create a thread.

    // Main Thread Logic.
    for(int i = 0; i < 10; i++){
        printf("Hello From Main Thread\n");
        usleep(1);
    }

    // Joining the Thread with another thread Object.
    pthread_join(thread1, NULL); 

    return 0;
}
