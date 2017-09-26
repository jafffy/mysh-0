#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "commands.h"

int do_cd(int argc, char** argv) {
  if (!validate_cd_argv(argc, argv))
    return -1;

  // TODO: Fill it!
  chdir(argv[1]);
  return 0;
}

int do_pwd(int argc, char** argv) {
  if (!validate_pwd_argv(argc, argv))
    return -1;

  // TODO: Fill it!
  char output[200];
  getcwd(output,200);
  printf("%s\n",output);
  return 0;
}

int validate_cd_argv(int argc, char** argv) {
  // TODO: Fill it!
  if (strcmp(argv[0],"cd")==0 && argc>=2)
    return 1;
}

int validate_pwd_argv(int argc, char** argv) {
  // TODO: Fill it!
  if(strcmp(argv[0],"pwd")==0)
    return 1;
}
