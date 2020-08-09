#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "ListaC.h"
#include "NodoC.h"
int main(){
    NodoA* a=newNodoC(10);
    NodoA* b=newNodoC(3);
    NodoC* c=newNodoC(25);
    ListaC* l=nuevaLista();
    add(l,a);
    add(l,b);
    add(l,c);
    //eliminar(2,l);
    //getNodo(2,l);
    imprimir(l);
    generar(l);
    Liberar(l);
    free(l);
    return 0;
}