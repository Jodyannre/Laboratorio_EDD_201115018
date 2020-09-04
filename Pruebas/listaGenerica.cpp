#include "listaGenerica.h"


template <class T>
listaGenerica<T>::listaGenerica()
{
    this->primero = NULL;
    this->ultimo = NULL;
}

template <class T>
listaGenerica<T>::~listaGenerica()
{
}

template <class T>
void listaGenerica<T>::add(T* n){
    if (this->primero == NULL){
        this->primero = n;
        this->ultimo = n;
        this->tamano += 1;
    }else{
        this->ultimo->setSig(n);
        n->setAnt(this->ultimo);
        this->ultimo= n;
        this->tamano +=1;
    }
}
template <class T>
void listaGenerica<T>::del(int id){

}
template <class T>
void listaGenerica<T>::setPrimero(T* n){
    this->primero = n;
}
template <class T>
void listaGenerica<T>::setUltimo(T* n){
    this->ultimo = n;
}
template <class T>
void listaGenerica<T>::imprimir(T* raiz){

}
template <class T>
void listaGenerica<T>::destruirElementos(T* raiz){
    if (raiz != NULL){
        T* temp = raiz->getSig();
        if (temp != NULL){temp->setAnt(NULL);}
        delete raiz;
        destruirElementos(temp);
        return;
    }
    return;
}
template <class T>
T* listaGenerica<T>::buscar(int id, T* nodo){
    return nodo;
}
template <class T>
T* listaGenerica<T>::getPrimero(){
    return this->primero;
}
template <class T>
T* listaGenerica<T>::getUltimo(){
    return this->ultimo;
}


template class listaGenerica<nodoGenerico>;