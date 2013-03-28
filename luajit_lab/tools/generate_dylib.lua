local files = ''
local dfiles = ''

for _, v in ipairs(arg) do
    files = files  .. ' src/' .. tostring(v) .. '.cpp'
    dfiles = dfiles .. ' ' .. tostring(v) .. '.o'
end

local str1 = 'g++ -I include -c' .. files
print(str1)

if io.open(path or '','r') == nil then
    os.execute('mkdir libs')
    print('mkdir libs')
end

local str2 = 'g++ -dynamiclib -o libs/libstudent.dylib' .. dfiles
print(str2)

local str3 = 'rm' .. dfiles
print(str3)

os.execute(str1)
os.execute(str2)
os.execute(str3)
print 'done'
