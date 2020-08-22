#ifndef OBJETO_H
#define OBJETO_H
#include <iostream>
#include <string>
#include "lista.h"
#include "nodoL.h"

using namespace std;

class objeto
{
private:
    int id;
    string nombre,color;
    char letra;
    lista* l;

public:
    objeto(int id, string nombre, string color, char letra, lista* l);
    ~objeto();
    int getId();
};



#endif
