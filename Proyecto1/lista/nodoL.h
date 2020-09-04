#ifndef NODOL_H
#define NODOL_H
#include <iostream>
#include "../libreria/coordenada.h"
// Nodos que contendran las coordenadas de los objetos y que luego iran dentro de una lista doblemente enlazada

class nodoL
{
private:
    coordenada* dato;
    nodoL* sig;
    nodoL* ant;
    int valor;
public:
    nodoL(coordenada* dato);
    nodoL();
    ~nodoL();
    nodoL* getSig();
    nodoL* getAnt();
    int getValor();
    void setSig(nodoL* n);
    void setAnt(nodoL* n);
    void setDato(coordenada* dato);
    void setValor(int v);
    coordenada* getDato();
};
#endif