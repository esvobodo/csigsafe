#include <csignal>
#include <unistd.h>
#include <iostream>

/*
*   BUG: csigsafe reports handler in namespace second even though signal() uses 
        handler without namespace
*/

void handler(int sig_num);

namespace first {
    int value = 10;
    void handler(int sig_num)
    {
        printf("first handler\n");
    }
}

namespace second {
    int value = 20;
    void handler(int sig_num)
    {
        printf("second handler\n");
    }
}

int value = 30;

int main(void)
{
    signal(SIGUSR1, handler);
    signal(SIGUSR2, second::handler);
    signal(SIGABRT, first::handler);
}

void handler(int sig_num)
{
    printf("handler\n");
}