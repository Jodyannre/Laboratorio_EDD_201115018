#include "NodoDM.h"

NodoDM::NodoDM(int i, string n, char l, string c)
{
    this->id = i;
    this->nombre = n;
    this->letra = l;
    this->color = c;
}

void NodoDM::setNombre(string n){
    this->nombre = n;
}

void NodoDM::setId(int i){
    this->id = i;
}

void NodoDM::setLetra(char l){
    this->letra = l;
}

void NodoDM::setColor(string c){
    this->color = c;
}

int NodoDM::getId(){
    return this->id;
}

string NodoDM::getNombre(){
    return this->nombre;
}

char NodoDM::getLetra(){
    return this->letra;
}

string NodoDM::getColor(){
    return this->color;
}

int NodoDM::getPosX(){
    return this->posx;
}

int NodoDM::getPosY(){
    return this->posy;
}

void NodoDM::setPosX(int p){
    this->posx = p;
}

void NodoDM::setPosY(int p){
    this->posy = p;
}

NodoDM::~NodoDM()
{
}