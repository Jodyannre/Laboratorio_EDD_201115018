#include "nodo.h"



nodo::nodo(int dato)
{
    this->dato = dato;
    this->derecha = NULL;
    this->izquierda = NULL;
}

void nodo::setIzquierdo(nodo* n){
        this->izquierda = n;
    }
void nodo::setDerecho(nodo* n){
        this->derecha = n;
    }
nodo* nodo::getIzquierdo(){
        return this->izquierda;
    }
nodo* nodo::getDerecho(){
        return this->derecha;
    }
int nodo::getDato(){
        return this->dato;
    }
void nodo::setDato(int dato){
    this->dato = dato;
}
nodo::~nodo()
{

}