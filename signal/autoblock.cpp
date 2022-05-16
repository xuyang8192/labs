#include <cstdio>
#include <csignal>
#include <unistd.h>
#include <setjmp.h>

// confirm wether signals are auto blocked in signal handler

void sig_handle(int);
void print_block();

int main()
{
	if (SIG_ERR == signal(SIGINT, sig_handle))
	{
		return -1;
	}
	if (SIG_ERR == signal(SIGABRT, sig_handle))
	{
		return -1;
	}

	while(1)
	{
		print_block();
		pause();
		printf("\nnew loop begin\n");
	}
	return 0;
}

void sig_handle(int sig)
{
	printf("\nrecv sig %d\n", sig);
	print_block();
}

void print_block()
{
	sigset_t s;
	int ret = sigprocmask(SIG_BLOCK, nullptr, &s);
	if (ret < 0)
	{
		printf("fail proc mask %d\n", ret);
		return;
	}

	printf("SIGINT %sblocked in handler\n", sigismember(&s, SIGINT) > 0? "": "not ");
	printf("SIGABRT %sblocked in handler\n", sigismember(&s, SIGABRT) > 0? "": "not ");
}


