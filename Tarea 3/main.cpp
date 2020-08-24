#include <iostream>
#include <string>
#include "nodo.h"
#include "arbol.h"

using namespace std;

int main(){
    arbol* a = new arbol();
    a->agregar(5);
    a->agregar(4);
    a->agregar(3);
    a->agregar(2);
    a->agregar(1);
    a->agregar(3);
    a->agregar(4);
    a->agregar(4);
    a->agregar(6);
    a->agregar(7);
    a->agregar(7);
    a->agregar(8);
    a->agregar(9);
    a->agregar(5);
    a->agregar(6);
    a->agregar(6);
    a->eliminar(4,a->getRaiz());
    a->eliminar(6,a->getRaiz());
    a->preOrden(a->getRaiz());
    a->inOrden(a->getRaiz());
    a->postOrden(a->getRaiz());
    a->destruir(a->getRaiz());
    delete a;
    return 0;
}