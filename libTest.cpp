#include<iostream>
#include "libHead.cpp"

int main()
{
	fun1();
	fun2();
}

/*
For creating static libraries:
1) Make Header file containing the function declarations.
2) Create files containing the function definitions
3) Compile the files from step 2 with the -c flag.
4) Use ar rcs <file1> ... <filen> -o <library.a>

For creatinf dynamic libraries:
Steps 1 and 2 common.
3) Compile the files with -c and -fPIC flags.
4) Use g++ -shared <file1> ... <filen> -o <library.so>
5) Add library path to $LD_LIBRARY_PATH.

