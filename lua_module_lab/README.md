Lua的module测试
---

```bash
$ lua main.lua
```

```bash
new_layer(1)
new_label(2)
new_layer(3)
new_label(4)
55
0.27906976744186
moduletable.test
------------------------------------------
string	table: 0x7f9ab3c07a10
debug	table: 0x7f9ab3c08c00
package	table: 0x7f9ab3c05730
_G	table: 0x7f9ab3c040c0
mt	table: 0x7f9ab3c0a370
ui.view	table: 0x7f9ab3c0b1a0
io	table: 0x7f9ab3c06b80
os	table: 0x7f9ab3c07390
table	table: 0x7f9ab3c05ec0
math	table: 0x7f9ab3c08240
ui.view2	table: 0x7f9ab3c098b0
coroutine	table: 0x7f9ab3c05330
test	table: 0x7f9ab3c0a330
```

参考: [http://lua-users.org/wiki/LuaModuleFunctionCritiqued][1]
      [http://lua-users.org/wiki/ModuleDefinition][2]

[1]: http://lua-users.org/wiki/LuaModuleFunctionCritiqued "http://lua-users.org/wiki/LuaModuleFunctionCritiqued"
[2]: http://lua-users.org/wiki/ModuleDefinition "http://lua-users.org/wiki/ModuleDefinition"
