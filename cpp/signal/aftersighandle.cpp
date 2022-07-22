#include <cstdio>
#include <csignal>
#include <unistd.h>

// try handle SIGSEGV without siglongjmp

void sig_handle(int);

int main()
{
	if (SIG_ERR == signal(SIGSEGV, sig_handle))
	{
		return -1;
	}

    int a = 123456789;
    printf("a is now %d", a);

    int *p = nullptr;

    a = *p;
    printf("a is now %d", a);

	while(1);
	return 0;
}

void sig_handle(int sig)
{
	printf("\nrecv sig %d\n", sig);
}


