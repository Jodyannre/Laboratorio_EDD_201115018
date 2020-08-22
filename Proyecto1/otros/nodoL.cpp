#include "nodoL.h"



nodoL::nodoL(int x,int y)
{
    this->x=x;
    this->y=y;
    this->sig=NULL;
    this->ant=NULL;
}

nodoL::~nodoL()
{
}


nodoL* nodoL::getSig(){
    return this->sig;
}
nodoL* nodoL::getAnt(){
    return this->ant;
}
int nodoL::getX(){
    return this->x;
}
int nodoL::getY(){
    return this->y;
}
void nodoL::setSig(nodoL* n){
    this->sig == n;
}
void nodoL::setAnt(nodoL* n){
    this->ant == n;
}