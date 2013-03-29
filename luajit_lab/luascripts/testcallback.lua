
local log = function(...)
    print('[LuaJIT] -- ' .. string.format(...))
end

local ffi = require 'ffi'

ffi.cdef[[
    typedef void (*Callback)(void);
    typedef int (*Callback2)(int,int);

    void callLuaFunc(Callback);
    void callLuaFunc2(Callback2);
]]

local function lfunc()
    log('lfunc')
end

local function lfunc2()
    log('lfunc2')
end

local cb = ffi.cast('Callback', lfunc); -- 把lua函数转换成c函数指针
ffi.C.callLuaFunc(cb)                   -- 把转换后的c函数指针传递给c函数

cb:set(lfunc2);         -- 修改回调函数
ffi.C.callLuaFunc(cb)

cb:free()

local cb2 = ffi.cast('Callback2', function(x, y)
    log(x .. ' + ' .. y .. ' = ' .. x + y)
    return x + y
end)

ffi.C.callLuaFunc2(cb2)
cb2:free()
