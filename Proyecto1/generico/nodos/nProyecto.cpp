#include "nProyecto.h"


nProyecto::nProyecto(proyecto* dato){
    this->sig=NULL;
    this->ant=NULL;  
    this->dato = dato;
    this->valor = 0;
}

nProyecto::~nProyecto()
{
}

nProyecto* nProyecto::getSig(){
    return this->sig;
}

nProyecto* nProyecto::getAnt(){
    return this->ant;
}

void nProyecto::setSig(nProyecto* n){
    this->sig = n;
}

void nProyecto::setAnt(nProyecto* n){
    this->ant = n;
}

void nProyecto::setDato(proyecto* n){
    this->dato = n;
}

proyecto* nProyecto::getDato(){
    return this->dato;
}

int nProyecto::getValor(){
    return this->valor;
}

void nProyecto::setValor(int v){
    this->valor = v;
}