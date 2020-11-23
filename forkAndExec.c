using namespace std;

#include <iostream>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
   pid_t pid;
  // pid_t wait(int *stat_loc);

   char * argsCopied[argc]; //new array to copy values of argv 
   //fork a child process
   pid = fork();

   for(int i = 0; i<argc; i++) //array to hold argv commands
   {
      argv[i];
   }


   /*copy values of argv into argsCopied
    * starting at argv[1]
    */
   for(int i = 0; i<argc;i++)
   {
      argsCopied[i] = argv[i+1];
   }


   //check if pid is negative 
   if (pid < 0) //an error occurred
   {
      perror("Error!");
      return 1;
   }

   else if (pid==0) //child process
   {
      printf("Child process pid is, pid=%u\n", getpid());


      if(( execvp(argv[1], &argsCopied[0]))< 0) //exec call
      {
           perror("Error ");
           return(-1);
      }


   }

   else //parent process
   {
      // printf( "Parent process pid is, pid=%u\n",getppid());
      //parent will wait for the child to complete
      pid = wait(NULL);
      printf("Parent process pid is, pid=%u\n",getpid());
      printf("Child Complete");
   }

   return 0;

}
