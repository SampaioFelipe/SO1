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

  // while (1) {
  // }



  // if(pid == 0){
  //   printf(1, "Filho funcionando\n");
  //   //exit();
  // }
  // else
  //   printf(1, "Pai funcionando\n");


  // for(n=0; n<N; n++){
  //   pid = cowfork();
  //   if(pid < 0)
  //     break;
  //
  //   if(pid == 0){
  //     exit();
  //   }
  // }
  //
  // if(n == N){
  //   printf(1, "fork claimed to work N times!\n", N);
  //   exit();
  // }
  //
  // for(; n > 0; n--){
  //   if(wait() < 0){
  //     printf(1, "wait stopped early\n");
  //     exit();
  //   }
  // }
  //
  // if(wait() != -1){
  //   printf(1, "wait got too many\n");
  //   exit();
  // }
}

int main(int argc, char const *argv[]) {
  testeCowfork();
  exit();
}
