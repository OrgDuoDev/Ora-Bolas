import ctypes

class TD(ctypes.Structure):
    _fields_ = [("xRobo", ctypes.c_double),
                ("yRobo", ctypes.c_double)]

lib = ctypes.CDLL("../calc/calc.so")

lib.calculo.restype = TD
lib.calculo.argtypes = [ctypes.c_double, ctypes.c_double, ctypes.c_double, ctypes.c_double, ctypes.c_double]
result = lib.calculo(5, 5, 5, 4, 0.056)

print(result.xRobo, result.yRobo)