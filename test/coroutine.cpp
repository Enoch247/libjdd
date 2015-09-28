#include <iostream>
#include "../coroutine.h"

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
        yield;
        cout << "B" << endl;
        yield;
        cout << "C" << endl;
        yield;
    }
    coroutine_end;
}

void bar()
{
    coroutine_beg;
    while(1)
    {
        cout << "X" << endl;
        yield;
        cout << "Y" << endl;
        yield;
        cout << "Z" << endl;
        yield;
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

