#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(){

    int isCreated;
    isCreated = mkdir("Linux", 0777);

    if(isCreated == 0){ // The value is 0 for Successful 
        printf("Directory is Created Succesfully\n");
    }else{  // Value is -1 if it is unsuccessful.
        printf("Unable to Create Directory\n");
    }

    return 0;
}