#ifndef COORDENADA_H
#define COORDENADA_H
#include <iostream>
#include <string>
using namespace std;

//Clase que contendrá las coordenadas X y Y de los muebles dentro de la matriz dispersa.
class coordenada
{
private:
    int x,y,valor;
    coordenada *sig, *ant;
public:
    coordenada(int x, int y, int valor);
    coordenada();
    void setX(int x);
    void setY(int y);
    void setValor(int n);
    int getX();
    int getY();
    int getValor();
    coordenada* getSig();
    coordenada* getAnt();
    void setSig(coordenada* n);
    void setAnt(coordenada* n);
    ~coordenada();
};



#endif