#include<csignal>
#include<unistd.h>
#include<errno.h>

/*
*   BUG/FEATURE: csigsafe reports only one function changing errno inside handler at a time,
        when the one is repaired, only then another appears, but eventually it catches everything
*   (NOT FIXED)
*/

void handler(int sig_num);

int main(void)
{
    signal(SIGUSR1, handler);
}

void handler(int sig_num)
{
    kill(123, SIGUSR1);
    kill(123, SIGUSR2);
    pause();
}