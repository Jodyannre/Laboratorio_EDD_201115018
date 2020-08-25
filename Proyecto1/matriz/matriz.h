#ifndef MATRIZ_H
#define MATRIZ_H
#include "NodoM.h"
#include "NodoDM.h"
#include "Cabecera.h"
#include <iostream>
#include <string>

using namespace std;

class matriz
{
private:
    Cabecera* x;
    Cabecera* y;
    Cabecera* crearX(int n);
    Cabecera* crearY(int n);
    Cabecera* getCabeceraX(int n);
    Cabecera* getCabeceraY(int n);
    NodoM* getUltimoX(Cabecera* cabecera,int numero);
    NodoM* getUltimoY(Cabecera* cabecera,int numero);
public:
    matriz();
    void add(NodoDM* n);
    void codigo();
    ~matriz();
};



#endif