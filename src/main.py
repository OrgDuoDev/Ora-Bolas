import matplotlib.pyplot as plt
from calc import Cport
from plot import XYroboBola, trajetoriaX, trajetoriaY

def main():
    # Chamar a função Cport
    posX = input("Posição em X: ")
    posY = input("Posição em Y: ")

    
    result = Cport(posX, posY)
    
    # Armazenar os resultados em listas
    xBolaPos_list = [result.xBolaPos[i] for i in range(result.size)]
    yBolaPos_list = [result.yBolaPos[i] for i in range(result.size)]
    xRoboPos_list = [result.xRoboPos[i] for i in range(result.size)]
    yRoboPos_list = [result.yRoboPos[i] for i in range(result.size)]
    tempo_list = [result.tempo[i] for i in range(result.size)]

    #Aplicar o estilo dark mode
    plt.style.use('Solarize_Light2')

    # Criação dos gŕaficos:
    XYroboBola(xBolaPos_list, yBolaPos_list, xRoboPos_list, yRoboPos_list)
    trajetoriaX(xBolaPos_list, xRoboPos_list, tempo_list)
    trajetoriaY(yBolaPos_list, yRoboPos_list, tempo_list)

    plt.show()

if __name__ == "__main__":
    main()
