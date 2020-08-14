#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define PERMISSIONS 0777

// Definition of Message Buffer
struct messageBuffer {
   long mtype;
   char data[1024];
};

// Global Declaration of Message Buffer Object
struct messageBuffer object;

// Global Data for Variables
int msqid;
int string_status;
key_t key;

// Function to receive the data from message queue.
void receiveMessages(){

   while(1) {
      // Trying to retrieve the data from message queue by checking the condition.
      // If there is any error, while retrieving the data then 
      // condition will throw an error and exits the function.
      if (msgrcv(msqid, &object, sizeof(object.data), 0, 0) == -1) {
         perror("msgrcv");
         exit(1);
      }

      printf("received: \"%s\"\n", object.data);
      string_status = strcmp(object.data,"end");
      if (string_status == 0)
         break;
   }
}
int main() {

   // Creating the unique Identifier for the message queue.
   if ((key = ftok("messagequeue.txt", 'B')) == -1) {
      perror("ftok");
      exit(1);
   }
   // Connecting the Message Queue.
   if ((msqid = msgget(key, PERMISSIONS)) == -1) {  
      // connect to the queue
      printf("Unable to Create the Message Queue.\n");
      perror("msgget");
      exit(1);
   }

   printf("Message Queue is ready to receive messages.\n");
   // Calling the receive message function to reterive the data from message queue.
   receiveMessages();

   printf("Message Queue is done with receiving messages.\n");
   return 0;
}
