#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <string>

using namespace std;

int main()
{
    int n = 3;
    int pid = 0;

    for(int i = 0; i < n; i++)
    {
        if(pid == 0)
        {
            pid = fork();
            wait(NULL);

            if(pid > 0)
            {
                pid = fork();
                wait(NULL);
                
                if(pid > 0)
                {
                    break;
                }
            }
        }
    }
    printf("[%d] Mi Padre tiene el pid %d\n",getpid(), getppid());
    exit(0);
}