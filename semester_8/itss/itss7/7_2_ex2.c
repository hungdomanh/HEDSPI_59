/*
Viet chuong trinh thuc hien: Su dung tin hieu SIGLARM trong khi cac ham sleep dang hoat dong
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

unsigned int secs = 20;
unsigned int usecs = 20000000;
long nsecs = 2000;
void sigHandleSigalrm(int sigNo);

int main(int argc, char const *argv[]) {
  printf("main       : start\n");
  struct timespec time1, time2;
  time1.tv_sec = nsecs / 100;
  time1.tv_nsec = nsecs;
// Signal handler function registration
  signal(SIGALRM, sigHandleSigalrm);
  printf("Test sleep with: %ds\n", secs);1
  alarm(secs);
  sleep(secs);
  printf("End test sleep\n");

  signal(SIGALRM, sigHandleSigalrm);
  printf("Test usleep with: %dus\n", usecs);
  alarm(usecs / 1000000);
  usleep(usecs);
  printf("End test usleep\n");

  signal(SIGALRM, sigHandleSigalrm);
  printf("Test nsleep with: %ldns\n", nsecs*10000000);
  alarm(nsecs / 100);
  if(nanosleep(&time1, &time2) < 0) {
    printf("Test nanosleep failed\n");
    return -1;
  }
  printf("End test nsleep\n");
  printf("main       : end\n");
  return 0;
}

void sigHandleSigalrm(int sigNo) {
  printf("-------------Tin hieu SIGALRM den\n");
  return;
}
