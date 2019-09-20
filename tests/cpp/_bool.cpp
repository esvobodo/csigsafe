#include<csignal>
#include<string>
#include<iostream>
#include<unistd.h>
#include<tgmath.h>

void handler(int sig_num);

int main(void)
{
    signal(SIGUSR1, handler);
}

void handler(int sig_num)
{
    bool flag;
    flag = sig_num > 11;

    if(flag){
        printf("bigger\n");
    } else{
        printf("smaller\n");
    }
    
    int result = flag ? SIGUSR1 : SIGUSR2;
    kill(123, result);
}
