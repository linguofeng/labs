local log = function(...)
    print('[LuaJIT] -- ' .. string.format(...))
end

local ffi = require 'ffi'
local C = ffi.C

--table.foreach(ffi, print)

--ffi.cdef[[
    --int printf(const char*, ...);
    --int add(int, int);
    --typedef struct { char* name; int age; } Student;
    --void call(Student*);
--]]

ffi.cdef(io.open('ffi_header.h', 'r'):read('*a'))

local stu = ffi.new('Student', {ffi.cast('char*', 'abc'), 23})
C.call(stu)

--print(io.open('header.h', 'r'):read('*a'))

log('end----')
--local a = ffi.new('int')
--local c = ffi.new('char const*')
--a = 123
--c = 'abcdef'
--log(a)
--log(c)

--C.printf('Hello %s!\n', 'World')
--log(C.add(12, 34))

--C.printf('%d', ffi.cast('int', false))

--local stu = ffi.new('Student', 23)
--C.call(Student)
--log(stu.name)
