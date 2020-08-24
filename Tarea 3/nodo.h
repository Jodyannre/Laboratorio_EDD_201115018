#ifndef NODO_H
#define NODO_H
#include <iostream>
#include <string>
using namespace std;

class nodo
{
private:
    int dato;
    nodo* izquierda;
    nodo* derecha;
public:
    nodo(int dato);
    void setIzquierdo(nodo* n);
    void setDerecho(nodo* n);
    nodo* getIzquierdo();
    nodo* getDerecho();
    int getDato();
    void setDato(int dato);
    ~nodo();
};

#endif