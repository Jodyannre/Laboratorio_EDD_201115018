#ifndef PROYECTO_H
#define PROYECTO_H
#include <iostream>
#include <string>

using namespace std;

class proyecto
{
private:
    string nombreOriginal;
    int id;
    proyecto* derecha;
    proyecto* izquierda;
    int factor;
    //variable de tiempo
    //Lista para las otras estructuras

public:
    proyecto(string nombre, int id);
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