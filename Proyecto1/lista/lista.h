#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include "nodoL.h"
#include "../libreria/coordenada.h"
//#include "../libreria/coordenada.cpp"

//Lista que contendra todos los nodos con coodenadas de la posicion de los objetos y que ira dentro de un objeto.

class lista
{
private:
    coordenada* primero;
    coordenada* ultimo;
    int tamano;
public:
    lista();
    void add(coordenada* n);
    void del(int id);
    void setPrimero(coordenada* n);
    void setUltimo(coordenada* n);
    void imprimir(coordenada* raiz);
    void destruirElementos(coordenada* raiz);
    coordenada* buscar(int id, coordenada* nodo);
    coordenada* getPrimero();
    coordenada* getUltimo();
    ~lista();
};


#endif