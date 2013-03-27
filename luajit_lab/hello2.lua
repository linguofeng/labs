local log = function(...)
    print('[LuaJIT] -- ' .. string.format(...))
end

local ffi = require 'ffi'
local C = ffi.C

ffi.cdef[[
    typedef struct Student Student;
]]

ffi.cdef(io.open('bindings.ffi', 'r'):read('*a'))

local Mt_Student = {} -- metatype
Mt_Student.__index = Mt_Student
Mt_Student.setName = C.Student_setName
Mt_Student.setAge = C.Student_setAge
Mt_Student.toString = C.Student_toString

ffi.metatype('Student', Mt_Student)

local stu = ffi.gc(C.Student_new(), C.Student__gc)
stu:setName("Tom")
stu:setAge(23)
stu:toString()

--student = ffi.cast('Student*', student)
--student:setAge(23)
