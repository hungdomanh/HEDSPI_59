/*
Viet chuong trinh thuc hien: Su dung cac ham sleep, uslepp va nanosleep theo
thoi gian nghi
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

unsigned int secs = 2;
unsigned int usecs = 2000000;
long nsecs = 200;

int main(int argc, char const *argv[]) {
  struct timespec time1, time2;
  time1.tv_sec = nsecs / 100;
  time1.tv_nsec = nsecs;
  printf("main       : start\n");
  printf("Test sleep with: %ds\n", secs);
  sleep(secs);
  printf("End test sleep\n");
  printf("Test usleep with: %dus\n", usecs);
  usleep(usecs);
  printf("End test usleep\n");
  printf("Test nsleep with: %ldns\n", nsecs*10000000);
  if(nanosleep(&time1, &time2) < 0) {
    printf("Test nanosleep failed\n");
    return -1;
  }
  printf("End test nsleep\n");
  printf("main       : end\n");
  return 0;
}
