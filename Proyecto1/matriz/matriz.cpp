#include "matriz.h"
#include <iostream>
#include <string>

using namespace std;

matriz::matriz(/* args */)
{
    this->x = NULL;
    this->y = NULL;
}

Cabecera* matriz::crearX(int n){
    if(this->x == NULL){
        Cabecera* nuevo = new Cabecera(n);
        this->x = nuevo;
        return nuevo;
    }
    Cabecera* aux = this->x;
    if (n <= aux->getNumero()){
        Cabecera* nuevo = new Cabecera(n);
        nuevo->setDerecha(aux);
        this->x->setIzquierda(nuevo);
        this->x = nuevo;
        return nuevo;
    }
    while (aux->getDerecha() != NULL){
        if(n > aux->getNumero() && n <= ((Cabecera*)aux->getDerecha())->getNumero()){
            Cabecera* nuevo = new Cabecera(n);
            Cabecera* tmp= (Cabecera*)aux->getDerecha();
            tmp->setIzquierda(nuevo);
            nuevo->setIzquierda(tmp);
            aux->setDerecha(nuevo);
            nuevo->setIzquierda(aux);
            return nuevo;
        }
        aux = (Cabecera*)aux->getDerecha();
    }
    Cabecera* nuevo = new Cabecera(n);
    aux->setDerecha(nuevo);
    nuevo->setIzquierda(aux);
    return nuevo;
}

Cabecera* matriz::crearY(int n){
    if(this->y == NULL){
        Cabecera* nuevo = new Cabecera(n);
        this->y = nuevo;
        return nuevo;
    }
    Cabecera* aux = this->y;
    if (n <= aux->getNumero()){
        Cabecera* nuevo = new Cabecera(n);
        nuevo->setAbajo(aux);
        this->y->setArriba(nuevo);
        this->y = nuevo;
        return nuevo;
    }
    while (aux->getAbajo() != NULL){
        if(n > aux->getNumero() && n <= ((Cabecera*)aux->getAbajo())->getNumero()){
            Cabecera* nuevo = new Cabecera(n);
            Cabecera* tmp= (Cabecera*)aux->getAbajo();
            tmp->setArriba(nuevo);
            nuevo->setAbajo(tmp);
            aux->setAbajo(nuevo);
            nuevo->setArriba(aux);
            return nuevo;
        }
        aux = (Cabecera*)aux->getAbajo();
    }
    Cabecera* nuevo = new Cabecera(n);
    aux->setAbajo(nuevo);
    nuevo->setArriba(aux);
    return nuevo;
}


NodoM* matriz::getUltimoX(Cabecera* cabecera,int numero){
    if (cabecera->getDerecha()==NULL){
        return cabecera;
    }
    NodoM* aux = cabecera->getDerecha();
    while (aux->getDerecha()!=NULL){
        if (((NodoDM*)aux)->getPosX() <= numero){
            return aux;
        }
        aux = aux->getDerecha();
    }
    if(((NodoDM*)aux)->getPosX() <= numero){
        return aux->getIzquierda();
    }
    return aux;
}

NodoM* matriz::getUltimoY(Cabecera* cabecera,int numero){
    if (cabecera->getAbajo()==NULL){
        return cabecera;
    }
    NodoM* aux = cabecera->getAbajo();
    while (aux->getAbajo()!=NULL){
        if (((NodoDM*)aux)->getPosY() <= numero){
            return aux;
        }
        aux = aux->getAbajo();
    }
    if(((NodoDM*)aux)->getPosY() <= numero){
        return aux->getArriba();
    }
    return aux;    
}


Cabecera* matriz::getCabeceraX(int n){
    if(this->x == NULL){
        return NULL;
    }
    Cabecera* aux = this->x;
    while (aux != NULL){
        if (aux->getNumero()==n){
            return aux;
        }
        aux = (Cabecera*)aux->getDerecha();
    }
    return NULL;
}

Cabecera* matriz::getCabeceraY(int n){
    if(this->y == NULL){
        return NULL;
    }
    Cabecera* aux = this->y;
    while (aux != NULL){
        if (aux->getNumero()==n){
            return aux;
        }
        aux = (Cabecera*)aux->getAbajo();
    }
    return NULL;
}

matriz::~matriz()
{
    /*
        aux = Coordenadas en x
        aux2 = Coordenadas en y
        aux3 = Coordenadas extra en Y
        aux4 = Coordenadas extra en X
        aux5 = Extra para guardar siguientes
        aux6 = Extra para guardar siguientes
    */
    NodoM *aux,*aux2,*aux3,*aux4,*aux5,*aux6;

    aux = this->x;
    aux2 = this->y;
    while(aux != NULL){
        aux3 = aux->getAbajo();
        aux4 = aux->getIzquierda();
        while (aux4 != NULL){
            aux5 = aux4->getIzquierda();
            delete aux4;
            aux4 = aux5;
        }
        delete aux;
        aux = aux3;
    }
    while (aux2 != NULL){
        aux6 = aux2->getDerecha();
        delete aux2;
        aux2 = aux6;
    }
}

void matriz::add(NodoDM* n){
    Cabecera* y = this->getCabeceraY(n->getPosY());
    Cabecera* x = this->getCabeceraX(n->getPosX());
    if (y== NULL){
        y = crearY(n->getPosY());
    }
    if (x== NULL){
        x = crearX(n->getPosX());
    }
    NodoM* izquierda = getUltimoX(x,n->getPosX());
    NodoM* arriba = getUltimoY(y,n->getPosY());
    if (izquierda->getDerecha()== NULL){
        izquierda->setIzquierda(n);
        n->setDerecha(izquierda);
    }else{
        NodoM* tmp = izquierda->getDerecha();
        izquierda->setDerecha(n);
        n->setIzquierda(izquierda);
        tmp->setIzquierda(n);
        n->setDerecha(tmp);
    }
    if (arriba->getAbajo()==NULL){
        arriba->setAbajo(n);
        n->setArriba(arriba);
    }else{
        NodoM* tmp = arriba->getAbajo();
        arriba->setAbajo(n);
        n->setArriba(arriba);
        tmp->setArriba(n);
        n->setAbajo(tmp);
    }
}