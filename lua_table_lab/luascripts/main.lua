-- table lab

-- 迭代table,能够迭代所有项,包括索引不是整数的项
local function print_table(t)
    for k, v in pairs(t) do
        print('key: ' .. k .. ' value: ' .. v)
    end
    print('-------------------------------------------')
end

-- 迭代table,只能迭代出索引index为整数的项
local function print_table_index(t)
    for i, v in ipairs(t) do
        print('index: ' .. i .. ' value: ' .. v)
    end
    print('-------------------------------------------')
end

-- 遍历table，纯数组类型的table
local function print_table_array(t)
    for i = 1, #t do
        print('value:' .. t[i])
    end
    print('-------------------------------------------')
end

local black = { -- 黑色
    r = 0,
    g = 0,
    b = 0
}

local white = { -- 白色
    r = 1,
    g = 1,
    b = 1
}

local array = {'a', 'b', 'c', 'd', 'e', 'f'}

print_table(black)
print_table(white)

print_table_array(array)

print(next(black))
print(next(array, 4))

-- 定义成全局的，提供给C++访问
lua_print_table = print_table
lua_print_table_index = print_table_index

function lua_add(x, y)
    print(x, y)
    return (x + y)
end
