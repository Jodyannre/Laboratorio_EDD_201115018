#include "mueble.h"



mueble::mueble(int id, string nombre, char letra, string color, int grado)
{
    this->id = id;
    this->nombre = nombre;
    this->letra = letra;
    this->color = color;
    this->grado = grado;
    this->coordenadas = new lista();
}

mueble::mueble(){
    this->id = 0;
    this->nombre = "";
    this->letra = 'a';
    this->color = "";
    this->grado = 0; 
    this->izquierda = NULL;
    this->derecha = NULL;
    this->coordenadas = new lista();
}

void mueble::setDato(int id){
    this->id = id;
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
int mueble::getDato(){
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
void mueble::agregarCoordenada(int x, int y, int valor){
    coordenada* nueva = new coordenada(x,y,valor);
    this->coordenadas->add(nueva);
}
lista* mueble::getCoordenadas(){
    return this->coordenadas;
}
mueble* mueble::getDerecha(){
    return this->derecha;
}
mueble* mueble::getIzquierda(){
    return this->izquierda;
}

void mueble::eliminarLista(){
    this->coordenadas->destruirElementos(this->coordenadas->getPrimero());
    delete this->coordenadas;
}

mueble::~mueble()
{
}