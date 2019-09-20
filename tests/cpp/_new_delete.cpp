#include <csignal>

/*
*   OK: csigsafe found new and delete and reported them to not be known as async-signal-safe
*/

void handler(int sig_num);

int main(void)
{
    signal(SIGUSR1, handler);
}

void handler(int sig_num)
{
    int *i = new int(12);
    delete i;
}