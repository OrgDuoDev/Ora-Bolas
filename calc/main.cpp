#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <vector>

#define vd double> 

using namespace std;
extern "C"{

    struct Data {
        int size;

        double* xRoboPos;
        double* yRoboPos;
        
        double* xBolaPos;
        double* yBolaPos;

        double* tempo;
        //double>velBola; aplicar depois
        //double>velRobo; aplicar depois

        //double>AceleracaoRobo; Aplicar depois
        //double>AceleracaoBola; Aplicar depois

    };
    /*
    // teste
    Data* calculo(double xRoboInit, double yRoboInit, double vel);
    int main(){
        Data* result = calculo(1.01, 5, 0.056);
        
        for(int i = 0; i < result->size; i++){
            cout << "BOLA: " << result->xBolaPos[i] << " " << result->yBolaPos[i] << " Robo: " << result->xRoboPos[i] << " " << result->yRoboPos[i] << " Tempo: " << result->tempo[i]<< endl;
        }
    }
    */

    Data* calculo(double xRoboInit, double yRoboInit, double vel){
        vector<double> xRoboPos;
        vector<double> yRoboPos;
        vector<double> xBolaPos;
        vector<double> yBolaPos;
        vector<double> vTempo;

        xRoboPos.push_back(xRoboInit);
        yRoboPos.push_back(yRoboInit);


        ifstream arq("trajetoria.txt");
        string linha;


        int pos = 0;
        if (arq.is_open()) {
            double tBola, xBola, yBola;

            // Le os valores iniciais do robo e da bola
            getline(arq, linha);
            istringstream iss(linha);
            if (iss >> tBola >> xBola >> yBola) {
                xBolaPos.push_back(xBola);
                yBolaPos.push_back(yBola);
                vTempo.push_back(tBola);        
            }
        
            double distancia = sqrt(pow(xRoboInit - xBola, 2) + pow(yRoboInit - yBola, 2));
            
            if(distancia > 0.115){

                // Variáveis de Posição;
                double xRobo, yRobo, tempo;

                // Laço de Repetição que lê linha do trajetoria.txt a cada repetição
                while(getline(arq, linha)){
                    istringstream iss(linha);
                    if (iss >> tempo >> xBola >> yBola) {

                        // Variáveis de Cálculo
                        double CA, CO, theta, dx, dy;
                        double novoX, novoY;

                        // Posição Atual do Robo;
                        xRobo = xRoboPos[pos];
                        yRobo = yRoboPos[pos];

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
                        xRoboPos.push_back(novoX);
                        yRoboPos.push_back(novoY);
                        xBolaPos.push_back(xBola);
                        yBolaPos.push_back(yBola);
                        vTempo.push_back(tempo);

                        distancia = sqrt(pow(novoX - xBolaPos[pos + 1], 2) + pow(novoY - yBolaPos[pos + 1], 2));
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
        Data res;

        Data* data = new Data();
        data->size = pos + 2;

        data->xBolaPos = new double[data->size + 2];
        data->yBolaPos = new double[data->size + 2];
        data->xRoboPos = new double[data->size + 2];
        data->yRoboPos = new double[data->size + 2];
        data->tempo = new double[data->size + 2];



        for(int i = 0; i < pos + 2; i++){
            data->xBolaPos[i] = xBolaPos[i];
            data->yBolaPos[i] = yBolaPos[i];
            data->xRoboPos[i] = xRoboPos[i];
            data->yRoboPos[i] = yRoboPos[i];
            data->tempo[i] = vTempo[i];
        }
        return data;
    }

}

extern "C" void free_data(Data* data) {
    delete[] data->xBolaPos;
    delete[] data->yBolaPos;
    delete[] data->xRoboPos;
    delete[] data->yRoboPos;
    delete[] data->tempo; 
    delete data;
}