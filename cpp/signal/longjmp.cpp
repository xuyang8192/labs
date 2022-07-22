#include <cstdio>
#include <csignal>
#include <unistd.h>
#include <setjmp.h>

// confirm longjmp will skip necessary steps after signal handler returns

static jmp_buf buf;
static volatile int count = 100;
void sig_handle(int);
void print_block();

int main()
{
	if (SIG_ERR == signal(SIGINT, sig_handle))
	{
		return -1;
	}

    int ret = setjmp(buf);
	if (ret == 0)
	{
		printf("setjmp saved\n");
	}
	else
	{
		printf("longjmp ret %d\n", ret);
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

	++count;
	longjmp(buf, count);
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
}
