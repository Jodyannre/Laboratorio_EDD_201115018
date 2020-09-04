#ifndef METODO_H
#define METODO_H
#include <iostream>
#include <string>
#include <stdbool.h>
#include <stdio.h>
#include <cstring>
using namespace std;

class metodo
{
private:
    string* array;
    int culo;
    int getPivote (string array[], int pequeno, int grande);
    void quicksort(string array[],int pequeno, int grande);
    int getAscii(string cadena);
public:
    metodo(string array[]);
    void imprimirArray();
    void quicksort();
    ~metodo();
};

#endif

