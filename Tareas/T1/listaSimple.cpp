#include <iostream>
#include <string>
#include "listaSimple.h"

listaSimple::listaSimple()
{
    this->head = NULL;
    this->last = NULL;
    this->size = 0;
}

listaSimple::~listaSimple()
{
}

void listaSimple::push(nodo* nuevo){
    if (this->head == NULL){
        this->head = nuevo;
        this->last = nuevo;
        this->size++;
    } else {
        this->last->setSiguiente(nuevo);
        this->last = nuevo;
        this->size++;
    }

}

void listaSimple::pop(int carnet){
    nodo* n = getNodo(carnet);
    nodo* actual = this->head;
    nodo* aux;
    if (n != NULL){
        while (actual!= NULL){
            if (n == actual){
                if (actual == head && actual == last){
                    delete actual;
                    head = NULL;
                    last = NULL;  
                    this->size--; 
                    break;   
                }
                else if (actual == head){
                    this->head->setSiguiente(actual->getSiguiente());
                }
                else if (actual == last){
                    this->last=aux;
                    last->setSiguiente(NULL);
                }
                else{
                    aux->setSiguiente(actual->getSiguiente());
                }
                delete actual;  
                this->size--; 
                break;             
            }
            aux = actual;
            actual = actual->getSiguiente();
        }  
    }
    else{
        cout<<"Registro inexistente"<<endl;
    }
  
}

nodo* listaSimple::getNodo(int carnet){
    nodo* n = this->head;
    nodo* aux;
    while (n!= NULL){
        if (n->getCarnet() == carnet){
            return n;
        }
        aux = n->getSiguiente();
        n = aux;
        if (aux != NULL){
            aux = aux->getSiguiente(); 
        }
    }
    return n;
}

int listaSimple::getSize(){
    return this->size;
}

void listaSimple::show(int carnet){
    nodo* n = getNodo(carnet);
    if (n != NULL){
        try{
            cout<< n->getNombre()<<"\n";
        }
        catch(int i){
            cout<< "Registro inexistente"<<endl;
        }       
    }
    else{
        cout<< "Registro inexistente\n";
    }
}


