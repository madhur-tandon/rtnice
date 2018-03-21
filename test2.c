#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

int main()
{
	long int pid=fork();

	if(pid!=0)
	{
		printf("System call sys_rt_nice returned %ld\n",pid);
		printf("System call sys_rt_nice not returned %ld\n",getpid());
		syscall(323,pid,200);
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
			long prod=1;
			long i=1;
			for(i=1;i<2000000000;i++)
			{
				prod=prod*i;
			}

			printf("Time %lu PID %ld \n",stop.tv_usec - start.tv_usec,getpid());
		}
		else
		{
			long prod=1;
			long i=1;
			for(i=1;i<2000000000;i++)
			{
				prod=prod*i;
			}
			printf("Time %lu PID %ld \n",stop.tv_usec - start.tv_usec,getpid());
			wait(pid2);
		}
	}
	else
	{
			long prod=1;
			long i=1;
			for(i=1;i<2000000000;i++)
			{
				prod=prod*i;
			}
			printf("Time %lu PID %ld \n",stop.tv_usec - start.tv_usec,getpid());
			wait(pid);
	}
	return 0;
}
