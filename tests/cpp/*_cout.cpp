#include<iostream>
#include<csignal>

/*
*   BUG: csigsafe doesn't report operator << as dangerous function 
        when operator << has constant string as a parameter (csigsafe reports it only when it has variable as parameter)
*   PROBLEM: in css_function::process_gimple_call functions are scanned on base of DECL_INITIAL(function)
        library function operator << is evaluated as a dependency (it is presumed that we will have its definition 
        and than it will be scanned)
    FIX: add DECL_INITIAL  (function) && !DECL_EXTERNAL(function)
                                     ----------------------------
        DECL_EXTERNAL tests function wheter it is undefined or not
*/

void handler(int sig_num)
{
    int var = 10;
    std::cout << "Handler: " << std::endl;
}

int main (void)
{
    signal(SIGINT, handler);

    return 0;
}