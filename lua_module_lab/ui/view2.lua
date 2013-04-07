local print = print

module(...)     -- 由于没有使用 package.seeall 设置_G全局表，所以print是没法使用的，但可以在上面使用的local print

function new_layer(tag)
    print('new_layer(' .. tag .. ')')
end

function new_label(tag)
    print('new_label(' .. tag .. ')')
end
