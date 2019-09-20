#include <csignal>
#include <iostream>
#include <unistd.h>

/*
*   OK: no problem discovered
*/

void fnc(void);
void handler(int sig_num);

int main(void)
{
    try {
        fnc();
    } catch (int e) {
        signal(SIGUSR1, handler);
    }

    kill(getpid(), SIGUSR1);
}

void handler(int sig_num)
{
    printf("handler\n");
}

void fnc()
{
    throw 42;
}