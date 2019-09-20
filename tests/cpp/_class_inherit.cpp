#include<csignal>
#include<iostream>

/*
*   BUG/FEATURE: csigsafe reports unsafe functions only inside handler 
        that is activated as the last in main in signal(),
        when the one is fixed, the previous one is reported
    NOTE: signal() accepts only static handlers
*/

class base
{
 public:
    base()
        : var(0)
    {}
    static void handler(int sig_num)
    {
        printf("base handler\n");
    }
 private:
    int var;
};

class derivate : public base
{
 public:
    derivate()
        : base(), add_var(1)
    {}
    static void handler(int sig_num)
    {
        printf("derivate handler\n");
    }
 private:
    int add_var; 
};

class derivate_second : public base
{
 public:
    derivate_second()
        : base(), add_var(1)
    {}
    static void handler(int sig_num)
    {
        printf("derivate_second handler\n");
    }
 private:
    int add_var; 
};

int main(void)
{
    signal(SIGUSR2, base::handler);
    signal(SIGUSR1, derivate::handler);
}