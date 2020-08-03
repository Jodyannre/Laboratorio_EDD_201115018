#include "nodo.h"
#include <iostream>
#include <conio.h>
#include <string.h>

//Constructor
nodo::nodo(string nombre, int carnet)
{
    this->carnet = carnet;
    this->nombre = nombre;
    this->siguiente = NULL;
}

nodo::nodo(){
    
}

//Destructor
nodo::~nodo()
{
}

//Funciones

string nodo::getNombre(){
    return this->nombre;
}

int nodo::getCarnet(){
    return this->carnet;
}

nodo* nodo::getSiguiente(){
    return this->siguiente;
}

void nodo::setSiguiente(nodo* siguiente){
    this->siguiente = siguiente;
}
