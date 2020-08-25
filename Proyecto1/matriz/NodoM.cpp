#include "NodoM.h"



NodoM::NodoM(/*Sin Argumetos*/)
{
    this->arriba = NULL;
    this->abajo = NULL;
    this->izquierda = NULL;
    this->derecha = NULL;

}

void NodoM::setArriba(NodoM* n){
    this->arriba = n;
}

void NodoM::setAbajo(NodoM* n){
    this->abajo = n;
}

void NodoM::setDerecha(NodoM* n){
    this->derecha = n;
}

void NodoM::setIzquierda(NodoM* n){
    this->izquierda = n;
}

NodoM* NodoM::getArriba(){
    return this->arriba;
}

NodoM* NodoM::getAbajo(){
    return this->abajo;
}

NodoM* NodoM::getDerecha(){
    return this->derecha;
}

NodoM* NodoM::getIzquierda(){
    return this->izquierda;
}

NodoM::~NodoM()
{
}