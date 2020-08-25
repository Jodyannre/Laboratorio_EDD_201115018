#include "Cabecera.h"


Cabecera::Cabecera(int n){
    this->numero = n;
}

void Cabecera::setNumero(int n){
    this->numero = n;
}

int Cabecera::getNumero(){
    return this->numero;
}