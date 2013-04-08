#include <iostream>

extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

void call_lua_function(lua_State*, const char*, int args = 0, int returns = 0);

int main(void)
{
    lua_State* L = luaL_newstate();   
    luaL_openlibs(L);

    // 加载并执行lua脚本
    luaL_dofile(L, "luascripts/main.lua");

    // 调用lua的函数,接收两个int值的参数
    lua_pushinteger(L, 12);
    lua_pushinteger(L, 88);
    call_lua_function(L, "lua_add", 2, 1);

    // 调用lua的函数，打印由c api创建的table
    lua_newtable(L);            // [..., table]
    lua_pushstring(L, "k1");    // [..., table, k1]
    lua_pushstring(L, "v1");    // [..., table, k1, v1]
    lua_settable(L, -3);        // [..., table] 等于于 table[k1] = v1 的操作
    lua_pushstring(L, "k2");    // [..., table, k2]
    lua_pushstring(L, "v2");    // [..., table, k2, v2]
    lua_settable(L, -3);        // [..., table] 等于于 table[k2] = v2 的操作
    lua_pushstring(L, "k3");    // [..., table, k3]
    lua_pushstring(L, "v3");    // [..., table, k3, v3]
    lua_settable(L, -3);        // [..., table] 等于于 table[k3] = v3 的操作
    //lua_setglobal(L, "map"); // 把table弹出并在全局变量表中增加一个名为map的变量,该变量可在脚本中直接使用
    call_lua_function(L, "lua_print_table", 1);

    lua_close(L);
    
    return 0;
}

void call_lua_function(lua_State *L, const char* func, int args, int returns)
{
    // 获取全局元素,实际是把该元素移至栈顶,等同于lua_getfield(L, LUA_GLOBALSINDEX, s)
    // LUA_GLOBALSINDEX 伪索引,此处特指全局变量的环境,表示从全局变量中获取对应的值
    lua_getglobal(L, func); // lua_getfield(L, LUA_GLOBALSINDEX, func)
    // 判断栈顶元素是否是个函数类型
    if (!lua_isfunction(L, -1))
        luaL_error(L, "%s() 不是一个Lua函数", func);

    if (args > 0)
    {
        // 移动栈顶的元素，即lua_function至该函数接收参数个数之前
        // [..., tom, lua_function]
        lua_insert(L, -1 - args); // 等同于(lua_gettop(L) - args)
        // [..., lua_function, tom]
    }

    // 调用函数
    if (lua_pcall(L, args, returns, 0)) // 如果是0则成功,否则调用失败,最后一个参数0表示没有处理异常的函数
        luaL_error(L, "调用 %s() 失败", func);

    if (returns <= 0)
        return;

    // 判断返回值是不是数字类型
    if (!lua_isnumber(L, -1))
        luaL_error(L, "返回值不是数字类型!!");

    int result = lua_tonumber(L, -1);
    std::cout << "result: " << result << "\n";
    lua_pop(L, 1); // 从栈中弹出1个结果元素
}
