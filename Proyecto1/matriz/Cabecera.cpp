#include "Cabecera.h"


Cabecera::Cabecera(int n){
    this->numero = n;
    this->posx = 0;
    this->posy = 0;
}

void Cabecera::setNumero(int n){
    this->numero = n;
}

int Cabecera::getNumero(){
    return this->numero;
}

void Cabecera::setPosX(int p){
    this->posx = p;
}
void Cabecera::setPosY(int p){
    this->posy = p;
}
/*
int Cabecera::getPosX(){
    return this->posx;
}
int Cabecera::getPosY(){
    return this->posy;
}
*/