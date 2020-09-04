#include "arbol.h"



arbol::arbol()
{
    this->raiz = NULL;
}

void arbol::agregar(int dato, string nombre, char letra, string color, int grado){
    mueble* nuevo = new mueble(dato,nombre,letra,color,grado);
    if (this->raiz == NULL){
        this->raiz = nuevo;
    }else{
        recorrer(nuevo, this->raiz);
    }
}

void arbol::agregar(mueble* nuevo){
    if (this->raiz == NULL){
        this->raiz = nuevo;
    }else{
        recorrer(nuevo, this->raiz);
    }
}

bool arbol::recorrer(mueble* nuevo,mueble* actual){
    if (nuevo->getDato() >= actual->getDato() && actual->getDerecha()==NULL){
        actual->setDerecha(nuevo);
        return true;
    }
    if (nuevo->getDato() <= actual->getDato() && actual->getIzquierda()==NULL){
        actual->setIzquierda(nuevo);
        return true;
    }
    if (nuevo->getDato() >= actual->getDato() ){
        recorrer(nuevo, actual->getDerecha());
        return true;
    }
    if (nuevo->getDato() <= actual->getDato() ){
        recorrer(nuevo, actual->getIzquierda());
        return true;
    }
    return true;
}


mueble* arbol::eliminar(int dato, mueble* actual){
    if (actual == NULL){
        return actual;
    }
    if (dato < actual->getDato()){
        actual->setIzquierda(eliminar(dato,actual->getIzquierda()));
    }
    else if (dato > actual->getDato()){
        actual->setDerecha(eliminar(dato,actual->getDerecha()));
    }
    else{
        if(actual->getIzquierda()==NULL){
            mueble* temp = actual->getDerecha();
            delete actual;
            return temp;
        }
        else if (actual->getDerecha()==NULL){
            mueble* temp = actual->getIzquierda();
            delete actual;
            return temp;
        }
        mueble* temp = buscar(actual->getDerecha());
        actual->setDato(temp->getDato());
        actual->setDerecha(eliminar(temp->getDato(), actual->getDerecha()));
    }
    return actual;
}

mueble* arbol::buscar(mueble* actual) 
{ 
    mueble* temp = actual; 
    while (temp && temp->getIzquierda() != NULL) 
        temp = temp->getIzquierda(); 
  
    return temp; 
} 

arbol::~arbol()
{
    destruirElementos(this->raiz);
}

bool arbol::destruirElementos(mueble* actual){
    mueble* auxI = actual->getIzquierda();
    mueble* auxD = actual->getDerecha();
    if (auxI == NULL && auxD == NULL){
        actual->eliminarLista();
        delete actual;
        return true;
    }
    if (auxI != NULL && auxD != NULL){
        destruirElementos(auxI);
        destruirElementos(auxD);
        return true;
    }
    if (auxI != NULL){
        destruirElementos(auxI);
        return true;
    }
    if (auxD != NULL){
        destruirElementos(auxD);
        return true;
    }
    return true;
}

mueble* arbol::getRaiz(){
    return this->raiz;
}

void arbol::preOrden(mueble* actual){
    if (actual == NULL){
        return;
    }
    cout<<"preOrden: "<<actual->getDato()<<endl;
    preOrden(actual->getIzquierda());
    preOrden(actual->getDerecha());
}

void arbol::inOrden(mueble* actual){
    if (actual == NULL){
        return;
    }
    inOrden(actual->getIzquierda());
    if (actual != NULL){
        cout<<"InOrden: "<<actual->getDato()<<endl;
    }
    inOrden(actual->getDerecha());
}

void arbol::postOrden(mueble* actual){
    if (actual == NULL){
        return;
    }
    postOrden(actual->getIzquierda());
    postOrden(actual->getDerecha());
    if (actual != NULL){
        cout<<"PostOrden: "<<actual->getDato()<<endl;
    }
}

void arbol::imprimir(int proyecto, int nivel){
    mueble* padre = this->getRaiz();
    string ruta = "./Impresiones/Librerias";
    string salida = "libreria_" + to_string(proyecto) + to_string(nivel)+".png";
    string entrada = "Impresiones/Librerias/libreria_" + to_string(proyecto) + to_string(nivel)+".dot";
    string nombre = ruta + "/" + "libreria_"+ to_string(proyecto) + to_string(nivel)+".dot";
    string cmd = "dot -Tpng " + entrada + " -O "+salida;
    //string borrar = "del "+entrada;
    ofstream archivo(nombre);
    imprimir(padre,archivo, true);
    archivo<<"}";
    archivo.close();
    system(cmd.c_str());
    //system(borrar.c_str());    
}

void arbol::imprimir(mueble* padre, ofstream& file, bool primero){
    mueble* izq = padre->getIzquierda();
    mueble* der = padre->getDerecha();
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


/*
bool arbol::repetido(int id, mueble* actual, bool validar){
    if (actual == NULL){
        return false;
    }
    if (actual->getId()==id){
        return true;
    }
    validar = repetido(id,actual->getIzquierda(),repetido);
    if (!validar){ validar = repetido(id, actual->getDerecha(),validar);};
    return validar;
}
*/