#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>

#define __NR_add 549

int main() // test program main func.
{
	int a,b; // two parameter
	a=7; b=4;

	#ifdef WRAPPING // if hooking,
		printf("%d add %d = %ld\n", a, b, syscall(__NR_add, getpid()));
	#else // not hooking
		printf("%d add %d = %ld\n", a, b, syscall(__NR_add, a, b));
	#endif
	
	return 0; // exit of program
}