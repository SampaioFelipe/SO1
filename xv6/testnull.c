
/* null pointer dereference should kill process */
#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
   //int ppid = getpid();
   uint *pointer = (uint*)0;
   *pointer = 15;
   printf(1,"%x %x\n", pointer, *pointer);
   exit();
  //  if (fork() == 0) {
  //     uint * nullp = (uint*)0;
  //     printf(1,"null dereference: ");
  //     printf(1,"%x %x\n", nullp, *nullp);
  //     // this process should be killed
  //     printf(1,"TEST FAILED\n");
  //     //kill(ppid);
  //     exit();
  //  } else {
  //     wait();
  //  }
   //
  //  printf(1, "TEST PASSED\n");
  //  exit();
}
