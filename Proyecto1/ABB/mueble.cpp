#include "mueble.h"



mueble::mueble(int id, string nombre, char letra, string color, int grado)
{
    this->id = id;
    this->nombre = nombre;
    this->letra = letra;
    this->color = color;
    this->grado = grado;
    this->izquierda = NULL;
    this->derecha = NULL;
}

void mueble::setId(int id){
    this->id = id;
}
void mueble::setNombre(string nombre){
    this->nombre = nombre;
}
void mueble::setLetra(char letra){
    this->letra = letra;
}
void mueble::setColor(string color){
    this->color = color;
}
void mueble::setGrado(int grado){
    this->grado = grado;
}
void mueble::setDerecha(mueble* n){
    this->derecha = n;
}
void mueble::setIzquierda(mueble* n){
    this->izquierda = n;
}
void mueble::setFactor(int factor){
    this->factor = factor;
}
int mueble::getId(){
    return this->id;
}
string mueble::getNombre(){
    return this->nombre;
}
char mueble::getLetra(){
    return this->letra;
}
string mueble::getColor(){
    return this->color;
}
int mueble::getGrado(){
    return this->grado;
}
mueble* mueble::getDerecha(){
    return this->derecha;
}
mueble* mueble::getIzquierda(){
    return this->izquierda;
}
int mueble::getFactor(){
    return this->factor;
}

mueble::~mueble()
{
}