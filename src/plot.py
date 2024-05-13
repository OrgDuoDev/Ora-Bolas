import matplotlib.pyplot as plt

def XYroboBola(xBolaPos, yBolaPos, xRoboPos, yRoboPos ):
    # Criar o gráfico
    plt.figure(num="X e Y da Bola e Robo", figsize=(9, 6))
    plt.plot(xBolaPos, yBolaPos, label='Bola')
    plt.plot(xRoboPos, yRoboPos, label='Robo')
    plt.xlabel('x')
    plt.ylabel('y')
    plt.title('Posição da Bola e do Robô')
    plt.legend()
    plt.grid(True)

    # Definir os limites do eixo x e do eixo y
    plt.xlim(0, 9)
    plt.ylim(0, 6)

    

def trajetoriaX(xBolaPos, xRoboPos, tempo):
    # Criar o gráfico
    plt.figure(num="x dos objetos em função do Tempo", figsize=(9, 6))
    plt.plot(xBolaPos, tempo, label="Bola")
    plt.plot(xRoboPos, tempo, label="Robo")
    plt.xlabel('x')
    plt.ylabel('Tempo')
    plt.title('X da Bola e do Robô por Tempo')
    plt.legend()
    plt.grid(True)


def trajetoriaY(yBolaPos, yRoboPos, tempo):
    # Criar o gráfico
    plt.figure(num="y dos objetos em função do tempo", figsize=(9, 6))
    plt.plot(yBolaPos, tempo, label="Bola")
    plt.plot(yRoboPos, tempo, label="Robo")
    plt.xlabel('y')
    plt.ylabel('Tempo')
    plt.title('Y da Bola e do Robô por Tempo')
    plt.legend()
    plt.grid(True)


    