#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
int main()
{
    printf("Invoking 'rtnice' system call");

    long int ret_status = syscall(323); // 323 is the syscall number

    if(ret_status == 0)
         printf("System call 'rtnice' executed correctly. Use dmesg to check processInfo\n");

    else
         printf("System call 'rtnice' did not execute as expected\n");

     return 0;
}
