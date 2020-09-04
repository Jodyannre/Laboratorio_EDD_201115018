#include "proyecto.h"

proyecto::proyecto(string nombre)
{
    this->nombreOriginal = nombre;
    setNombre();
    this->factor = 0;
    this->derecha = NULL;
    this->izquierda = NULL;
    this->fecha = "";
    this->dato = new listaM();
}

proyecto::proyecto(int id){
    this->nombreOriginal = "";
    this->id = id;
    this->factor = 0;
    this->derecha = NULL;
    this->izquierda = NULL;
    this->fecha = "";
    this->dato = new listaM();
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
void proyecto::setFecha(){
    time_t ahora = time(0);
    this->fecha = ctime(&ahora);
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
void proyecto::setNombre(){
   string cadena = this->nombreOriginal;
   int n = cadena.length();
   int sumatoria = 0;
   char char_array[n+1];
   strcpy(char_array,cadena.c_str());
   for (int i=0;i<n;i++){
       //cout<<char_array[i]<<endl;
       sumatoria = sumatoria+int(char_array[i]);
   }
   this->id = sumatoria;
}

