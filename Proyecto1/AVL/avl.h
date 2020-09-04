#ifndef AVL_H
#define AVL_H
#include <iostream>
#include <string>
#include "proyecto.h"
#include <stdbool.h>
#include <fstream>
#include "../generico/listaGenerica.h"
#include <cstring>


class avl
{
private:
    proyecto* raiz;
    proyecto* insertar(proyecto* raiz,string nombre, int valor,bool &validar);
    proyecto* rotacionII(proyecto* n, proyecto* m);
    proyecto* rotacionID(proyecto* n, proyecto* m);
    proyecto* rotacionDD(proyecto* n, proyecto* m);
    proyecto* rotacionDI(proyecto* n, proyecto* m);
    void imprimir(proyecto* padre, ofstream& file, bool primero);
    int getId(string nombre);
    int size;
    listaGenerica<nProyecto>* getCopia(listaGenerica<nProyecto>* lista, proyecto* nodo);
public:
    avl();
    void insertar(string nombre, int id);
    void insertar(int id);
    proyecto* getRaiz();
    void destruir(proyecto* raiz);
    void setRaiz(proyecto* nuevo);
    void preOrden(proyecto* actual, int contador);
    void inOrden(proyecto* actual);
    void postOrden(proyecto* actual);
    void imprimir();
    int getSize();
    listaGenerica<nProyecto>* getCopia();
    ~avl();
};





#endif