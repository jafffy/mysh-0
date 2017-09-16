extern "C" {
#include "utils.h"
}

#include "gtest/gtest.h"

#include <stdlib.h>

TEST(CommandParsingTest, BasicCommand) {
  char** argv;
  int argc = -1;

  argv = (char**)malloc(2);
  for (int i = 0; i < 2; ++i) {
    argv[i] = (char*)malloc(512);
  }

  mysh_parse_command("cd test", &argc, argv);

  EXPECT_EQ(argc, 2);
  EXPECT_STREQ(argv[0], "cd");
  EXPECT_STREQ(argv[1], "test");

  for (int i = 0; i < 2; ++i) {
    free(argv[i]);
  }
  free(argv);
}
