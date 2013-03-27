
-- temporary C interface header to LuaJIT FFI cdefs command script

local stub = io.open("stub2.c", "w")
stub:write([[#include "bindings.h"]])
stub:close()

local str2 = "gcc -I include -E -P stub2.c > bindings.ffi"
print(str2)

os.execute(str2)
os.execute"rm stub2.c"
print 'done'
