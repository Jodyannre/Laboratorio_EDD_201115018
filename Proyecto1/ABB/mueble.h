#ifndef MUEBLE_H
#define MUEBLE_H
#include <iostream>
#include <string>

using namespace std;

class mueble
{
private:
    int id;
    string nombre;
    char letra;
    string color;
    int grado;
    mueble* derecha;
    mueble* izquierda;
    int factor;
public:
    mueble(int id, string nombre, char letra, string color, int grado);
    void setId(int id);
    void setNombre(string nombre);
    void setLetra(char letra);
    void setColor(string color);
    void setGrado(int grado);
    void setDerecha(mueble* n);
    void setIzquierda(mueble* n);
    void setFactor(int valor);
    int getId();
    string getNombre();
    char getLetra();
    string getColor();
    int getGrado();
    mueble* getDerecha();
    mueble* getIzquierda();
    int getFactor();
    ~mueble();
};

#endif