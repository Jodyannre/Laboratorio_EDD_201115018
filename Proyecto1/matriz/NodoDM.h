#ifndef NODODM_H
#define NODODM_H
#include "NodoM.h"
#include <iostream>
#include <string>

using namespace std;

// Nodo datos matriz
class NodoDM:public NodoM
{
private:
    int id;
    string nombre;
    char letra;
    string color;
    int posx,posy;
    //string puntos; <<<<<-------- Falta idear esto, pero creo que sera una lista enlazada
   
public:
    NodoDM(int i, string n, char l, string c);
    void setNombre(string n);
    void setLetra(char l);
    void setColor(string c);
    void setId(int i);
    void setPosX(int p);
    void setPosY(int p);
    string getNombre();
    char getLetra();
    string getColor();
    int getId();
    int getPosX();
    int getPosY();
    ~NodoDM();
};


#endif