#include <sys/stat.h>
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

int main(int argc, char **argv){
  struct stat s;
  struct dirent *dp;
  DIR *dirp = opendir(".");
  while ((dp = readdir(dirp)) != NULL){
    stat(dp->d_name, & s);
    if (S_ISREG(s.st_mode))
      printf("%s %jd\n",dp->d_name, s.st_size);
  }
  closedir(dirp);


}
