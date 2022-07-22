#include <cstdio>
#include <csignal>
#include <unistd.h>

// simple test of handler register for signals

void sig_handle(int);

int main()
{
	if (SIG_ERR == signal(SIGSEGV, sig_handle))
	{
		return -1;
	}

	if (SIG_ERR == signal(SIGABRT, sig_handle))
	{
		return -1;
	}

	if (SIG_ERR == signal(SIGINT, sig_handle))
	{
		return -1;
	}

	// pause();
	while(1);
	return 0;
}

void sig_handle(int sig)
{
	printf("\nrecv sig %d\n", sig);
}


