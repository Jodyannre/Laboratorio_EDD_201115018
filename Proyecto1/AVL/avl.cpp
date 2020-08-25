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

}