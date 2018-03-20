from ctypes import c_uint8, c_uint
var = 65535
i = c_uint(var)
i.value = i.value + 1
print i.value
