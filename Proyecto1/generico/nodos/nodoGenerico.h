#ifndef NODOGENERICO_H
#define NODOGENERICO_H
#include <iostream>
#include <string>

using namespace std;

// Nodos que contendran las coordenadas de los objetos y que luego iran dentro de una lista doblemente enlazada

class nodoGenerico
{
private:
    nodoGenerico* sig;
    nodoGenerico* ant;
    int valor;
public:
    nodoGenerico();
    ~nodoGenerico();
    nodoGenerico* getSig();
    nodoGenerico* getAnt();
    int getValor();
    void setSig(nodoGenerico* n);
    void setAnt(nodoGenerico* n);
    void setDato();
    void setValor(int v);
};
#endif