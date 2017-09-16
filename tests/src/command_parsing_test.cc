extern "C" {
#include "utils.h"
}

#include "gtest/gtest.h"

#include <stdlib.h>

static char** alloc_string_array(int num_str, int size_str);
static void free_string_array(char** argv, int num_str);

TEST(CommandParsingTest, BasicCommand) {
  char** argv = alloc_string_array(2, 1024);
  int argc = -1;

  mysh_parse_command("cd test", &argc, argv);

  EXPECT_EQ(argc, 2);
  EXPECT_STREQ(argv[0], "cd");
  EXPECT_STREQ(argv[1], "test");

  free_string_array(argv, 2);
}

TEST(CommandParsingTest, SingleCommand) {
  char** argv = alloc_string_array(1, 1024);
  int argc = -1;

  mysh_parse_command("pwd", &argc, argv);

  EXPECT_EQ(argc, 1);
  EXPECT_STREQ(argv[0], "pwd");

  free_string_array(argv, 1);
}

TEST(CommandParsingTest, Redirection1) {
  char** argv = alloc_string_array(3, 1024);
  int argc = -1;

  mysh_parse_command("pwd > curdir.txt", &argc, argv);

  EXPECT_EQ(argc, 3);
  EXPECT_STREQ(argv[0], "pwd");
  EXPECT_STREQ(argv[1], ">");
  EXPECT_STREQ(argv[2], "curdir.txt");

  free_string_array(argv, 3);
}

TEST(CommandParsingTest, Redirection2) {
  char** argv = alloc_string_array(5, 1024);
  int argc = -1;

  mysh_parse_command("pwd > curdir.txt | less", &argc, argv);

  EXPECT_EQ(argc, 5);
  EXPECT_STREQ(argv[0], "pwd");
  EXPECT_STREQ(argv[1], ">");
  EXPECT_STREQ(argv[2], "curdir.txt");
  EXPECT_STREQ(argv[3], "|");
  EXPECT_STREQ(argv[4], "less");

  free_string_array(argv, 5);
}

TEST(CommandParsingTest, SpaceBeforeString) {
  char** argv = alloc_string_array(5, 1024);
  int argc = -1;

  mysh_parse_command("    \n  \t pwd > curdir.txt | less", &argc, argv);

  EXPECT_EQ(argc, 5);
  EXPECT_STREQ(argv[0], "pwd");
  EXPECT_STREQ(argv[1], ">");
  EXPECT_STREQ(argv[2], "curdir.txt");
  EXPECT_STREQ(argv[3], "|");
  EXPECT_STREQ(argv[4], "less");

  free_string_array(argv, 5);
}

TEST(CommandParsingTest, EmptyCommand) {
  char** argv = alloc_string_array(1, 1024);
  int argc = -1;

  mysh_parse_command("", &argc, argv);

  EXPECT_EQ(argc, 1);
  EXPECT_STREQ(argv[0], "");

  free_string_array(argv, 1);
}

static char** alloc_string_array(int num_str, int size_str) {
  char** argv;

  argv = (char**)malloc(num_str);

  for (int i = 0; i < num_str; ++i) {
    argv[i] = (char*)malloc(size_str);
  }

  return argv;
}

static void free_string_array(char** argv, int num_str) {
  for (int i = 0; i < num_str; ++i) {
    free(argv[i]);
  }

  free(argv);
}
