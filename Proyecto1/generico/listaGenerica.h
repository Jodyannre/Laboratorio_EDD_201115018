#ifndef LISTAGENERICA_H
#define LISTAGENERICA_H
#include <iostream>
#include <string>
#include "nodos/nProyecto.h"

using namespace std;


template <class T>
class listaGenerica
{
private:
    T* primero;
    T* ultimo;
    int tamano;
public:
    listaGenerica<T>();
    ~listaGenerica();
    void add(T* n);
    void del(int id);
    void setPrimero(T* n);
    void setUltimo(T* n);
    void imprimir(T* raiz);
    void destruirElementos(T* raiz);
    T* buscar(int id, T* nodo);
    T* getPrimero();
    T* getUltimo();
    int getTamano();
    void imprimirCopia(nProyecto* actual);
};





#endif