#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int calculo(double xRobo, double yRobo, double xBola, double yBola, double vel){

    double CA, CO, theta, dx, dy;
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
    
    double novoX, novoY;
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
    return novoX, novoY;
}
