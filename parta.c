#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
 int a;
 a=fork();
 if(a<0)
    {
    printf("Fork failed");
    }

else
    {
    printf("Parent and child Executed : %d",getpid());
    }
    return 0;
}
