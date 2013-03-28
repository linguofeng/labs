local log = function(...)
    print('[LuaJIT] -- ' .. string.format(...))
end

log('testcpp start----')

local ffi = require 'ffi'
local C = ffi.C

ffi.cdef[[
    typedef struct Student Student;
    Student* Student_new(void);
    void Student_toString(Student*);
    void Student_setName(Student*, const char*);
    void Student_setAge(Student*, int);
    void Student__gc(Student*);
]]

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

log('testcpp end----')
