extern "C" {
#include "utils.h"
}

#include "gtest/gtest.h"

#include <stdlib.h>

static void free_string_array(char*** argv, int num_str);

TEST(CommandParsingTest, BasicCommand) {
  char** argv = NULL;
  int argc = -1;

  mysh_parse_command("cd test", &argc, &argv);

  ASSERT_EQ(argc, 2);
  EXPECT_STREQ(argv[0], "cd");
  EXPECT_STREQ(argv[1], "test");

  free_string_array(&argv, argc);
}

TEST(CommandParsingTest, SingleCommand) {
  char** argv = NULL;
  int argc = -1;

  mysh_parse_command("pwd", &argc, &argv);

  ASSERT_EQ(argc, 1);
  EXPECT_STREQ(argv[0], "pwd");

  free_string_array(&argv, argc);
}

TEST(CommandParsingTest, Redirection1) {
  char** argv = NULL;
  int argc = -1;

  mysh_parse_command("pwd > curdir.txt", &argc, &argv);

  ASSERT_EQ(argc, 3);
  EXPECT_STREQ(argv[0], "pwd");
  EXPECT_STREQ(argv[1], ">");
  EXPECT_STREQ(argv[2], "curdir.txt");

  free_string_array(&argv, argc);
}

TEST(CommandParsingTest, Redirection2) {
  char** argv = NULL;
  int argc = -1;

  mysh_parse_command("pwd > curdir.txt | less", &argc, &argv);

  ASSERT_EQ(argc, 5);
  EXPECT_STREQ(argv[0], "pwd");
  EXPECT_STREQ(argv[1], ">");
  EXPECT_STREQ(argv[2], "curdir.txt");
  EXPECT_STREQ(argv[3], "|");
  EXPECT_STREQ(argv[4], "less");

  free_string_array(&argv, argc);
}

TEST(CommandParsingTest, SpaceBeforeString) {
  char** argv = NULL;
  int argc = -1;

  mysh_parse_command("    \n  \t pwd > curdir.txt | less", &argc, &argv);

  ASSERT_EQ(argc, 5);
  EXPECT_STREQ(argv[0], "pwd");
  EXPECT_STREQ(argv[1], ">");
  EXPECT_STREQ(argv[2], "curdir.txt");
  EXPECT_STREQ(argv[3], "|");
  EXPECT_STREQ(argv[4], "less");

  free_string_array(&argv, argc);
}

TEST(CommandParsingTest, EmptyCommand) {
  char** argv = NULL;
  int argc = -1;

  mysh_parse_command("   \n \t    ", &argc, &argv);

  ASSERT_EQ(argc, 1);
  EXPECT_STREQ(argv[0], "");

  free_string_array(&argv, argc);
}

static void free_string_array(char*** argv, int num_str) {
  for (int i = 0; i < num_str; ++i) {
    free((*argv)[i]);
  }

  free(*argv);

  *argv = NULL;
}
