#include <iostream>
#include <string>
#include "nodo.h"
#include "arbol.h"

using namespace std;

int main(){
    arbol* a = new arbol();
    a->agregar(10);
    a->agregar(1);
    a->agregar(20);
    a->agregar(15);
    a->agregar(8);
    a->agregar(96);
    a->agregar(23);
    a->agregar(4);
    a->agregar(7);
    a->agregar(32);
    a->preOrden(a->getRaiz());
    a->inOrden(a->getRaiz());
    a->postOrden(a->getRaiz());
    a->destruir(a->getRaiz());
    delete a;
    return 0;
}