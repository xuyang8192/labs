#include <stdio.h>

int f();

int main()
{
	printf("main function address %p\n", (void*) &main);
	printf("f function address %p\n", (void*) &f);
	return 0;
}

int f()
{
	return 0;
}

