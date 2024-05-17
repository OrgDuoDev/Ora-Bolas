import ctypes

def Cport(posX, posY):
    class Data(ctypes.Structure):
        _fields_ = [
            ("size", ctypes.c_int),
            
            ("xRoboPos", ctypes.POINTER(ctypes.c_double)),
            ("yRoboPos", ctypes.POINTER(ctypes.c_double)),
            
            ("xRoboVelo", ctypes.POINTER(ctypes.c_double)),
            ("yRoboVelo", ctypes.POINTER(ctypes.c_double)),

            ("xRoboAcele", ctypes.POINTER(ctypes.c_double)),
            ("yRoboAcele", ctypes.POINTER(ctypes.c_double)),
            
            ("xBolaPos", ctypes.POINTER(ctypes.c_double)),
            ("yBolaPos", ctypes.POINTER(ctypes.c_double)),
            
            ("xBolaVelo", ctypes.POINTER(ctypes.c_double)),
            ("yBolaVelo", ctypes.POINTER(ctypes.c_double)),

            ("xBolaAcele", ctypes.POINTER(ctypes.c_double)),
            ("yBolaAcele", ctypes.POINTER(ctypes.c_double)),
            
            ("dist", ctypes.POINTER(ctypes.c_double)),
            ("tempo", ctypes.POINTER(ctypes.c_double)),
        ]

    calculo_lib = ctypes.CDLL('./calculo.so')
    calculo_lib.calculo.restype = ctypes.POINTER(Data)
    calculo_lib.calculo.argtypes = [ctypes.c_double, ctypes.c_double, ctypes.c_double]

    result_ptr = calculo_lib.calculo(posX, posY, 0.056)
    result = result_ptr.contents

    return result

Cport(5,5)