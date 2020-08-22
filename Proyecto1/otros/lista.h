#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include "nodoL.h"

//Lista que contendra todos los nodos con coodenadas de la posicion de los objetos y que ira dentro de un objeto.
class lista
{
private:
    nodoL* head;
    nodoL* tail;
    int tamaño;
public:
    lista();
    void add(nodoL* n);
    void del(int id);
    nodoL* buscar(int id);
    ~lista();
};


#endif