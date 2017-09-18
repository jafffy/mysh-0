#ifndef MYSH_COMMANDS_H_
#define MYSH_COMMANDS_H_

/**
  do_cd(argc, argv)

  params:
    argc: # of arguments. argc must be 2. just "cd" doesn't be approved.
    argv: a list of arguments.

  returns:
    If success, return 0.
    Else if arguments are not valid, return -1.
*/
int do_cd(int argc, char** argv);

/**
  do_pwd(argc, argv)

  params:
    argc: # of arguments. argc must be 1.
    argv: a list of arguments.

  returns:
    If success, return 0.
    Else if arguments are not valid, return -1.
*/
int do_pwd(int argc, char** argv);

/**
  validate_cd_argv(argc, argv)

  returns:
    If success, return 1. (true)
    Else return 0. (false)
*/
int validate_cd_argv(int argc, char** argv);
/**
  validate_pwd_argv(argc, argv)

  returns:
    If success, return 1. (true)
    Else return 0. (false)
*/
int validate_pwd_argv(int argc, char** argv);

#endif // MYSH_COMMANDS_H_
