#include <time.h>
#include <stdio.h>
#include <unistd.h> 
#include <fcntl.h>
#include <string.h>

 int main()
  {
   pid_t p;
   clock_t time;
   printf ("\nOriginal program pid: %d\n", getpid());
   p = fork();
   if (p==0) {
    time = clock();
    printf ("\nChild pid: %d and ppid: %d\n", getpid(), p);
    time = clock()-time;
    printf ("Time child's process: %f SEC \n", (double)time/CLOCKS_PER_SEC);

    int file = open ("Child's_file.txt", O_RDWR|O_CREAT, 0777);
    char buff[1024] = ("File create successfully!");
    write (file, buff, strlen (buff));
    close (file);
    printf ("File of child's process contains:%s\n\n", buff);
   }

   else {
    time = clock();
    printf ("\nParent pid: %d and ppid: %d\n", getpid(), p);
    time = clock() - time;
    printf ("Time parent's process: %f SEC \n", (double)time/CLOCKS_PER_SEC);

    int file = open ("parent's_file.txt", O_RDWR|O_CREAT, 0777);
    char buff[1024] = ("File create successfully!");
    write (file, buff, strlen (buff));
    close (file);
    printf ("File of parent process contains:%s\n", buff);
   }
 return 0;
  }
