#ifndef MATRIZ_H
#define MATRIZ_H
#include "NodoM.h"
#include "NodoDM.h"
#include "Cabecera.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class matriz
{
private:
    Cabecera* x;
    Cabecera* y;
    Cabecera* crearX(int n);
    Cabecera* crearY(int n);
    //Cabecera* getCabeceraX(int n);
    //Cabecera* getCabeceraY(int n);
    NodoM* getUltimoX(Cabecera* cabecera,int numero);
    NodoM* getUltimoY(Cabecera* cabecera,int numero);
    void horizontal(ofstream& archivo, Cabecera* matrix);
    void vertical(ofstream& archivo, Cabecera* matrix);
    void cuerpo(ofstream& file, Cabecera* nActual);
    void cuerpo2(ofstream& file, NodoM* nActual);
    void escribirColumnas(ofstream& file, Cabecera* nActual, bool validar);
    void escribirGrupos(ofstream& file, NodoM* nActual);
    void escribirGrupos2(ofstream& file, NodoM* nActual);
    void destruirX(NodoM* cabeza);
    void destruirY(NodoM* cabeza);
public:
    matriz();
    void imprimir(int proyecto, int nivel);
    Cabecera* getPrimerX();
    Cabecera* getPrimerY();
    void add(NodoDM* n);
    void codigo();
    Cabecera* getCabeceraX(int n);
    Cabecera* getCabeceraY(int n);
    ~matriz();
};



#endif