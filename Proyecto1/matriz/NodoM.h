#ifndef NODOM_H
#define NODOM_H
#include <iostream>

using namespace std;


class NodoM
{

protected:
    int posx,posy;
private:
    NodoM* arriba;
    NodoM* abajo;
    NodoM* izquierda;
    NodoM* derecha;

public:
    NodoM(/* args */);
    void setArriba(NodoM* n);
    void setAbajo(NodoM* n);
    void setIzquierda(NodoM* n);
    void setDerecha(NodoM* n);
    NodoM* getArriba();
    NodoM* getAbajo();
    NodoM* getIzquierda();
    NodoM* getDerecha(); 
    int getPosX();
    int getPosY();
    ~NodoM();
};






#endif