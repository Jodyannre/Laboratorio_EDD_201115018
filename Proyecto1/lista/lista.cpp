#include "lista.h"



lista::lista()
{
    this->primero=NULL;
    this->ultimo=NULL;
    this->tamano=0;
}


lista::~lista()
{
}



void lista::add(coordenada* n){
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

/*
nodoL* lista::buscar(int id){

}
*/

void lista::setPrimero(coordenada* n){
    this->primero = n;
}

void lista::setUltimo(coordenada* n){
    this->ultimo = n;
}

coordenada* lista::getUltimo(){
    return this->ultimo;
}

coordenada* lista::getPrimero(){
    return this->primero;
}

void lista::imprimir(coordenada* raiz){
    if (raiz != NULL){
        cout<<"Coordenada no: "<<raiz->getValor()<<endl;
        cout<<"Pos x: "<<raiz->getX()<<endl;
        cout<<"Pos y: "<<raiz->getY()<<endl;
        imprimir(raiz->getSig());
        return;
    }else{
        return;
    }
}


void lista::destruirElementos(coordenada* raiz){
    if (raiz != NULL){
        coordenada* temp = raiz->getSig();
        if (temp != NULL){temp->setAnt(NULL);}
        delete raiz;
        destruirElementos(temp);
        return;
    }
    return;
}

coordenada* lista::buscar(int id, coordenada* nodo){
    if (nodo != NULL){
        if (nodo->getValor()!= id){
            return buscar(id, nodo->getSig());
        }else{
            return nodo;
        }
    }
    return NULL;
}

