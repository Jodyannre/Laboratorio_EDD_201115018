#include "coordenada.h"



coordenada::coordenada(int x, int y, int valor)
{
    this->x = x;
    this->y = y;
    this->valor = valor;
    this->sig = NULL;
    this->ant = NULL;
}
coordenada::coordenada(){
    this->x = 0;
    this->y = 0;
}

coordenada::~coordenada()
{
}

void coordenada::setX(int x){
    this->x = x;
}
void coordenada::setY(int y){
    this->y = y;
}
void coordenada::setValor(int v){
    this->valor = v;
}
int coordenada::getX(){
    return this->x;
}
int coordenada::getY(){
    return this->y;
}
int coordenada::getValor(){
    return this->valor;
}
coordenada* coordenada::getSig(){
    return this->sig;
}
coordenada* coordenada::getAnt(){
    return this->ant;
}
void coordenada::setSig(coordenada* n){
    this->sig = n;
}
void coordenada::setAnt(coordenada* n){
    this->ant = n;
}


