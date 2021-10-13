/* timer.c */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <signal.h>
#include <unistd.h>

int count = 0;
bool alarmed = false;

void alarmhandler(int signum)
{ //signal handler
  count++;
  alarmed=false;
}

void handler(int signum)
{ //signal handler
  printf("The program ran for %d seconds\n", count);
  exit(1);
}

int main(int argc, char * argv[])
{
  signal(SIGALRM, alarmhandler);
  signal(SIGINT, handler);
  
  while(1){
    if (!alarmed){
      alarm(1);
      alarmed=true;
    }
  } ; //busy wait for signal to be delivered
  
  return 0; //never reached
}