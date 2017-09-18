#include <string.h>

#include "commands.h"

int do_cd(int argc, char** argv) {
  if (!validate_cd_argv(argc, argv))
    return -1;

  // TODO: Fill it!
  return 0;
}

int do_pwd(int argc, char** argv) {
  if (!validate_pwd_argv(argc, argv))
    return -1;

  // TODO: Fill it!

  return 0;
}

int validate_cd_argv(int argc, char** argv) {
  // TODO: Fill it!
  return 1;
}

int validate_pwd_argv(int argc, char** argv) {
  // TODO: Fill it!
  return 1;
}
