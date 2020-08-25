#include "avl.h"

avl::avl()
{
    this->raiz = NULL;
}

avl::~avl()
{
    borrar(this->raiz);
}

void avl::borrar(proyecto* raiz){
    if (raiz == NULL){
        return;
    }
    borrar(raiz->getIzquierda());
    borrar(raiz->getDerecha());
    delete raiz;
}

proyecto* avl::rotacionII(proyecto* n, proyecto* m){
    n->setIzquierda(m->getDerecha());
    m->setDerecha(n);
    if(m->getFactor()==-1){
        n->setFactor(0);
        m->setFactor(0);
    }
    else{
        n->setFactor(-1);
        m->setFactor(-1);
    }
    return m;
}
proyecto* avl::rotacionID(proyecto* n, proyecto* m){
    proyecto* n2 = m->getDerecha();
    n->setIzquierda(n2->getDerecha());
    n2->setDerecha(n);
    m->setDerecha(n2->getIzquierda());
    n2->setIzquierda(m);
    if (n2->getFactor()==1){
        m->setFactor(-1);
    }else{
        m->setFactor(0);
    }
    if (n2->getFactor()==-1){
        n->setFactor(1);
    }else{
        n->setFactor(0);
    }
    n2->setFactor(0);
    return n2;
}
proyecto* avl::rotacionDD(proyecto* n, proyecto* m){
    n->setDerecha(m->getIzquierda());
    m->setIzquierda(n);
    if(m->getFactor()==1){
        n->setFactor(0);
        m->setFactor(0);
    }
    else{
        n->setFactor(1);
        m->setFactor(-1);
    }
    return m;
}
proyecto* avl::rotacionDI(proyecto* n, proyecto* m){
    proyecto* n2 = m->getIzquierda();
    n->setDerecha(n2->getIzquierda());
    n2->setIzquierda(n);
    m->setIzquierda(n2->getDerecha());
    n2->setDerecha(m);
    if (n2->getFactor()==1){
        n->setFactor(-1);
    }else{
        n->setFactor(0);
    }
    if (n2->getFactor()==-1){
        m->setFactor(1);
    }else{
        m->setFactor(0);
    }
    n2->setFactor(0);
    return n2;
}
proyecto* avl::insertar(proyecto* raiz, string nombre, int id,bool &validar){
    proyecto* n1;
    if (raiz == NULL){
        raiz = new proyecto(nombre, id);
        validar = true;
    }
    else if (id < raiz->getId()){
        proyecto* izq = insertar(raiz->getIzquierda(), nombre, id, validar);
        raiz->setIzquierda(izq);
        if (validar){
            switch(raiz->getFactor()){
                case 1:
                    raiz->setFactor(0);
                    validar = false;
                    break;
                case 0:
                    raiz->setFactor(-1);
                    break;
                case -1:
                    n1 = raiz->getIzquierda();
                    if (n1->getFactor()==-1){
                        raiz = rotacionII(raiz, n1);
                    }else{
                        raiz = rotacionID(raiz, n1);
                    }
                    validar = false;
                    break; 
            }
        }
    }else if (id >= raiz->getId()){
        proyecto* der = insertar(raiz->getDerecha(), nombre, id, validar);
        raiz->setDerecha(der);
        if (validar){
            switch(raiz->getFactor()){
                case 1:
                    n1 = raiz->getDerecha();
                    if (n1->getFactor()==1){
                        raiz = rotacionDD(raiz,n1);
                    }else{
                        raiz = rotacionDI(raiz,n1);
                    }
                    validar = false;
                    break;
                case 0:
                    raiz->setFactor(1);
                    break;
                case -1:
                    raiz->setFactor(0);
                    validar = false;
                    break;
            }
        }
    }
    return raiz;
}

void avl::insertar(string nombre, int id){
    bool crecer = false;
    bool *aCrecer = &crecer;
    this->raiz=insertar(this->raiz, nombre, id, *aCrecer);
}