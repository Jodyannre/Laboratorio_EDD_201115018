#include "nodoHijo.h"


nodoHijo::nodoHijo(int dato):nodoGenerico()
{
    this->dato = dato;
}

nodoHijo::~nodoHijo()
{
}

int nodoHijo::getDato(){
    return this->dato;
}