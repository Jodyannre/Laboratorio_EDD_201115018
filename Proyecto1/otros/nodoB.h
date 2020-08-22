#ifndef NODOB_H
#define NODOB_H
#include <iostream>
#include <string>
#include "objeto.h"
// Nodos que contendran los objetos y que luego ingresaran a un arbol binario de busqueda
using namespace std;

class nodoB
{
private:
    nodoB* der;
    nodoB* izq;
    nodoB* padre;
    int id;
    objeto* dato;
    
    int altura;
public:
    nodoB(objeto* o);
    int getAltura();
    nodoB* getDer();
    nodoB* getIzq();
    nodoB* getPadre();
    ~nodoB();
};

#endif