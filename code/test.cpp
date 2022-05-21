#include <stdio.h>
#include "base.h"

//TODO(Cian): once memory/linked lists(maybe) have been implemented, implement a basic unit testing framework
#define TestI(testInfo, expected, actual) printf("%s expected: %d, actual: %d \n", ##testInfo, expected, actual)

int main(u32 argc, u8 **argv) {
	TestI("Compiler Clang?", 0, COMPILER_CLANG);
	TestI("Compiler MSVC?", 1, COMPILER_VS);
	TestI("Compiler GCC?", 0, COMPILER_GCC);
	
	TestI("OS Windows 64?", 1, OS_WIN64);
	TestI("Compiler GCC?", 0, OS_LINUX);

	return 0;
}