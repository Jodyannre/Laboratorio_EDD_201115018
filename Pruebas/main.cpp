#include "listaGenerica.h"
#include "nodoGenerico.h"
#include "nodoHijo.h"
#include <iostream>

using namespace std;

int main(){
    nodoHijo* n1 = new nodoHijo(1);
    nodoHijo* n2 = new nodoHijo(2);
    nodoHijo* n3 = new nodoHijo(3);
    nodoHijo* n4 = new nodoHijo(4);
    nodoHijo* n5 = new nodoHijo(5);
    listaGenerica<nodoGenerico>* lista = new listaGenerica<nodoGenerico>();
    lista->add(n1);
    lista->add(n2);
    lista->add(n3);
    lista->add(n4);
    lista->add(n5);
    nodoGenerico* aux = lista->getPrimero();
    for (int i;i<4;i++){
        cout<<((nodoHijo*)aux)->getDato()<<endl;
        aux = aux->getSig();
    }   
    return 0;
}