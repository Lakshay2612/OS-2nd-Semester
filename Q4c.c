#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
int main()
{
 int a;
 a=fork();
 if(a<0)
    {
    printf("Fork failed");
    }
else if(a==0)
    {
    printf("\nExecuting child");
    execlp("/home/documents/C++/Q4/parta.c","ls",NULL);
    }
else
    {
    wait(NULL);
    printf("\nExecuting parent : %d",getpid());
    }
    return 0;
}
