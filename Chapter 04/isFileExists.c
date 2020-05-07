#include<stdio.h>
#include<unistd.h>

int main(){

    char filepath[100];
    // Taking the Input from the user
    printf("Enter the filename with path: ");
    scanf("%[^\n]%*c", filepath);   

    int status;

    status = access(filepath, F_OK);
    if(status == 0){
        printf("File Exists\n");
    }else{
        printf("File Doesn't Exists\n");
    }
}