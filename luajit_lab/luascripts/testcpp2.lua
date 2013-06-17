local log = function(...)
    print('[LuaJIT] -- ' .. string.format(...))
end

log('testcpp2 start----')

local ffi = require 'ffi'
local lib = ffi.load('../libs/libstudent.dylib')

ffi.cdef[[
    typedef struct Student Student;
]]

ffi.cdef(io.open('../luascripts/ffi/bindings.ffi', 'r'):read('*a'))

local Mt_Student = {} -- metatype
Mt_Student.__index = Mt_Student
Mt_Student.setName = lib.Student_setName
Mt_Student.setAge = lib.Student_setAge
Mt_Student.toString = lib.Student_toString

ffi.metatype('Student', Mt_Student)

local stu = ffi.gc(lib.Student_new(), lib.Student__gc)
stu:setName("Tom")
stu:setAge(23)
stu:toString()

log('testcpp2 end----')
