#include "avl.h"

avl::avl()
{
    this->raiz = NULL;
    this->size = 0;
}

avl::~avl()
{
    destruir(this->raiz);
}

void avl::destruir(proyecto* raiz){
    if (raiz == NULL){
        return;
    }
    destruir(raiz->getIzquierda());
    destruir(raiz->getDerecha());
    delete raiz;
}
void avl::setRaiz(proyecto* nuevo){
    this->raiz = nuevo;
}

proyecto* avl::getRaiz(){
    return this->raiz;
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
        raiz = new proyecto(nombre);
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
    this->size++;
    return raiz;
}

void avl::insertar(string nombre, int id){
    bool crecer = false;
    bool *aCrecer = &crecer;
    id = getId(nombre);
    this->raiz=insertar(this->raiz, nombre, id, *aCrecer);
}

void avl::preOrden(proyecto* actual, int contador){
    if (actual == NULL){
        return;
    }
    cout<<contador<<"preOrden: "<<actual->getId()<<endl;
    preOrden(actual->getIzquierda(),contador+1);
    preOrden(actual->getDerecha(),contador+1);
}



void avl::inOrden(proyecto* actual){
    if (actual == NULL){
        return;
    }
    inOrden(actual->getIzquierda());
    if (actual != NULL){
        cout<<"InOrden: "<<actual->getId()<<endl;
    }
    inOrden(actual->getDerecha());
}

void avl::postOrden(proyecto* actual){
    if (actual == NULL){
        return;
    }
    postOrden(actual->getIzquierda());
    postOrden(actual->getDerecha());
    if (actual != NULL){
        cout<<"PostOrden: "<<actual->getId()<<endl;
    }
}

void avl::imprimir(){
    proyecto* padre = this->getRaiz();
    string ruta = "./Impresiones/Proyectos";
    string salida = "proyecto_" + to_string(padre->getId()) + padre->getNombre()+".png";
    string entrada = "Impresiones/Proyectos/proyecto_" + to_string(padre->getId()) + padre->getNombre()+".dot";
    string nombre = ruta + "/" + "proyecto_"+to_string(padre->getId()) + padre->getNombre()+".dot";
    string cmd = "dot -Tpng " + entrada + " -O "+salida;
    //string borrar = "del "+entrada;
    ofstream archivo(nombre);
    imprimir(padre,archivo, true);
    archivo<<"}";
    archivo.close();
    system(cmd.c_str());
    //system(borrar.c_str());
    
}

void avl::imprimir(proyecto* padre, ofstream& file, bool primero){
    proyecto* izq = padre->getIzquierda();
    proyecto* der = padre->getDerecha();
    if (primero){
        file<<"digraph A {"<<endl;
        file<<"node [fontname=\"Arial\"];"<<endl;
    }
    if (izq){
        file<<"P"<<padre->getId()<<"->"<<"P"<<izq->getId()<<endl;
        imprimir(izq,file,false);
    }
    if (der){
        file<<"P"<<padre->getId()<<"->"<<"P"<<der->getId()<<endl;
        imprimir(der,file,false);
    }
    return;
}

int avl::getId(string nombre){
   string cadena = nombre;
   int n = cadena.length();
   int sumatoria = 0;
   char char_array[n+1];
   strcpy(char_array,cadena.c_str());
   for (int i=0;i<n;i++){
       //cout<<char_array[i]<<endl;
       sumatoria = sumatoria+int(char_array[i]);
   }
   return sumatoria;
}
int avl::getSize(){
    return this->size;
}

listaGenerica<nProyecto>* avl::getCopia(){
    listaGenerica<nProyecto>* lista = new listaGenerica<nProyecto>();
    return getCopia(lista,this->raiz);
} 

listaGenerica<nProyecto>* avl::getCopia(listaGenerica<nProyecto>* lista, proyecto* actual){
    if (actual == NULL){
        return lista;
    }
    getCopia(lista,actual->getIzquierda());
    if (actual != NULL){
        nProyecto* nuevo = new nProyecto(actual);
        lista->add(nuevo);
        nuevo->setValor(lista->getTamano());
    }
    getCopia(lista,actual->getDerecha());  
    return lista;  
} 



