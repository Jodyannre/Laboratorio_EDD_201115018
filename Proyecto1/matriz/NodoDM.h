#ifndef NODODM_H
#define NODODM_H
#include "nodoM.h"
#include "../libreria/mueble.h"
#include <iostream>
#include <string>

using namespace std;

// Nodo datos matriz
class NodoDM:public NodoM
{
    int contador = 0;
private:
    mueble* dato;
    //int posx,posy;
    int parte;
    int id;
    //string puntos; <<<<<-------- Falta idear esto, pero creo que sera una lista enlazada
   
public:
    NodoDM(mueble* nuevo);
    void setDato(mueble* nuevo);
    void setPosX(int p);
    void setPosY(int p);
    void setId(int i);
    void setParte(int i);
    mueble* getDato();
    //int getPosX();
    //int getPosY();
    int getParte();
    int getId();
    ~NodoDM();
};


#endif