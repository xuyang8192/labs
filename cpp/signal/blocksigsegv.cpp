#include <cstdio>
#include <csignal>
#include <unistd.h>

// try block SIGSEGV

void sig_handle(int);

int main()
{
	if (SIG_ERR == signal(SIGSEGV, sig_handle))
	{
		return -1;
	}

	sigset_t s;
	sigemptyset(&s);
	sigaddset(&s, SIGSEGV);
	if (0 > sigprocmask(SIG_BLOCK, &s, nullptr))
	{
		printf("fail block SIGSEGV\n");
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
}


