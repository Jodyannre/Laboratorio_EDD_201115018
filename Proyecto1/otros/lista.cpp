#include "lista.h"


lista::lista()
{
    this->head=NULL;
    this->tail=NULL;
    this->tamaño=0;
}

lista::~lista()
{
}

void lista::add(nodoL* n){
    
    if (this->head == NULL){
        this->head = n;
        this->tail = n;
        this->tamaño += 1;
    }else if(tamaño ==1){
        this->tail = n;
        this->tail->setAnt(this->head);
        this->head->setSig(this->tail);
    }
    else{
        this->tail->setSig(n);
        n->setAnt(tail);
        this->tail= n;
    }
    
}
void lista::del(int id){

}
nodoL* lista::buscar(int id){

}