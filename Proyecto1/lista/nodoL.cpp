#include "nodoL.h"


nodoL::nodoL(coordenada *dato)
{
    this->dato = dato;
    this->sig=NULL;
    this->ant=NULL;
}
nodoL::nodoL(){
    this->dato = NULL;
    this->sig=NULL;
    this->ant=NULL;  
}

nodoL::~nodoL()
{
}

nodoL* nodoL::getSig(){
    return this->sig;
}

nodoL* nodoL::getAnt(){
    return this->ant;
}

void nodoL::setSig(nodoL* n){
    this->sig = n;
}

void nodoL::setAnt(nodoL* n){
    this->ant = n;
}

coordenada* nodoL::getDato(){
    return this->dato;
}

void nodoL::setDato(coordenada* dato){
    this->dato = dato;
}

