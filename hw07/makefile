# C++ verison
CPP_FLAGS = -Werror '-std=c++11'

# Target file
Target = CmpTree

#dir for *.o files
O_PATH = ./obj

#source file dir path
SUBDIR := $(shell pwd)

# Compile rules
${Target} : ${Target}.o
	g++ ${CPP_FLAGS} *.o -o $@ 
%.o : %.cpp
	g++ ${CPP_FLAGS} -c $< -o $@ 

# make clean
clean:
	rm -f *.o main *.out ${Target}