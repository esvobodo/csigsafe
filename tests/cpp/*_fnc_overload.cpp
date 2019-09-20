#include <csignal>
#include <iostream>

/*
*   PROBLEM: csigsafe distinguishes functions on base of their name, 
        the right function doesn't have to be checked 
        (here function accepting char is scaned in place of the one working with int)
*/

void handler(int sig_num);
void overloading_function(int num);
void overloading_function(char c);

int main(void)
{
    signal(SIGUSR1, handler);
}

void handler(int sig_num)
{
    overloading_function(45);
}

void overloading_function(char c)
{
    printf("char\n");
}

void overloading_function(int num)
{
    printf("int\n");
}