#include "types.h"
#include "stat.h"
#include "user.h"

#define N  2

void testeCowfork()
{
  int pid;
  printf(1, "Teste do CowFork\n");

  pid = cowfork();

  if(pid==0){
    printf(1,"funcionando o filho\n");
  }
  else{
    printf(1,"funcionando o pai\n");
  }

  while (1);
}

int main(int argc, char const *argv[]) {
  testeCowfork();
  exit();
}
