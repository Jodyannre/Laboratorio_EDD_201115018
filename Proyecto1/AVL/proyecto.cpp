#include "proyecto.h"

proyecto::proyecto(string nombre, int id)
{
    this->nombreOriginal = nombre;
    this->id = id;
    this->factor = 0;
    this->derecha = NULL;
    this->izquierda = NULL;
}


void proyecto::setId(int i){
    this->id = i;
}
void proyecto::setDerecha(proyecto* d){
    this->derecha = d;
}
void proyecto::setIzquierda(proyecto* i){
    this->izquierda = i;
}
void proyecto::setNombre(string n){
    this->nombreOriginal = n;
}
void proyecto::setFactor(int f){
    this->factor = f;
}
string proyecto::getNombre(){
    return this->nombreOriginal;
}
int proyecto::getId(){
    return this->id;
}
proyecto* proyecto::getIzquierda(){
    return this->izquierda;
}
proyecto* proyecto::getDerecha(){
    return this->derecha;
}
int proyecto::getFactor(){
    return this->factor;
}
proyecto::~proyecto()
{
}