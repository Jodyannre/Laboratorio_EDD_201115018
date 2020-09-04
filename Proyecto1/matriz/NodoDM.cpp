#include "NodoDM.h"

NodoDM::NodoDM(mueble* dato)
{
    contador++;
    this->dato = dato;
    this->id = contador;
    this->parte = 0;
    this->posx = 0;
    this->posy = 0;
}

/*
int NodoDM::getPosX(){
    return this->posx;
}

int NodoDM::getPosY(){
    return this->posy;
}
*/
void NodoDM::setPosX(int p){
    this->posx = p;
}

void NodoDM::setPosY(int p){
    this->posy = p;
}

void NodoDM::setDato(mueble* m){
    this->dato = m;
}
mueble* NodoDM::getDato(){
    return this->dato;
}

int NodoDM::getId(){
    return this->id;
}
int NodoDM::getParte(){
    return this->id;
}

void NodoDM::setId(int i){
    this->id = i;
}

void NodoDM::setParte(int i){
    this->parte = i;
}

NodoDM::~NodoDM()
{
}