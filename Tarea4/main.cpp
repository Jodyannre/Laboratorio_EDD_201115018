#include <iostream>
#include <string>
#include <stdbool.h>
#include <stdio.h>
#include "metodo.h"

using namespace std;

int main(){

    string cadenas[]={"Hola como estas","Yo bien gracias","ESTE ES UN MENSAJE","Vamos a ganar EDD todos juntos","!!!!Vamos a sacar 100","$$$$$$$$$#$$$$$","Este es el ultimo mensaje del dia de hoy*45"};
    cout<<cadenas->size()<<endl;
    metodo* m = new metodo(cadenas);
    m->imprimirArray();
    m->quicksort();
    m->imprimirArray();
    return 0;    
}