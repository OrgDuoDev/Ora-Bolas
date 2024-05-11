import ctypes

# Definir a estrutura Data em Python usando ctypes
class Data(ctypes.Structure):
    _fields_ = [
        ("size", ctypes.c_int),
        ("xRoboPos", ctypes.POINTER(ctypes.c_double)),
        ("yRoboPos", ctypes.POINTER(ctypes.c_double)),
        ("xBolaPos", ctypes.POINTER(ctypes.c_double)),
        ("yBolaPos", ctypes.POINTER(ctypes.c_double)),
        ("tempo", ctypes.POINTER(ctypes.c_double))
    ]

# Carregar a biblioteca compartilhada
calculo_lib = ctypes.CDLL('./calculo.so')

# Definir a assinatura da função
calculo_lib.calculo.restype = ctypes.POINTER(Data)
calculo_lib.calculo.argtypes = [ctypes.c_double, ctypes.c_double, ctypes.c_double]

# Chamar a função
result_ptr = calculo_lib.calculo(4, -2, 0.056)

# Obter os dados
result = result_ptr.contents

# Imprimir os resultados
for i in range(result.size):
    print(f"BOLA: {result.xBolaPos[i]} {result.yBolaPos[i]} Robo: {result.xRoboPos[i]} {result.yRoboPos[i]} Tempo: {result.tempo[i]}")

# Liberar a memória alocada pela função C++
calculo_lib.free_data(result_ptr)
