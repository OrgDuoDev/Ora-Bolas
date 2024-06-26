#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;
extern "C" {

    struct Data {
        int size;

        double* xRoboPos;
        double* yRoboPos;

        double* xRoboVelo;
        double* yRoboVelo;

        double* xRoboAcele;
        double* yRoboAcele;
        
        double* xBolaPos;
        double* yBolaPos;

        double* xBolaVelo;
        double* yBolaVelo;

        double* xBolaAcele;
        double* yBolaAcele;

        double* dist;
        double* tempo;
    };

    
    Data* calculo(double xRoboInit, double yRoboInit, double vel);
    int main(){
        Data* result = calculo(1.5, 1, 0.056);
        cout << fixed << setprecision(10);
        for(int i = 0; i < result->size; i++){
            cout << "BOLA A: " << result->xBolaAcele[i] << " " << result->yBolaAcele[i] << " Robo A: " <<  result->xRoboAcele[i] << " " << result->yRoboAcele[i] << " Tempo: " << result->tempo[i]<< " Dist: " << result->dist[i] << endl;
        }
        cout << "-----------------------------" << endl;
        for(int i = 0; i < result->size; i++){
           cout << "BOLA V: " << result->xBolaVelo[i] << " " << result->yBolaVelo[i] << " Robo V: " <<  result->xRoboVelo[i] << " " << result->yRoboVelo[i] << " Tempo: " << result->tempo[i]<< " Dist: " << result->dist[i] << endl;
        }
        cout << "-----------------------------" << endl;
        for(int i = 0; i < result->size; i++){
           cout << "BOLA S: " << result->xBolaPos[i] << " " << result->yBolaPos[i] << " Robo S: " <<  result->xRoboPos[i] << " " << result->yRoboPos[i] << " Tempo: " << result->tempo[i]<< " Dist: " << result->dist[i] << endl;
        }
    }
    
    

    Data* calculo(double xRoboInit, double yRoboInit, double vel){
        Data* data = new Data();
        ifstream arq("trajetoria.txt");
        string linha;
        
        int pos = 0;
        int bolaPos = 0;
        int roboPos = 0;
        if (arq.is_open()) {
            // Vector de Posição, Tempo, Distância e Velocidade
            vector<double> xRoboPos;
            vector<double> yRoboPos;
            vector<double> xBolaPos;
            vector<double> yBolaPos;

            vector<double> vTempo;
            vector<double> vDist;

            vector<double> xRoboVelo; 
            vector<double> yRoboVelo;
            vector<double> xBolaVelo; 
            vector<double> yBolaVelo;  

            vector<double> xRoboAcele;
            vector<double> yRoboAcele;
            vector<long double> xBolaAcele;
            vector<double> yBolaAcele;

            double distancia;       
            double temp, xBola, yBola;

            getline(arq, linha); 
            istringstream iss(linha); 
            if (iss >> temp >> xBola >> yBola) {
                xBolaPos.push_back(xBola);
                yBolaPos.push_back(yBola);
                
                vTempo.push_back(temp);

                xRoboPos.push_back(xRoboInit);
                yRoboPos.push_back(yRoboInit);
                
                distancia = sqrt(pow(xRoboInit - xBola, 2) + pow(yRoboInit - yBola, 2));
                vDist.push_back(distancia);

            }
            // Velocidade inicial = 0
            xRoboVelo.push_back(0);
            yRoboVelo.push_back(0);
            xBolaVelo.push_back(0);
            yBolaVelo.push_back(0);

            // Aceleração inicial = 0
            xRoboAcele.push_back(0);
            yRoboAcele.push_back(0);
            xBolaAcele.push_back(0);
            yBolaAcele.push_back(0);

            xRoboAcele.push_back(0);
            yRoboAcele.push_back(0);
            xBolaAcele.push_back(0);
            yBolaAcele.push_back(0);

            if(distancia > 0.1115){
            
                while(getline(arq, linha)){
                    int lineValidate = 0;

                    // Le os valores iniciais do  da bola
                    istringstream iss(linha); 
                    if (iss >> temp >> xBola >> yBola) {
                        xBolaPos.push_back(xBola);
                        yBolaPos.push_back(yBola);
                        vTempo.push_back(temp);  

                        // Lê um valor a mais no primeiro loop para permtir que o robo veja posições futuras da bola
                        // Velocidade da bola a cada momento
                        xBolaVelo.push_back(abs(xBolaPos[pos + 1] - xBolaPos[pos]) / 0.2);
                        yBolaVelo.push_back(abs(yBolaPos[pos + 1] - yBolaPos[pos]) / 0.2);

                        if(pos > 0){
                            yBolaAcele.push_back((yBolaVelo[pos + 1] - yBolaVelo[pos]) / 0.2);
                            xBolaAcele.push_back((xBolaVelo[pos + 1] - xBolaVelo[pos]) / 0.2);
                        }
                        

                        lineValidate = 1;      
                    }

                    if(lineValidate){
                        // Variáveis de Cálculo
                        double CA, CO, theta, dx, dy;
                        double novoX, novoY;

                        // Posição Atual do Robo e Bola;
                        double xRobo = xRoboPos[pos];
                        double yRobo = yRoboPos[pos];

                        double xBola = xBolaPos[pos + 1];
                        double yBola = yBolaPos[pos + 1];

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
                        int podeDarBreak = 0;
                        // Verifica a Distãncia entre o Robo e a Bola
                        distancia = sqrt(pow(novoX - xBolaPos[pos + 1], 2) + pow(novoY - yBolaPos[pos + 1], 2));
                        if(distancia < 0.1115){
                            /*
                            double parametro = (sqrt(2) / 2) * 0.1115;
                            if(novoX >= xBolaPos[pos + 1]  && novoY >= yBolaPos[pos + 1]){ // Primeiro Quadrante
                                
                                CA = abs(novoX - xBolaPos[pos + 1]);
                                CO = abs(novoY - yBolaPos[pos + 1]);
                                theta = atan2(CO, CA);
                                
                                double pX = abs(sin(theta) * 0.1115);
                                double pY = abs(cos(theta) * 0.1115);
                                
                                novoX = xBolaPos[pos + 1] + pX; 
                                novoY = yBolaPos[pos + 1] + pY;             
                            }
                            else if(novoX < xBolaPos[pos + 1]  && novoY > yBolaPos[pos + 1]){ // Segundo Quadrante
                                
                                CA = abs(novoX - xBolaPos[pos + 1]);
                                CO = abs(novoY - yBolaPos[pos + 1]);
                                theta = atan2(CO, CA);
                                
                                double sX = abs(sin(theta) * 0.1115);
                                double sY = abs(cos(theta) * 0.1115);
                               
                                novoX = xBolaPos[pos + 1] - sX; 
                                novoY = yBolaPos[pos + 1] + sY;      
                            }
                            else if(novoX <= xBolaPos[pos + 1]  && novoY <= yBolaPos[pos + 1]){ // Terceiro Quadrante
                                
                                CA = abs(novoY - yBolaPos[pos + 1]);
                                CO = abs(novoX - xBolaPos[pos + 1]);
                                theta = atan2(CO, CA);
                                
                                double tX = abs(sin(theta) * 0.1115);
                                double tY = abs(cos(theta) * 0.1115);
                                
                                novoX = xBolaPos[pos + 1] - tX; 
                                novoY = yBolaPos[pos + 1] - tY; 
                            }
                            else{ // Quarto Quadrante:
                                CA = abs(novoY - yBolaPos[pos + 1]);
                                CO = abs(novoX - xBolaPos[pos + 1]);
                                theta = atan2(CO, CA);

                                double qX = abs(sin(theta) * 0.1115);
                                double qY = abs(cos(theta) * 0.1115);
                                
                                novoX = xBolaPos[pos + 1] + qX; 
                                novoY = yBolaPos[pos + 1] - qY; 
                            }
                            */

                            distancia = sqrt(pow(novoX - xBolaPos[pos + 1], 2) + pow(novoY - yBolaPos[pos + 1], 2)); 
                            podeDarBreak = 1;
                            //break;
                        }    
                        // Adiciona as novas posições do Robo
                        xRoboPos.push_back(novoX);
                        yRoboPos.push_back(novoY);

                        // Adiciona a velocidade do Robo deste momento
                        xRoboVelo.push_back(abs(xRoboPos[pos + 1] - xRoboPos[pos]) /0.2);
                        yRoboVelo.push_back(abs(yRoboPos[pos + 1] - yRoboPos[pos]) /0.2);

                        if(pos > 0){
                            xRoboAcele.push_back((xRoboVelo[pos + 1] - xRoboVelo[pos]) /0.2);
                            yRoboAcele.push_back((yRoboVelo[pos + 1] - yRoboVelo[pos]) /0.2);
                        }

                        // Salva a distancia
                        vDist.push_back(distancia);

                        if(podeDarBreak){
                            break;
                        }

                    }
                    else{
                        cout << "Erro Ao Ler Arquivo!\n";
                        break;
                    }
                    pos++;
                }
            }
            arq.close();

            // Cria um novo Data com o tamanho já definido
            data->size = vTempo.size(); // Utilizado o x do Robo para tamanho por ser o vector mais seguro
            data->xBolaPos = new double[data->size];
            data->yBolaPos = new double[data->size];
            data->xRoboPos = new double[data->size];
            data->yRoboPos = new double[data->size];

            data->xBolaVelo = new double[data->size];
            data->yBolaVelo = new double[data->size];
            data->xRoboVelo = new double[data->size];
            data->yRoboVelo = new double[data->size];

            data->xBolaAcele = new double[data->size];
            data->yBolaAcele = new double[data->size];
            data->xRoboAcele = new double[data->size];
            data->yRoboAcele = new double[data->size];

            data->tempo = new double[data->size];
            data->dist = new double[data->size];

            // Transporta os valores dos vector para as arrays do Data
            for(int i = 0; i < data->size; i++){
                data->xBolaPos[i] = xBolaPos[i];
                data->yBolaPos[i] = yBolaPos[i];
                data->xRoboPos[i] = xRoboPos[i];
                data->yRoboPos[i] = yRoboPos[i];

                data->xBolaVelo[i] = xBolaVelo[i];
                data->yBolaVelo[i] = yBolaVelo[i];
                data->xRoboVelo[i] = xRoboVelo[i];
                data->yRoboVelo[i] = yRoboVelo[i];

                data->xBolaAcele[i] = xBolaAcele[i];
                data->yBolaAcele[i] = yBolaAcele[i];
                data->xRoboAcele[i] = xRoboAcele[i];
                data->yRoboAcele[i] = yRoboAcele[i];

                data->tempo[i] = vTempo[i];
                data->dist[i] = vDist[i];
            }
        }
        return data;
    }   
}   
