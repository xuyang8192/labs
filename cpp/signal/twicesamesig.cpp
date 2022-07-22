#include <cstdio>
#include <csignal>
#include <unistd.h>

// confirm auto block and delivering same signal only once after unblock

void sig_handle(int);

int main()
{
	if (SIG_ERR == signal(SIGINT, sig_handle))
	{
		return -1;
	}

	while(1);
	return 0;
}

void sig_handle(int sig)
{
	printf("\nrecv sig %d\n", sig);
	// if we press ctrl+c multiple times (under UBUNTU 20.04, Linux 5.4.0)
	// the first signal will be executed immediately and sleep 5 seconds
	// and following signals produced will be delivered after sleep
	// no matter how many times ctrl+c is pressed during sleep, the program receives only one extra same singal.
	sleep(5);
	printf("finish sleep\n");
}


