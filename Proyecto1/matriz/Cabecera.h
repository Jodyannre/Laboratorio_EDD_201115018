#ifndef CABECERA_H
#define CABECERA_H
#include "NodoM.h"
#include <iostream>
#include <string>

using namespace std;

class Cabecera:public NodoM
{
private:
    int numero;
    //int posx,posy;
public:
    Cabecera(int n);
    void setNumero(int n);
    int getNumero();
    ~Cabecera();
    void setPosX(int p);
    void setPosY(int p);
    //int getPosX();
    //int getPosY();
};





#endif