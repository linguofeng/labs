#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#include "header.h"

int main(void) {
    
    lua_State* L = luaL_newstate();   
    luaL_openlibs(L);
    /*luaL_dostring(L, "return 'Hello from Lua !'");  // 执行Lua语句的返回值*/
    luaL_dofile(L, "luascripts/testc.lua");
    /*const char * str = lua_tostring(L, -1);         // 获取Lua语句的返回值*/
    /*printf(str);*/
    lua_close(L);

    /*Student s = {"Tom", 21};*/
    /*call(&s);*/
    return 0;
}

int add(int x, int y) {
    return x + y;
}

void call(Student* stu)
{
    printf("name: %s, age: %d\n", stu->name, stu->age);
    /*printf("age: %d", stu->age);*/
}

void sayHi(void) {
    printf("Hello World!!!!!!\n");
}
