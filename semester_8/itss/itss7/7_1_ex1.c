/*
Sau 1 thoi gian - thoi gian nay dua tren tham so dong lenh,
thi hien thi thoi gian do len man hinh console. Su dung SIGALRM
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

#define LOOP_ON 0
#define LOOP_OFF 1

int flag = LOOP_ON;

// Prototype declaration
void sigHandleSigalrm(int sigNo);

int main(int argc, char const *argv[]) {
  printf("main       : start\n");
  int time = atoi(argv[1]);
// Signal handler function registration
  signal(SIGALRM, sigHandleSigalrm);
  alarm(time);

  while(flag == LOOP_ON) {
  }
  printf("The time: %d\n", time);
  printf("main       : end\n");
  return 0;
}

void sigHandleSigalrm(int sigNo) {
  flag = LOOP_OFF;
  return;
}
