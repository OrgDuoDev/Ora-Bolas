import matplotlib.pyplot as plt

def XYroboBola(xBolaPos, yBolaPos, xRoboPos, yRoboPos):
    # Criar o gráfico
    plt.figure(num="X e Y da Bola e Robo", figsize=(9, 6))
    plt.plot(xBolaPos, yBolaPos, label='Bola', color="red")
    plt.plot(xRoboPos, yRoboPos, label='Robo')
    plt.xlabel('x')
    plt.ylabel('y')
    plt.title('Posição da Bola e do Robô')
    plt.legend()
    plt.grid(True)

    # Definir os limites do eixo x e do eixo y
    plt.xlim(0, 9)
    plt.ylim(0, 6)

def distancia(tempo, dist):
    # Criar o gráfico
    plt.figure(num="Distância em função do tempo")
    plt.plot(tempo, dist, label='Distância',  color="red")
    plt.xlabel('tempo')
    plt.ylabel('Distância')
    plt.title('Distância entre os objetos em função do tempo')
    plt.legend()
    plt.grid(True)

    

def trajetoriaX(xBolaPos, xRoboPos, tempo):
    # Criar o gráfico
    plt.figure(num="Posição X dos objetos em função do Tempo")
    plt.plot(tempo, xBolaPos, label="Bola", color="red")
    plt.plot(tempo, xRoboPos, label="Robo")
    plt.xlabel('Tempo')
    plt.ylabel('x')
    plt.title('X da Bola e do Robô por Tempo')
    plt.legend()
    plt.grid(True)



def trajetoriaY(yBolaPos, yRoboPos, tempo):
    # Criar o gráfico
    plt.figure(num="Posição Y dos objetos em função do tempo")
    plt.plot(tempo, yBolaPos, label="Bola",  color="red")
    plt.plot(tempo, yRoboPos, label="Robo")
    plt.xlabel('Tempo')
    plt.ylabel('y')
    plt.title('Y da Bola e do Robô por Tempo')
    plt.legend()
    plt.grid(True)


def velocidadeX(xBolaVelo, xRoboVelo, tempo):
    # Criar o gráfico
    plt.figure(num="Velocidade em X dos objetos em função do tempo ")
    plt.plot(tempo, xBolaVelo, label='Bola',  color="red")
    plt.plot(tempo, xRoboVelo, label='Robo')
    plt.xlabel('tempo')
    plt.ylabel('x')
    plt.title('Velocidade da Bola e do Robô')
    plt.legend()
    plt.grid(True)
    
def velocidadeY(yBolaVelo, yRoboVelo, tempo):
    # Criar o gráfico
    plt.figure(num="Velocidade em Y dos objetos em função do tempo")
    plt.plot(tempo, yBolaVelo, label='Bola',  color="red")
    plt.plot(tempo, yRoboVelo, label='Robo')
    plt.xlabel('tempo')
    plt.ylabel('y')
    plt.title('Velocidade da Bola e do Robô')
    plt.legend()
    plt.grid(True)
    plt.ylim(0, 0.4)

def aceleracaoX(xBolaAcele, xRoboAcele, tempo):
    # Criar o gráfico
    plt.figure(num="Aceleração em X dos objetos em função do tempo ")
    plt.plot(tempo, xBolaAcele, label='Bola',  color="red")
    plt.plot(tempo, xRoboAcele, label='Robo')
    plt.xlabel('tempo')
    plt.ylabel('x')
    plt.title('Aceleração da Bola e do Robô')
    plt.legend()
    plt.grid(True)

def aceleracaoY(yBolaAcele, yRoboAcele, tempo):
    # Criar o gráfico
    plt.figure(num="Aceleração em Y dos objetos em função do tempo")
    plt.plot(tempo, yBolaAcele, label='Bola',  color="red")
    plt.plot(tempo, yRoboAcele, label='Robo')
    plt.xlabel('tempo')
    plt.ylabel('y')
    plt.title('Aceleração da Bola e do Robô')
    plt.legend()
    plt.grid(True)

