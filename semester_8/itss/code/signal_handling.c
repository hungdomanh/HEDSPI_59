#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

#define SIG_OK 0
#define SIG_NG -1
#define LOOP_ON   0
#define LOOP_OFF  1

int loopFlag = LOOP_ON;  /* Loop flag */

// Global variable
void handle_sigalrm(int signal);
void do_sleep(int seconds) {
    struct sigaction sa;
    sigset_t mask;
    
    sa.sa_handler = &handle_sigalrm; // Intercept and ignore SIGALRM
    sa.sa_flags = SA_RESETHAND; // Remove the handler after first signal
    sigfillset(&sa.sa_mask);
    sigaction(SIGALRM, &sa, NULL);
    
    // Get the current signal mask
    sigprocmask(0, NULL, &mask);

    // Unblock SIGALRM
    sigdelset(&mask, SIGALRM);

    // Wait with this mask
    alarm(seconds);
    sigsuspend(&mask);

    printf("sigsuspend() returned\n");
}

void handle_sigalrm(int signal) {
    if (signal != SIGALRM) {
        fprintf(stderr, "Caught wrong signal: %d\n", signal);
    }

    printf("Got sigalrm, do_sleep() will end\n");
}
// Prototype declaration
void sigHandleSighup(int sigNo);

/**
 * The main processing
 * 
 * param  none
 * 
 * return SIG_OK fix
 */
void handle_signal(int signal) {
    const char *signal_name;
    sigset_t pending;

    // Find out which signal we're handling
    switch (signal) {
        case SIGHUP:
            signal_name = "SIGHUP";
            break;
        case SIGUSR1:
            signal_name = "SIGUSR1";
            break;
        case SIGINT:
            printf("Caught SIGINT, exiting now\n");
            exit(0);
        default:
            fprintf(stderr, "Caught wrong signal: %d\n", signal);
            return;
    }

    /*
     * Please note that printf et al. are NOT safe to use in signal handlers.
     * Look for async safe functions.
     */
    printf("Caught %s, sleeping for ~3 seconds\n"
           "Try sending another SIGHUP / SIGINT / SIGALRM "
           "(or more) meanwhile\n", signal_name);
    /*
     * Indeed, all signals are blocked during this handler
     * But, at least on OSX, if you send 2 other SIGHUP,
     * only one will be delivered: signals are not queued
     * However, if you send HUP, INT, HUP,
     * you'll see that both INT and HUP are queued
     * Even more, on my system, HUP has priority over INT
     */
    do_sleep(3);
    printf("Done sleeping for %s\n", signal_name);

    // So what did you send me while I was asleep?
    sigpending(&pending);
    if (sigismember(&pending, SIGHUP)) {
        printf("A SIGHUP is waiting\n");
    }
    if (sigismember(&pending, SIGUSR1)) {
        printf("A SIGUSR1 is waiting\n");
    }

    printf("Done handling %s\n\n", signal_name);
}

int main()
{
    struct sigaction sa;
    sa.sa_handler = &handle_signal;
    sa.sa_flags = SA_RESTART;
sigfillset(&sa.sa_mask);

    // Intercept SIGHUP and SIGINT
    if (sigaction(SIGHUP, &sa, NULL) == -1) {
        perror("Error: cannot handle SIGHUP"); // Should not happen
    }

    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("Error: cannot handle SIGUSR1"); // Should not happen
    }

    // Will always fail, SIGKILL is intended to force kill your process
    if (sigaction(SIGKILL, &sa, NULL) == -1) {
        perror("Cannot handle SIGKILL"); // Will always happen
        printf("You can never handle SIGKILL anyway...\n");
    }

    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("Error: cannot handle SIGINT"); // Should not happen
    }
  printf("main       : start\n");
//   time_t start, end;
//   start = time(NULL);
//   double elapsed;
//   // Signal handler function registration
//   signal(SIGHUP, sigHandleSighup);

//   // Loop during the time the loop flag is ON
//   while(loopFlag == LOOP_ON){
//     end = time(NULL);
//     elapsed = difftime(end, start);
//     printf("Looping\n");
//     if (elapsed >= 5.0) 
        
//         {
//             loopFlag = 1;
//             return SIGALRM;
//         }
//   }
    for (; ;) {
        printf("\n Sleeping for ~3 seconds\n");
        do_sleep(3);
    }
  printf("main       : end\n");
  return SIG_OK;
}

/**
 * Signal handler function that receives signal SIGHUP
 * 
 * param sigNo Received signal number
 *
 * return  none
 */
void sigHandleSighup(int sigNo)
{
  printf("Signal No. %d\n", sigNo);
  loopFlag = LOOP_OFF;
  return;
}