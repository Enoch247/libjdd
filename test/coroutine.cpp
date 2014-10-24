#include <iostream>
#include "coroutine.h"

using namespace std;

void foo()
{
    //anything put here will be done every time foo() is called

    coroutine_beg;

    //anything put here will be done once per program execution

    while(1)
    {
        //anything put here will be done once per loop

        cout << "A" << endl;
        yeild;
        cout << "B" << endl;
        yeild;
        cout << "C" << endl;
        yeild;
    }
    coroutine_end;
}

void bar()
{
    coroutine_beg;
    while(1)
    {
        cout << "X" << endl;
        yeild;
        cout << "Y" << endl;
        yeild;
        cout << "Z" << endl;
        yeild;
    }
    coroutine_end;
}

int main ()
{
    for(int i = 0; i < 6; i++)
    {
        foo();
        bar();
    }
}

