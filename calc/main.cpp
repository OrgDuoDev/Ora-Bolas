#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <vector>

#define vd vector<double> 

using namespace std;
extern "C"{

    struct TD {
        vector<double> xRoboPos;
        vector<double> yRoboPos;
        
        vector<double>xBolaPos;
        vector<double>yBolaPos;

        vector<double>tempo;

        //vector<double>velBola; aplicar depois
        //vector<double>velRobo; aplicar depois

        //vector<double>AceleracaoRobo; Aplicar depois
        //vector<double>AceleracaoBola; Aplicar depois

    };

    /*
    // teste

    */
    TD calculo(double xRoboInit, double yRoboInit, double vel);
    int main(){
        TD result = calculo(1.01, 5, 0.056);
        
        for(int i = 0; i < result.xRoboPos.size(); i++){
            cout << "BOLA: " << result.xBolaPos[i] << " " << result.yBolaPos[i] << " Robo: " << result.xRoboPos[i] << " " << result.yRoboPos[i] << " Tempo: " << result.tempo[i]<< endl;
        }
    }

    TD calculo(double xRoboInit, double yRoboInit, double vel){
        TD result; 

        result.xRoboPos.push_back(xRoboInit);
        result.yRoboPos.push_back(yRoboInit);


        ifstream arq("trajetoria.txt");
        string linha;


        if (arq.is_open()) {
            double tBola, xBola, yBola;

            // Le os valores iniciais do robo e da bola
            getline(arq, linha);
            istringstream iss(linha);
            if (iss >> tBola >> xBola >> yBola) {
                result.xBolaPos.push_back(xBola);
                result.yBolaPos.push_back(yBola);
                result.tempo.push_back(tBola);        
            }
        
            double distancia = sqrt(pow(xRoboInit - xBola, 2) + pow(yRoboInit - yBola, 2));
            
            if(distancia > 0.115){

                // Variáveis de Posição;
                int pos = 0;
                double xRobo, yRobo, tempo;

                // Laço de Repetição que lê linha do trajetoria.txt a cada repetição
                while(getline(arq, linha)){
                    istringstream iss(linha);
                    if (iss >> tempo >> xBola >> yBola) {

                        // Variáveis de Cálculo
                        double CA, CO, theta, dx, dy;
                        double novoX, novoY;

                        // Posição Atual do Robo;
                        xRobo = result.xRoboPos[pos];
                        yRobo = result.yRoboPos[pos];

                        // Calculo de Catetos e do angulo theta:
                        if( (xRobo > xBola && yRobo > yBola) || (xRobo < xBola && yRobo > yBola) ){
                            CA = abs(xRobo - xBola);
                            CO = abs(yRobo - yBola);
                            theta = atan2(CO, CA);
                        }
                        else if((xRobo < xBola && yRobo < yBola) || (xRobo > xBola && yRobo < yBola)){
                            CA = abs(yRobo - yBola);
                            CO = abs(xRobo - xBola);
                            theta = atan2(CO, CA);
                        }


                        // Caso o Robo já tenha x ou y igual ao da bola, ele se movimentará somente na direção que está diferente:
                        if(xRobo == xBola){
                            if(yRobo > yBola){
                                novoX = xRobo;
                                novoY = yRobo - vel;
                            }
                            else{
                                novoX = xRobo;
                                novoY = yRobo + vel;  
                            }
                        }
                        else if(yRobo == yBola){ 
                            if(xRobo > xBola){
                                novoX = xRobo - vel;
                                novoY = yRobo;
                            }
                            else{
                                novoX = xRobo + vel;
                                novoY = yRobo;
                            }
                        }
                        else{
                            if(xRobo > xBola && yRobo > yBola){ // Calcula o DX e DY no Primeiro Quadrante
                                dx = abs(cos(theta) * vel); 
                                dy = abs(sin(theta) * vel);
                                novoX = xRobo - dx;
                                novoY = yRobo - dy;
                            }
                            else if(xRobo < xBola && yRobo > yBola){ // Calcula o DX e DY no Segundo Quadrante
                                dx = abs(cos(theta) * vel); 
                                dy = abs(sin(theta) * vel);
                                novoX = xRobo + dx;
                                novoY = yRobo - dy;
                            }
                            else if(xRobo < xBola && yRobo < yBola){ // Calcula o DX e DY no Terceiro Quadrante
                                dx = abs(sin(theta) * vel);
                                dy = abs(cos(theta) * vel);
                                novoX = xRobo + dx;
                                novoY = yRobo + dy;
                            }
                            else{ // Calcula o DX e DY no Quarto Quadrante
                                dx = abs(sin(theta) * vel);
                                dy = abs(cos(theta) * vel);
                                novoX = xRobo - dx;
                                novoY = yRobo + dy;
                            }
                        }

                        // Salvando Valores do Robo e Bola no Vector
                        result.xRoboPos.push_back(novoX);
                        result.yRoboPos.push_back(novoY);
                        result.xBolaPos.push_back(xBola);
                        result.yBolaPos.push_back(yBola);
                        result.tempo.push_back(tempo);

                        distancia = sqrt(pow(novoX - result.xBolaPos[pos + 1], 2) + pow(novoY - result.yBolaPos[pos + 1], 2));
                        if(distancia <= 0.1115){
                            break;
                        }    
                    }
                    else{
                        cout << "Erro ao Ler linha, corrija o arquivo." << endl;
                    }
                    pos++;
                }
            }
            arq.close();
        }
        return result;
    }

}




