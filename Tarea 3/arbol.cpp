#include "arbol.h"



arbol::arbol()
{
    this->raiz = NULL;
}

void arbol::agregar(int dato){
    nodo* nuevo = new nodo(dato);
    if (this->raiz == NULL){
        this->raiz = nuevo;
    }else{
        recorrer(nuevo, this->raiz);
    }
}

bool arbol::recorrer(nodo* nuevo,nodo* actual){
    if (nuevo->getDato() >= actual->getDato() && actual->getDerecho()==NULL){
        actual->setDerecho(nuevo);
        return true;
    }
    if (nuevo->getDato() <= actual->getDato() && actual->getIzquierdo()==NULL){
        actual->setIzquierdo(nuevo);
        return true;
    }
    if (nuevo->getDato() >= actual->getDato() ){
        recorrer(nuevo, actual->getDerecho());
        return true;
    }
    if (nuevo->getDato() <= actual->getDato() ){
        recorrer(nuevo, actual->getIzquierdo());
        return true;
    }
    return true;
}


nodo* arbol::eliminar(int dato, nodo* actual){
    if (actual == NULL){
        return actual;
    }
    if (dato < actual->getDato()){
        actual->setIzquierdo(eliminar(dato,actual->getIzquierdo()));
    }
    else if (dato > actual->getDato()){
        actual->setDerecho(eliminar(dato,actual->getDerecho()));
    }
    else{
        if(actual->getIzquierdo()==NULL){
            nodo* temp = actual->getDerecho();
            delete actual;
            return temp;
        }
        else if (actual->getDerecho()==NULL){
            nodo* temp = actual->getIzquierdo();
            delete actual;
            return temp;
        }
        nodo* temp = buscar(actual->getDerecho());
        actual->setDato(temp->getDato());
        actual->setDerecho(eliminar(temp->getDato(), actual->getDerecho()));
    }
    return actual;
}

nodo* arbol::buscar(nodo* actual) 
{ 
    nodo* temp = actual; 
    while (temp && temp->getIzquierdo() != NULL) 
        temp = temp->getIzquierdo(); 
  
    return temp; 
} 

arbol::~arbol()
{
    if (this->raiz == NULL){
        return;
    }
    destruir(this->raiz);
}

bool arbol::destruir(nodo* actual){
    nodo* auxI = actual->getIzquierdo();
    nodo* auxD = actual->getDerecho();
    if (auxI == NULL && auxD == NULL){
        delete actual;
        return true;
    }
    if (auxI != NULL && auxD != NULL){
        destruir(auxI);
        destruir(auxD);
        return true;
    }
    if (auxI != NULL){
        destruir(auxI);
        return true;
    }
    if (auxD != NULL){
        destruir(auxD);
        return true;
    }
    return true;
}

nodo* arbol::getRaiz(){
    return this->raiz;
}

void arbol::preOrden(nodo* actual){
    if (actual == NULL){
        return;
    }
    cout<<"preOrden: "<<actual->getDato()<<endl;
    preOrden(actual->getIzquierdo());
    preOrden(actual->getDerecho());
}

void arbol::inOrden(nodo* actual){
    if (actual == NULL){
        return;
    }
    inOrden(actual->getIzquierdo());
    if (actual != NULL){
        cout<<"InOrden: "<<actual->getDato()<<endl;
    }
    inOrden(actual->getDerecho());
}

void arbol::postOrden(nodo* actual){
    if (actual == NULL){
        return;
    }
    postOrden(actual->getIzquierdo());
    postOrden(actual->getDerecho());
    if (actual != NULL){
        cout<<"PostOrden: "<<actual->getDato()<<endl;
    }
}
