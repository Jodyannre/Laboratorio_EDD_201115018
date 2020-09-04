#ifndef ARBOL_H
#define ARBOL_H
#include <iostream>
#include <string>
#include "../libreria/mueble.h"
#include <fstream>
using namespace std;

class arbol
{
private:
    mueble* raiz;
    void imprimir(mueble* padre, ofstream& file, bool primero);
public:
    arbol();
    void agregar(int dato, string nombre, char letra, string color, int grado);
    void agregar(mueble* nuevo);
    void preOrden(mueble* actual);
    void inOrden(mueble* actual);
    void postOrden(mueble* actual);
    bool recorrer(mueble* nuevo, mueble* actual);
    mueble* buscar(mueble* actual);
    mueble* eliminar(int dato, mueble* actual);
    ~arbol();
    bool destruirElementos(mueble* actual);
    mueble* getRaiz();
    void imprimir(int proyecto, int nivel);
    bool repetido(int id, mueble* actual, bool validar); //Actual es el nodo raiz desde el inicio; id es el buscado;
};




#endif