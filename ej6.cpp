#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <string>

using namespace std;

int main()
{   
    int pid;
    int num = 5;
    string color = "CAVERNICOLA";

    for(int i = 0; i < num ; i++)
    {
        pid = fork();
        
        if (pid == 0)
        {
            if(i % 2==0)
            {
                color = "Negro";
            }
            else
            {
                color = "Rojo";
            }
        }
        if (pid > 0)
        {
            break;
        }
    }

    wait(NULL);
    printf("Soy %s\n", color.c_str());
    exit(0);
    return 0;
}