#include <csignal>
#include <iostream>
#include <unistd.h>

/*
*   NO PROBLEM
*/

void handler(int sig_num);
template<typename T>
T max(T a, T b);

int bigger;
int numbers[] = {5, 9, 3, 7, 2, 45, 32};

int main(void)
{
    signal(SIGUSR1, handler);
}

void handler(int sig_num)
{
    bigger = max(sig_num, 11);
    std::cout << "handler: " << sig_num << std::endl;
    printf("s");
}

template<typename T>
T max(T a, T b)
{
    std::cout << a << " vs " << b << std::endl;
    return a >= b ? a : b;
}