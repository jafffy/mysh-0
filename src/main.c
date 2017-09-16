#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "commands.h"
#include "utils.h"

int main()
{
  char buf[8096];
  int argc;
  char** argv;

  // initialize command buffer
  argv = (char**)malloc(32);
  for (int i = 0; i < 32; ++i) {
    argv[i] = (char*)malloc(8096);
  }

  while (1) {
    fgets(buf, 8096, stdin);

    mysh_parse_command(buf, &argc, argv);

    if (strcmp(buf, "") == 0) {
      continue;
    } else if (strcmp(argv[0], "cd") == 0) {
      do_cd(argc, argv);
    } else if (strcmp(argv[0], "pwd") == 0) {
      do_pwd(argc, argv);
    } else if (strcmp(argv[0], "exit") == 0) {
      break;
    } else {
      fprintf(stderr, "%s: command not found\n", argv[0]);
    }
  }

  // destroy command buffer
  for (int i = 0; i < 32; ++i) {
    free(argv[i]);
  }
  free(argv);

  return 0;
}
