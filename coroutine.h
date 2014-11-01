#ifndef COROUTINE_H
#define COROUTINE_H

//NOTE: you cannot put a yeild statement inside a switch statement, but you can
//place a coroutine inside an switch statement and yeilds inside of that!

//see http://www.chiark.greenend.org.uk/~sgtatham/coroutines.html for more info
#define coroutine_beg { static int _state = __LINE__; switch(_state){ case __LINE__ :;
#define coroutine_end yeild;}}
#define yeild do{_state = __LINE__; return; case __LINE__:;} while(0)
#define yeildval(rtn) do{_state = __LINE__; return rtn; case __LINE__:;} while(0)

#endif
