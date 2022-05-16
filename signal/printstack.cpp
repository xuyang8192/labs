#include <cstdio>
#include <csignal>
#include <unistd.h>

// print variable address within signal handler

void sig_handle(int);

int main()
{
	if (SIG_ERR == signal(SIGINT, sig_handle))
	{
		return -1;
	}

	int a = 0;
	printf("address of var outside sig handler %p\n", (void*)&a);

	while(1);
	return 0;
}

void sig_handle(int sig)
{
	printf("\nrecv sig %d\n", sig);
	int a = 0;
	printf("address of var in sig handler %p\n", (void*)&a);
}


