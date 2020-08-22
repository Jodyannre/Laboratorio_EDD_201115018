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
public:
    Cabecera(int n);
    void setNumero(int n);
    int getNumero();
    ~Cabecera();
};





#endif