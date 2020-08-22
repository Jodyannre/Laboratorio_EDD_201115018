#include "objeto.h"


objeto::objeto(int id, string nombre, string color, char letra, lista* l)
{
    this->id = id;
    this->nombre = nombre;
    this->color = color;
    this->letra = letra;
    this->l = l;
}

objeto::~objeto()
{
}

int objeto::getId(){
    return this->id;
}