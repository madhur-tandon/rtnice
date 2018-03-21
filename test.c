#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

int main()
{
	
	//printf("System call sys_rt_nice returned %ld\n",amma);
	struct timeval start;
	//clock_t begin =clock();
	gettimeofday(&start,NULL);
	long int pid=fork();
	
	
	//unsigned long long int n
	printf("System call sys_rt_nice boo %ld\n",pid);
	
	if(pid!=0)
	{
		printf("System call sys_rt_nice returned %ld\n",pid);
		printf("System call sys_rt_nice not returned %ld\n",getpid());
		//syscall(323,pid,200);
	}

	
	if(pid==0)
	{
		struct timeval stop;
		//clock_t begin =clock();
		long prod=1;
		long i=1;
		for(i=1;i<1000000000;i++)
		{
			prod=prod*i;
			//if(i%1000000==0)	
				//syscall(324,getpid());		
		}
		gettimeofday(&stop,NULL);
		//clock_t end = clock();
		printf("Time %lu PID %ld \n",stop.tv_usec - start.tv_usec,getpid());
		
	}
	else
	{
		struct timeval stop;
		
		long prod=1;
		long i=1;
		for(i=1;i<1000000000;i++)
		{
			prod=prod*i;
			//printf("%ld\n",getpid());
			//syscall(324,getpid());
			
			
		}
		gettimeofday(&stop,NULL);
		
		//clock_t end = clock();	
		printf("Time %lu PID %ld \n",stop.tv_usec - start.tv_usec,getpid());
		wait(pid);
	}
	return 0;
}
