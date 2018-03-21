#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

unsigned long long nCr(unsigned long long n, unsigned long long r)
{
	if(n>=r)
	{
		if(r==0 || r==n)
		{
			return 1;
		}
		else
		{
			return nCr(n-1,r-1) + nCr(n-1,r);
		}
	}
	else
	{
		return 0;
	}
}

int main()
{
	long int pid=fork();

	if(pid!=0)
	{
		syscall(323,pid,300);
	}

	if(pid==0)
	{
		int pid2=fork();
		if(pid2 != 0)
		{
			syscall(323,pid2,200);
		}
		if(pid2==0)
		{
			unsigned long long ans = nCr(30,15);
			printf("Finished calculating 30C15\n");
			printf("Process with PID %ld finished\n",getpid());
		}
		else
		{
			unsigned long long ans = nCr(30,15);
			printf("Finished calculating 30C15\n");
			printf("Process with PID %ld finished\n",getpid());
			wait(pid2);
		}
	}
	else
	{
			unsigned long long ans = nCr(30,15);
			printf("Finished calculating 30C15\n");
			printf("Process with PID %ld finished\n",getpid());
			wait(pid);
	}
	return 0;
}
