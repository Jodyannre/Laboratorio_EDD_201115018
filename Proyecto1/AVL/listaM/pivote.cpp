#include "pivote.h"

pivote::pivote(matriz* dato){
    contador++;
    this->dato = dato;
    this->abb = NULL;
    this->sig = NULL;
    this->ant = NULL;
    this->id = contador;
}
pivote::pivote(){
    this->dato = NULL;
    this->abb = NULL;
    this->sig = NULL;
    this->ant = NULL;
    this->id = 0;
}
pivote::~pivote(){

}
pivote* pivote::getSig(){
    return this->sig;
}
pivote* pivote::getAnt(){
    return this->ant;
}
void pivote::setSig(pivote* n){
    this->sig = n;
}
void pivote::setAnt(pivote* n){
    this->ant = n;
}
void pivote::setDato(matriz* dato){
    this->dato = dato;
}
void pivote::setLibreria(arbol* dato){
    this->abb = dato;
}
matriz* pivote::getDato(){
    return this->dato;
}
arbol* pivote::getLibreria(){
    return this->abb;
}