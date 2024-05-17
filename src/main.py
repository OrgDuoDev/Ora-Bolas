import tkinter as tk
import matplotlib.pyplot as plt
from calc import Cport
from plot import XYroboBola, trajetoriaX, trajetoriaY, velocidadeX, velocidadeY, aceleracaoX, aceleracaoY, distancia

def main():
    # Chamar a função Cport
    posX = float(input("Valor em X:"))
    posY = float(input("Valor em Y:"))
    result = Cport(posX, posY)
    
    # Armazenar os resultados em listas
    xBolaPos_list = [result.xBolaPos[i] for i in range(result.size)]
    yBolaPos_list = [result.yBolaPos[i] for i in range(result.size)]
    xRoboPos_list = [result.xRoboPos[i] for i in range(result.size)]
    yRoboPos_list = [result.yRoboPos[i] for i in range(result.size)]

    xBolaVelo_list = [result.xBolaVelo[i] for i in range(result.size)]
    yBolaVelo_list = [result.yBolaVelo[i] for i in range(result.size)]
    xRoboVelo_list = [result.xRoboVelo[i] for i in range(result.size)]
    yRoboVelo_list = [result.yRoboVelo[i] for i in range(result.size)]

    xBolaAcele_list = [result.xBolaAcele[i] for i in range(result.size)]
    yBolaAcele_list = [result.yBolaAcele[i] for i in range(result.size)]
    xRoboAcele_list = [result.xRoboAcele[i] for i in range(result.size)]
    yRoboAcele_list = [result.yRoboAcele[i] for i in range(result.size)]


    tempo_list = [result.tempo[i] for i in range(result.size)]
    dist_list = [result.dist[i] for i in range(result.size)]
    # Estilo do Gráfico
    plt.style.use('Solarize_Light2')

    # Criação dos gŕaficos:
    XYroboBola(xBolaPos_list, yBolaPos_list, xRoboPos_list, yRoboPos_list)
    trajetoriaX(xBolaPos_list, xRoboPos_list, tempo_list)
    trajetoriaY(yBolaPos_list, yRoboPos_list, tempo_list)
    velocidadeX(xBolaVelo_list,  xRoboVelo_list, tempo_list)
    velocidadeY(yBolaVelo_list,  yRoboVelo_list, tempo_list)
    aceleracaoX(xBolaAcele_list,  xRoboAcele_list, tempo_list)
    aceleracaoY(yBolaAcele_list,  yRoboAcele_list, tempo_list)
    distancia(tempo_list, dist_list)

    plt.show()
    
if __name__ == "__main__":
    main()
