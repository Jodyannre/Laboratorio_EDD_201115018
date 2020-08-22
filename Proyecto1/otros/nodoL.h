#ifndef NODOL_H
#define NODOL_H
#include <iostream>
// Nodos que contendran las coordenadas de los objetos y que luego iran dentro de una lista doblemente enlazada
class nodoL
{
private:
    int x,y;
    nodoL* sig;
    nodoL* ant;
public:
    nodoL(int x,int y);
    ~nodoL();
    nodoL* getSig();
    nodoL* getAnt();
    void setSig(nodoL* n);
    void setAnt(nodoL* n);
    int getX();
    int getY();
};
#endif