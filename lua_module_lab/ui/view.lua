module(..., package.seeall)     -- package.seeall 为当前模块设置一个_G全局元表，能够访问全局函数或变量
                                -- ... 代表当前文件名

function new_layer(tag)
    print('new_layer(' .. tag .. ')')
end

function new_label(tag)
    print('new_label(' .. tag .. ')')
end
