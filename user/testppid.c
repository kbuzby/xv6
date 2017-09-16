#include "types.h"
#include "stat.h"
#include "user.h"

int main(void) {

  int parent = getpid();
  int child=fork();
  if (child==0) {
    if (parent == getppid()) {
      printf(1,"SUCCESS\n");
    } else {
      printf(1,"FAILURE");
    }
  }
  
  wait();
}