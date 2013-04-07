-- lab1
require('ui.view')
ui.view.new_layer(1)
ui.view.new_label(2)

-- lab2
local view = require('ui.view2')
view.new_layer(3)
view.new_label(4)

-- lab3
local create_module = function(name)
    module(name)
    function add(x, y) return x + y end
    function div(x, y) return x / y end
end
create_module('test')
print(test.add(12, 43))
print(test.div(12, 43))

-- lab4
local moduletable = {}
moduletable['test'] = function() print('moduletable.test') end
package.loaded['mt'] = moduletable
package.loaded.mt.test()

print('------------------------------------------')
table.foreach(package.loaded, print)
