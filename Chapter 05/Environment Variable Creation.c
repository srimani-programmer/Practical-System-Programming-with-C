#include<stdio.h>
#include<stdlib.h>

int main(){

    char *variable_name;
    printf("Enter the variable to create:");
    scanf("%s",variable_name);
    // Returns 0 --> On Success || -1 on failure
    int status = putenv(variable_name);
    if(status == 0){
        printf("Environment Variable Created Successfully.!\n");
    }else{
        printf("Unable to create a Environment variable.\n");
    }

    printf("%s\n", getenv(variable_name));
    return 0;
}

