
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

typedef void (*Callback)(void);         // 定义一个无参无返回值的函数指针类型
typedef int (*Callback2)(int,int);      // 定义一个接收两个参数int返回值的函数指针类型


void callLuaFunc(Callback);
void callLuaFunc2(Callback2);

Callback callbackFunc = NULL;
Callback2 callbackFunc2 = NULL;

// 函数指针变量例子
void MyFunc(int);      // 普通函数
void (*MyFuncP)(int);  // 函数指针变量MyFuncP，注意有typedef与没有的区别

void MyFunc(int x) {
    printf("x = %d\n", x);
}

int main(void) {
   
    MyFuncP = &MyFunc;  // 把普通函数的地址赋给MyFuncP函数指针变量
    MyFuncP(12);        // 通过函数指针调用普通函数

    lua_State* L = luaL_newstate();   
    luaL_openlibs(L);
    luaL_dofile(L, "luascripts/testcallback.lua");
    lua_close(L);
    
    return 0;
}

void callLuaFunc(Callback cb) {
    callbackFunc = cb;
    callbackFunc();
}

void callLuaFunc2(Callback2 cb2) {
    callbackFunc2 = cb2;
    int count = callbackFunc2(12, 46);

    printf("count: %d\n", count);
}
