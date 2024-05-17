import matplotlib.pyplot as plt
import tkinter as tk
from calc import Cport
from plot import *


def graficos(posX, posY):
    # Chamar a função Cport
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

    # Plotar os gráficos nos subplots
    XYroboBola(xBolaPos_list, yBolaPos_list, xRoboPos_list, yRoboPos_list)
    trajetoriaX(xBolaPos_list, xRoboPos_list, tempo_list)
    trajetoriaY(yBolaPos_list, yRoboPos_list, tempo_list)
    velocidadeX(xBolaVelo_list, xRoboVelo_list, tempo_list)
    velocidadeY(yBolaVelo_list, yRoboVelo_list, tempo_list)
    aceleracaoX(xBolaAcele_list, xRoboAcele_list, tempo_list)
    aceleracaoY(yBolaAcele_list, yRoboAcele_list, tempo_list)
    distancia(tempo_list, dist_list)

    plt.show()

def animacao():
    try:
        x_value = float(entry_x_robo.get())
        y_value = float(entry_y_robo.get())
    except ValueError:
        print("Por favor, insira valores numéricos válidos.")
        return
    
    # Chamar a função Cport
    result = Cport(x_value, y_value)
    size = result.size
    xBolaPos_list = [result.xBolaPos[i] for i in range(result.size)]
    yBolaPos_list = [result.yBolaPos[i] for i in range(result.size)]
    xRoboPos_list = [result.xRoboPos[i] for i in range(result.size)]
    yRoboPos_list = [result.yRoboPos[i] for i in range(result.size)]
    
    clear_animation()
    
    # Estilo do Gráfico
    plt.style.use('Solarize_Light2')
    animate_BolaRobo(xBolaPos_list, yBolaPos_list, xRoboPos_list, yRoboPos_list)

def clearGraficos():
    # Limpar as figuras anteriores
    clear_animation()
    plt.close('all')

def gerarGraficos():
    try:
        x_value = float(entry_x_robo.get())
        y_value = float(entry_y_robo.get())
    except ValueError:
        print("Por favor, insira valores numéricos válidos.")
        return

    clearGraficos()
    graficos(x_value, y_value)

def menu():
    global entry_x_robo, entry_y_robo
    # Criar a janela principal
    root = tk.Tk()
    root.title("Orabolas")
    root.configure(bg='#333333')  # Cor de fundo ajustada para um tom de cinza escuro

    # Fonte em negrito
    bold_font = ("Helvetica", 10, "bold")

    # Criar e posicionar o rótulo e campo de entrada para X Robo
    label_x_robo = tk.Label(root, text="X Robo", bg='#333333', fg='white', font=bold_font)
    label_x_robo.grid(row=0, column=0, padx=10, pady=10)
    entry_x_robo = tk.Entry(root, bg='white', fg='black', bd=0, insertbackground='black')
    entry_x_robo.grid(row=0, column=1, padx=10, pady=10)

    # Criar e posicionar o rótulo e campo de entrada para Y Robo
    label_y_robo = tk.Label(root, text="Y Robo", bg='#333333', fg='white', font=bold_font)
    label_y_robo.grid(row=1, column=0, padx=10, pady=10)
    entry_y_robo = tk.Entry(root, bg='white', fg='black', bd=0, insertbackground='black')
    entry_y_robo.grid(row=1, column=1, padx=10, pady=10)

    # Criar um frame para os botões
    button_frame = tk.Frame(root, bg='#333333')
    button_frame.grid(row=2, column=0, columnspan=2, padx=10, pady=10, sticky='e')

    # Criar e posicionar os botões dentro do frame
    button_gerar = tk.Button(button_frame, text="Gerar Gráficos", command=gerarGraficos, bg='white', fg='black', bd=0, highlightthickness=0)
    button_gerar.pack(side='left', padx=5)

    button_apagar = tk.Button(button_frame, text="Apagar", command=clearGraficos, bg='white', fg='black', bd=0, highlightthickness=0)
    button_apagar.pack(side='left', padx=5)

    button_anima = tk.Button(button_frame, text="Animação", command=animacao, bg='white', fg='black', bd=0, highlightthickness=0)
    button_anima.pack(side='left', padx=5)

    root.mainloop()

menu()