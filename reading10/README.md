Reading 10
==========

1. 1) switch (childId = fork()){
      	case -1: 
	   perror("Something went wrong");
	...
      }
   2) open(path, O_TRUNC);
   3) fseek(file, 10, SEEK_SET);
   4) struct stat s;
      stat(path, &s);
      if (S_ISDIR(s.st_mode)) { ...
   5) fork();
   6) execl(/bin/ls)
   7) kill(90187,SIGINT)
   8) waitpid(child, &status, 0)

