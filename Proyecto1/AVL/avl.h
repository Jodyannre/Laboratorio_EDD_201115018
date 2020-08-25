#ifndef AVL_H
#define AVL_H
#include <iostream>
#include <string>
#include "proyecto.h"
#include <stdbool.h>

class avl
{
private:
    proyecto* raiz;
    proyecto* insertar(proyecto* raiz,string nombre, int valor,bool &validar);
    proyecto* rotacionII(proyecto* n, proyecto* m);
    proyecto* rotacionID(proyecto* n, proyecto* m);
    proyecto* rotacionDD(proyecto* n, proyecto* m);
    proyecto* rotacionDI(proyecto* n, proyecto* m);
    void borrar(proyecto* raiz);
public:
    avl();
    void insertar(string nombre, int id);
    proyecto* getRaiz();
    ~avl();
};





#endif