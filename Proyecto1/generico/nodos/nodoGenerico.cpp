#include "nodoGenerico.h"



nodoGenerico::nodoGenerico(){
    this->sig=NULL;
    this->ant=NULL;  
}

nodoGenerico::~nodoGenerico()
{
}

nodoGenerico* nodoGenerico::getSig(){
    return this->sig;
}

nodoGenerico* nodoGenerico::getAnt(){
    return this->ant;
}

void nodoGenerico::setSig(nodoGenerico* n){
    this->sig = n;
}

void nodoGenerico::setAnt(nodoGenerico* n){
    this->ant = n;
}

void nodoGenerico::setDato(){

}
