#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

// Permissions for the Message Queue.
#define PERMISSIONS 0777

// Definition of Message Buffer
struct messageBuffer {
   long messageType;
   char data[1024];
};

// Global Declaration of Message Buffer Object
struct messageBuffer object;

// Global Data for Variables
int msqid;
int len;
int string_status;
key_t key;

// Function to send the data to the message queue.
void sendMessage(){

   while(fgets(object.data, sizeof object.data, stdin) != NULL) {
      
      // Calculating the length of the data object.
      len = strlen(object.data);
      if (object.data[len-1] == '\n') object.data[len-1] = '\0';

      // If message queue unable to send the message then 
      // below condition will Checks and throws an error and exit the message queue.
      if (msgsnd(msqid, &object, len+1, 0) == -1){
         perror("msgsnd");
         exit(1);
      }
      // Checking for the sender exit status.
      string_status = strcmp(object.data, "end");
      if(string_status == 0)
         break;
   }

   if (msgctl(msqid, IPC_RMID, NULL) == -1) {
      perror("msgctl");
      exit(1);
   }

   printf("Message Queue is done with sending messages.\n");
}
int main() {

   system("touch messagequeue.txt");
   
   if ((key = ftok("messagequeue.txt", 'B')) == -1) {
      perror("ftok");
      exit(1);
   }
   
   if ((msqid = msgget(key, PERMISSIONS | IPC_CREAT)) == -1) {
      perror("msgget");
      exit(1);
   }
   printf("Message Queue is ready to send messages.\n");
   printf("Enter lines of text, enter \'end\' to quit:\n");
   object.messageType = 1; // Setting the message type value to 1.
  
   // Calling the function to send the data to the message queue.
   sendMessage();
   
   // Deleting the created file
   system("rm messagequeue.txt");
   
   return 0;
}





