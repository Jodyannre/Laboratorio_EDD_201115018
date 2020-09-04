#ifndef PROYECTO_H
#define PROYECTO_H
#include <iostream>
#include <string>
#include <ctime>
#include "listaM/pivote.h"
#include "listaM/listaM.h"
#include <bits/stdc++.h>
#include <fstream>

using namespace std;

class proyecto
{
private:
    string nombreOriginal;
    int id;
    proyecto* derecha;
    proyecto* izquierda;
    int factor;
    string fecha;
    listaM* dato;
    void setNombre();

    
    //Lista para las otras estructuras
    void setFecha();
public:
    proyecto(string nombre);
    proyecto(int id);
    void setId(int i);
    void setDerecha(proyecto* d);
    void setIzquierda(proyecto* i);
    void setNombre(string n);
    void setFactor(int f);

    string getNombre();
    int getId();
    int getFactor();
    proyecto* getIzquierda();
    proyecto* getDerecha();
    ~proyecto();
};




#endif