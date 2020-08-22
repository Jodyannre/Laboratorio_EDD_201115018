#include "nodoB.h"

    nodoB::nodoB(objeto* o){
        this->dato = o;
        this->id = dato->getId();
        this->der = NULL;
        this->izq = NULL;
        this->padre = NULL;
        this->altura = 0;
    }
    int nodoB::getAltura(){
        return this->altura;
    }
    nodoB* nodoB::getDer(){
        return this->der;
    }
    nodoB* nodoB::getIzq(){
        return this->izq;
    }
    nodoB* nodoB::getPadre(){
        return this->padre;
    }
    nodoB::~nodoB(){

    }

