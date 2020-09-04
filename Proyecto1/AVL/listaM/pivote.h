#ifndef PIVOTE_H
#define PIVOTE_H
#include <iostream>
#include "../../libreria/mueble.h"
#include "../../matriz/matriz.h"
#include "../../ABB/arbol.h"

// Nodos que contendran las coordenadas de los objetos y que luego iran dentro de una lista doblemente enlazada

class pivote
{
    int contador = 0;
private:
    matriz* dato;
    arbol* abb;
    pivote* sig;
    pivote* ant;
    int id;
public:
    pivote(matriz* dato);
    pivote();
    ~pivote();
    pivote* getSig();
    pivote* getAnt();
    void setSig(pivote* n);
    void setAnt(pivote* n);
    void setDato(matriz* dato);
    void setLibreria(arbol* dato);
    matriz* getDato();
    arbol* getLibreria();
};
#endif