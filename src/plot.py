import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import numpy as np

def XYroboBola(xBolaPos, yBolaPos, xRoboPos, yRoboPos):
    # Criar o gráfico
    plt.figure(num="Trajetoria", figsize=(9, 6))
    plt.plot(xBolaPos, yBolaPos, label='Bola', color="red")
    plt.plot(xRoboPos, yRoboPos, label='Robo')
    plt.xlabel('x (m)')
    plt.ylabel('y (m)')
    plt.title('Posição da Bola e do Robô')
    plt.legend()
    plt.grid(True)

    # Definir os limites do eixo x e do eixo y
    plt.xlim(0, 9)
    plt.ylim(0, 6)

def distancia(tempo, dist):
    # Criar o gráfico
    plt.figure(num="Distância")
    plt.plot(tempo, dist, label='Distância',  color="red")
    plt.xlabel('tempo (s)')
    plt.ylabel('Distância (m)')
    plt.title('Distância entre os objetos em função do tempo')
    plt.legend()
    plt.grid(True)

    

def trajetoriaX(xBolaPos, xRoboPos, tempo):
    # Criar o gráfico
    plt.figure(num="Posição X por Tempo")
    plt.plot(tempo, xBolaPos, label="Bola", color="red")
    plt.plot(tempo, xRoboPos, label="Robo")
    plt.xlabel('Tempo (s)')
    plt.ylabel('x (m)')
    plt.title('X da Bola e do Robô em função do Tempo')
    plt.legend()
    plt.grid(True)



def trajetoriaY(yBolaPos, yRoboPos, tempo):
    # Criar o gráfico
    plt.figure(num="Posição Y por tempo")
    plt.plot(tempo, yBolaPos, label="Bola",  color="red")
    plt.plot(tempo, yRoboPos, label="Robo")
    plt.xlabel('Tempo (s)')
    plt.ylabel('y (m)')
    plt.title('Y da Bola e do Robô em função do Tempo')
    plt.legend()
    plt.grid(True)


def velocidadeX(xBolaVelo, xRoboVelo, tempo):
    # Criar o gráfico
    plt.figure(num="Velocidade em X")
    plt.plot(tempo, xBolaVelo, label='Bola',  color="red")
    plt.plot(tempo, xRoboVelo, label='Robo')
    plt.xlabel('Tempo (s)')
    plt.ylabel('Velocidade (m/s)')
    plt.title('Velocidade da Bola e do Robô em função do tempo')
    plt.legend()
    plt.grid(True)
    
def velocidadeY(yBolaVelo, yRoboVelo, tempo):
    # Criar o gráfico
    plt.figure(num="Velocidade em Y")
    plt.plot(tempo, yBolaVelo, label='Bola',  color="red")
    plt.plot(tempo, yRoboVelo, label='Robo')
    plt.xlabel('Tempo (s)')
    plt.ylabel('Velocidade (m/s)')
    plt.title('Velocidade da Bola e do Robô em função do tempo')
    plt.legend()
    plt.grid(True)

def aceleracaoX(xBolaAcele, xRoboAcele, tempo):
    # Criar o gráfico
    plt.figure(num="Aceleração em X")
    plt.plot(tempo, xBolaAcele, label='Bola',  color="red")
    plt.plot(tempo, xRoboAcele, label='Robo')
    plt.xlabel('Tempo (s)')
    plt.ylabel('Aceleração (m/s²)')
    plt.title('Aceleração da Bola e do Robô em função do tempo')
    plt.legend()
    plt.grid(True)

def aceleracaoY(yBolaAcele, yRoboAcele, tempo):
    # Criar o gráfico
    plt.figure(num="Aceleração em Y")
    plt.plot(tempo, yBolaAcele, label='Bola',  color="red")
    plt.plot(tempo, yRoboAcele, label='Robo')
    plt.xlabel('tempo (s)')
    plt.ylabel('y (m/s²)')
    plt.title('Aceleração da Bola e do Robo em função do tempo')
    plt.legend()
    plt.grid(True)

# Animação:
def clear_animation():
    plt.close('Trajetoria')

def animate_BolaRobo(xBolaPos, yBolaPos, xRoboPos, yRoboPos):
    # Criar o gráfico
    fig, ax = plt.subplots(figsize=(9, 6))
    ax.set_xlim(0, 9)
    ax.set_ylim(0, 6)
    ax.set_xlabel('x (m)')
    ax.set_ylabel('y (m)')
    ax.set_title('Posição da Bola e do Robô')
    ax.grid(True)

    line_bola, = ax.plot([], [], label='Bola', color='red')
    line_robo, = ax.plot([], [], label='Robo')

    def update(frame):
        if frame < len(xBolaPos):
            line_bola.set_data(xBolaPos[:frame], yBolaPos[:frame])
            line_robo.set_data(xRoboPos[:frame], yRoboPos[:frame])
        return line_bola, line_robo

    ani = FuncAnimation(fig, update, frames=len(xBolaPos), blit=True, interval = 100)
    plt.title('Animação')
    plt.legend()
    plt.show()
