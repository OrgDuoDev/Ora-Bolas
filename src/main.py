import matplotlib.pyplot as plt
from calc import Cport
from plot import XYroboBola, trajetoriaX, trajetoriaY, velocidadeX, velocidadeY, distancia

def main():
    # Chamar a função Cport
    posX = float(input())
    posY = float(input())
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
    distancia(tempo_list, dist_list)
    
    
    for i in range(result.size):
        print(f"Bola:  {xBolaVelo_list[i]} {yBolaVelo_list[i]}  Robo: {xRoboVelo_list[i]}  {yRoboVelo_list[i]}   Tempo: {tempo_list[i]}")
    
    
    plt.show()
    
if __name__ == "__main__":
    main()
