# Ora-Bolas
Projeto Ora-Bolas, foi criado para um trabalho da matéria de física clássica do 2º semestre de ciência da computação na FEI, no qual um robo precisa interceptar uma bola antes que ela saia do campo de futebol.

Dependencias:
Foram usadas bibliotecas padrões do Python e de C++, entre elas matplotlib, Tkinter e Ctypes de python, todas elas costumam ser intaladas junto com a linguagem, necessário também que tanto o compilador de python e c++ sejam de mesma arquitetura, caso contrário não será posśivel a execução do programa.

Para executar o programa basta estar no diretorio /src e utilizar o comando:

**make**

ou no mesmo diretório utilizar os seguintes comandos:

**g++ -fPIC -shared -o calculo.so main.cpp**

**python main.py**

