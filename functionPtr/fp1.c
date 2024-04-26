#include <stdio.h>

void fun(int a)
{
    printf("Value of a is %d\n", a);
}

int main()
{
    // function pointer is a pointer to function fun()
    void (*fun_ptr)(int) = &fun;
    /*
        the above line is equivalent of following two
        void (*fun_ptr)(int);
        fun_ptr = &fun;
    */

    // invoking fun using fun_ptr
    (*fun_ptr)(10);

    return 0;
}