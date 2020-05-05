#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>

int rmdir(char *dirname);

int main(){

    int isRemoved;
    isRemoved = rmdir("Linux");

    if(isRemoved == 0){ // The value is 0 for Successful 
        printf("Directory is Deleted Succesfully\n");
    }else{  // Value is -1 if it is unsuccessful.
        printf("Unable to Delete Directory\n");
    }

    return 0;
}