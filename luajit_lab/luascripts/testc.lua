local log = function(...)
    print('[LuaJIT] -- ' .. string.format(...))
end

log('start----')

local ffi = require 'ffi'
local C = ffi.C

-- 打印ffi这个表的详细结构
--table.foreach(ffi, print)

--ffi.cdef[[
    --int printf(const char*, ...);
    --int add(int, int);
    --typedef struct { char* name; int age; } Student;
    --void call(Student*);
--]]

-- 生成header.ffi
-- $ luajit tools/generate_ffi header
ffi.cdef(io.open('luascripts/ffi/header.ffi', 'r'):read('*a'))

-- 创建Student数据结构
local stu = ffi.new('Student', {ffi.cast('char*', 'Tom'), 23})

-- 调用自定义的C函数
C.call(stu)

--print(io.open('luascripts/ffi/header.ffi', 'r'):read('*a'))

--local a = ffi.new('int')
--local c = ffi.new('char const*')
--a = 123
--c = 'abcdef'
--log(a)
--log(c)

-- 调用C中的printf函数
--C.printf('Hello %s!\n', 'World')

-- 调用C函数
log('12 + 34 = ' .. C.add(12, 34))

-- 类型转换，把lua中的类型转换成C的类型
--C.printf('%d', ffi.cast('int', false))

log('end----')
