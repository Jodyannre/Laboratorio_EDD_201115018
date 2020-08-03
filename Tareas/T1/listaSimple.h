#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H
#include "nodo.h"
#include <iostream>
#include <string.h>

using namespace std;

class listaSimple
{
private:
    nodo *head,*last;
    int size;
public:
    listaSimple();
    void push(nodo* nuevo);
    void pop(int carnet);
    void show(int carnet);
    int getSize();
    nodo* getNodo(int carnet);
    ~listaSimple();
};
#endif // LISTASIMPLE_H