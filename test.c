#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

long long nCr(long long n, long long r)
{
  if(r!=0 && n!=r)
  {
    return nCr(n-1,r-1) + nCr(n-1,r);
  }
  else
  {
    return 1;
  }
}

int main()
{
    struct timeval start;
    gettimeofday(&start,NULL);
    long int pid=fork();
   
    printf("System call sys_rt_nice boo %ld\n",pid);
   
    if(pid!=0)
    {
        printf("System call sys_rt_nice returned %ld\n",pid);
        printf("System call sys_rt_nice not returned %ld\n",getpid());
        syscall(323,pid,200);
    }

    if(pid==0)
    {
        struct timeval stop;
        long prod=1;
        long i=1;
        for(i=1;i<10000000000;i++)
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
        for(i=1;i<100000000;i++)
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
