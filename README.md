# Simple-Shell-Program

Use fork and one of the exec (e.g. execv, execvp) calls to issue the command and waituntil the command is completed. [NOTE: To see how these work, type man 3 exec or man 3 wait. The man pages also tell you what header files to include.] If a -1 is returned from fork or exec, an error occurred. Use perror to print the command, error and exit. Print out the arguments in a for-loop before forking and executing the command. Print out the process id of the parent and child.
