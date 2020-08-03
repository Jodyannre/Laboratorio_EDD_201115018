#ifndef NODO_H
#define NODO_H
#include <iostream>
#include <string>

using namespace std;

//Head
class nodo
{
private:
    string nombre;
    int carnet;
    nodo *siguiente;
public:
    nodo(string nombre, int carnet); //Constructor
    nodo(); //Consructor
    string getNombre(); //Función para conseguir nombre
    int getCarnet(); //Función para conseguir carnet
    nodo *getSiguiente(); //Función para conseguir el siguiente nodo
    void setSiguiente(nodo* siguiente); //FUnción para ingresar el siguiente
    ~nodo();
};
#endif // NODO_H
