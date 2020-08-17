#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>


#define FIFO_FILE "FIFO"

int file_descriptor;
char message_buffer[1024];
int read_buffer_bytes;

void receiveData(){

   while(1) {

      file_descriptor = open(FIFO_FILE, O_RDONLY);
      read_buffer_bytes = read(file_descriptor, message_buffer, sizeof(message_buffer));
      message_buffer[read_buffer_bytes] = '\0';
      
      if((int)strlen(message_buffer) == 0){
         close(file_descriptor);
         break;
      }
      
      printf("Received Message: %s\n", message_buffer);
   }
}

int main() {
   
   // Create the FIFO if it does not exist
   mknod(FIFO_FILE, S_IFIFO|0640, 0);

   // Function to receive the data from pipe.
   receiveData();

   return 0;
}