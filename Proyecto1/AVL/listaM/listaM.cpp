#include "listaM.h"



listaM::listaM()
{
    this->primero=NULL;
    this->ultimo=NULL;
    this->tamano=0;
}


listaM::~listaM()
{
}



void listaM::add(pivote* n){
    if (this->primero == NULL){
        this->primero = n;
        this->ultimo = n;
        this->tamano += 1;
    }else{
        this->ultimo->setSig(n);
        n->setAnt(this->ultimo);
        this->ultimo= n;
        this->tamano +=1;
    }
    
}

void listaM::setPrimero(pivote* n){
    this->primero = n;
}

void listaM::setUltimo(pivote* n){
    this->ultimo = n;
}

pivote* listaM::getUltimo(){
    return this->ultimo;
}

pivote* listaM::getPrimero(){
    return this->primero;
}

void listaM::destruir(pivote* raiz){
    if (raiz != NULL){
        pivote* temp = raiz->getSig();
        if (temp != NULL){temp->setAnt(NULL);}
        delete raiz;
        destruir(temp);
        return;
    }
    return;
}