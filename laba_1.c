#include <time.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
 pid_t p;
 clock_t time;
 printf ("Original program pid: %d\n", getpid());
 p = fork();
 if (p==0) { 
  time = clock();
  printf ("Child pid: %d and child's fork returned: %d and ppid: %d\n", getpid(), p, getppid());
  time = clock() - time;
  printf ("Time child's process: %f\n", (double)time/CLOCKS_PER_SEC);
 }
 else {
  time = clock();
  printf ("Parent pid: %d and parent's fork returned: %d\n", getpid(), p);
  time = clock() - time;
  printf ("Time parent's process: %f\n", (double)time/CLOCKS_PER_SEC);
 }
}
