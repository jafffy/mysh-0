# For implementation
CC=gcc -std=c99
CFLAGS=-I./src -I./include
LIB=
OBJ=./src/utils.o ./src/commands.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

mysh: $(OBJ)
	$(CC) -o $@ $^ ./src/main.c $(CFLAGS)

# For testing
CXX=g++ -std=c++11
TESTING_FLAGS=-I./tests/src -I./tests/include $(CFLAGS) -Wno-write-strings
TESTING_LIB=-lgtest -lgtest_main -L./tests/lib -lpthread $(LIB)
TESTING_SRC=./tests/src/command_parsing_test.cc ./tests/src/command_validate_test.cc
TESTING_EXE=mysh-test

test: $(OBJ)
	$(CXX) $(TESTING_FLAGS) -o $(TESTING_EXE) $(TESTING_SRC) $(OBJ) $(TESTING_LIB)
	./$(TESTING_EXE)

clean:
	rm -f $(TESTING_EXE) $(OBJ) mysh ./src/main.o
