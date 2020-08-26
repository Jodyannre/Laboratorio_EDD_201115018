#ifndef ARBOL_H
#define ARBOL_H
#include <iostream>
#include <string>
#include "nodo.h"
using namespace std;

class arbol
{
private:
    nodo* raiz;
public:
    arbol();
    void agregar(int dato);
    void preOrden(nodo* actual);
    void inOrden(nodo* actual);
    void postOrden(nodo* actual);
    bool recorrer(nodo* nuevo, nodo* actual);
    nodo* buscar(nodo* actual);
    nodo* eliminar(int dato, nodo* actual);
    ~arbol();
    bool destruir(nodo* actual);
    nodo* getRaiz();

};




#endif