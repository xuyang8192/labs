#include <cstdio>
#include <csignal>
#include <unistd.h>

// try receive SIGSEGV within signal handler

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

	pause();
	return 0;
}

void sig_handle(int sig)
{
	printf("\nrecv sig %d\n", sig);

    int *p = nullptr;
	printf("access nullptr in handler\n");
    int b = *p;
	printf("after accessing nullptr in handler\n");
}


