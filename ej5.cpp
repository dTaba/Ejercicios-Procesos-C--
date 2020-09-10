#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main(int argc, char *argv[])
{
    int pid = fork();
    
    if(pid == 0)
    {
        cout << "Comando ejecutandose " << endl;
        execvp(argv[1],&argv[1]);
    }
    else
    {
        wait(NULL);
        cout << "Comando ejecutado " << endl;
    }
    
    
    return 0;
}