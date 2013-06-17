local files = ''
local ofiles = ''

for _, v in ipairs(arg) do
    files = files  .. ' src/' .. tostring(v) .. '.cpp'
    ofiles = ofiles .. ' ' .. tostring(v) .. '.o'
end

if io.open('libs','r') == nil then
    local execute = 'mkdir libs'
    os.execute(execute)
    print(execute)
end

local str1 = 'g++ -I include -c' .. files
print(str1)

local str2 = 'g++ -dynamiclib -o libs/libstudent.dylib' .. ofiles
print(str2)

local str3 = 'rm' .. ofiles
print(str3)

os.execute(str1)
os.execute(str2)
os.execute(str3)
print 'done'
