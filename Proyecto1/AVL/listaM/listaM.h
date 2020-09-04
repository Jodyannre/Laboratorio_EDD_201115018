#ifndef LISTAM_H
#define LISTAM_H
#include <iostream>
#include "pivote.h"
//#include "../libreria/coordenada.cpp"

//Lista que contendra todos los nodos con coodenadas de la posicion de los objetos y que ira dentro de un objeto.

class listaM
{
private:
    pivote* primero;
    pivote* ultimo;
    int tamano;
public:
    listaM();
    void add(pivote* n);
    void del(int id);
    void setPrimero(pivote* n);
    void setUltimo(pivote* n);
    void imprimir(pivote* raiz);
    void destruir(pivote* raiz);
    pivote* getPrimero();
    pivote* getUltimo();
    ~listaM();
};


#endif