
/* null pointer dereference should kill process */
#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
   uint *pointer = (uint*)0;
   *pointer = 15;
   printf(1,"%x %x\n", pointer, *pointer);
   exit();
}
