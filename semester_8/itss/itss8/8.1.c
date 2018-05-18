/*
  truy cap bo nho chia se va in ra thong tin bo nho chia se
*/
#include <stdio.h>
#include <sys/shm.h> 
#include <sys/stat.h> 

int main() {
  int* shm, shmid, k;
  shmid = shmget(IPC_PRIVATE,128,IPC_CREAT|0666); 
  shm= (int*) shmat(shmid,0,0); 

  printf("shared memory ID: %d\n", shmid);
  printf("Key: IPC_PRIVATE\n");
  printf("Size: 128\n");
  printf("Access authority: IPC_CREAT|0666\n");

  int i =0;
  for(;i<3;i++) {
    if(fork()==0) {
      shm[0]=i;
      printf("Process %d reads: %d\n", getpid(),shm[0]);
      shmdt((void *)shm);
      shmctl(shmid, IPC_RMID, (struct shmid_ds*)0);
      sleep(1);
    }
  }
  return(0);
}