#include <iostream>
#include <csignal>
#include <unistd.h>

#include "*_more_files_lib.hh"

/*
*   PROBLEM: csigsafe doesn't scan handler (with fix for lib functions or without)
*/

int main(void)
{
    signal(SIGUSR1, handler);
    kill(getpid(), SIGUSR1);
}