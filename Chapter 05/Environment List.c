#include<stdio.h>

/* This code Helps us to prints the all the 
 Environments available in the operating system.
*/
int main(){

    extern char **environ;
    char **environment_list = environ;

    while(*environment_list != NULL){
        printf("%s\n", *environment_list);
        environment_list++;
    }

    return 0;
}
