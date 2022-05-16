#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	char *p = (char*)malloc(8);
	char *t = (char*)sbrk(0);
	printf("initial p %p\n", (void*) p); // initial p 0x55e132df62a0
	printf("initial t %p\n", (void*) t); // initial t 0x55e132e17000
	sleep(5);
	char *q = p;
	while(1)
	{
		printf("%p %d\n", (void*) p, *p);
		++p;
	}
	// 0x55e132e16fff 0
    // Segmentation fault (core dumped)
	return 0;
}
