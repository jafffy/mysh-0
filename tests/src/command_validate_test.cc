extern "C" {
#include "commands.h"
}

#include "gtest/gtest.h"

TEST(CDValidateTest, ValidateCDArgv) {
  int argc = 2;
  char* argv[] = {
    "cd", "."
  };

  ASSERT_EQ(validate_cd_argv(argc, argv), 1);
}

TEST(CDValidateTest, ValidateCDArgv2) {
  int argc = 3;
  char* argv[] = {
    "cd", ".", "."
  };

  ASSERT_EQ(validate_cd_argv(argc, argv), 0);
}

TEST(CDValidateTest, ValidateCDArgv3) {
  int argc = 1;
  char* argv[] = {
    "cd"
  };

  ASSERT_EQ(validate_cd_argv(argc, argv), 0);
}

TEST(CDValidateTest, ValidateCDArgv4) {
  int argc = 2;
  char* argv[] = {
    ".", "cd"
  };

  ASSERT_EQ(validate_cd_argv(argc, argv), 0);
}

TEST(PWDValidateTest, ValidatePWDArgv) {
  int argc = 1;
  char* argv[] = {
    "pwd"
  };

  ASSERT_EQ(validate_pwd_argv(argc, argv), 1);
}

TEST(PWDValidateTest, ValidatePWDArgv2) {
  int argc = 2;
  char* argv[] = {
    "pwd", "cd"
  };

  ASSERT_EQ(validate_pwd_argv(argc, argv), 0);
}

TEST(PWDValidateTest, ValidatePWDArgv3) {
  int argc = 1;
  char* argv[] = {
    "cd"
  };

  ASSERT_EQ(validate_pwd_argv(argc, argv), 0);
}
