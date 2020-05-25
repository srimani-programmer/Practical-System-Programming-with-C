#include <unistd.h>
 
int main() {

  char *binary_executable = "ls";
  char *arg1 = "-l";
  char *arg2 = "-a";
  char *arg3 = ".";
  
  // System call to perform the ls -la operation in the
  // CWD (Current Working Directory)
  execlp(binary_executable, binary_executable, NULL);
 
  return 0;
}