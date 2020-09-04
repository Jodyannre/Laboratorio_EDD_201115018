#include <iostream>
#include <string>
#include <stdbool.h>
#include <stdio.h>
#include "metodo.h"

using namespace std;

int main(){

    string cadenas[5] = {"hola","nos vemos","manana","por","la tarde"};
    metodo* m = new metodo(cadenas);
    m->imprimirArray();
    m->quicksort();
    m->imprimirArray();
    return 0;    
}