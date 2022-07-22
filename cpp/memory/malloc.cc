#include <stdlib.h>

int main()
{
	int *p = (int*)malloc(64);
	free(p);
	return 0;
}

