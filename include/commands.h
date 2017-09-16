#ifndef MYSH_COMMANDS_H_
#define MYSH_COMMANDS_H_

int do_cd(int argc, char** argv);
int do_pwd(int argc, char** argv);

int validate_cd_argv(int argc, char** argv);
int validate_pwd_argv(int argc, char** argv);

#endif // MYSH_COMMANDS_H_
