#include "matriz.h"

matriz::matriz(/* args */)
{
    this->x = NULL;
    this->y = NULL;
}

Cabecera* matriz::crearX(int n){
    if(this->x == NULL){
        Cabecera* nuevo = new Cabecera(n);
        this->x = nuevo;
        nuevo->setPosX(n);
        nuevo->setPosY(0);
        return nuevo;
    }
    Cabecera* aux = this->x;
    if (n <= aux->getNumero()){
        Cabecera* nuevo = new Cabecera(n);
        nuevo->setPosX(n);
        nuevo->setPosY(0);
        nuevo->setDerecha(aux);
        this->x->setIzquierda(nuevo);
        this->x = nuevo;
        return nuevo;
    }
    while (aux->getDerecha() != NULL){
        if(n > aux->getNumero() && n <= ((Cabecera*)aux->getDerecha())->getNumero()){
            Cabecera* nuevo = new Cabecera(n);
            nuevo->setPosX(n);
            nuevo->setPosY(0);            
            Cabecera* tmp= (Cabecera*)aux->getDerecha();
            tmp->setIzquierda(nuevo);
            nuevo->setDerecha(tmp);
            aux->setDerecha(nuevo);
            nuevo->setIzquierda(aux);
            return nuevo;
        }
        aux = (Cabecera*)aux->getDerecha();
    }
    Cabecera* nuevo = new Cabecera(n);
    aux->setDerecha(nuevo);
    nuevo->setIzquierda(aux);
    nuevo->setPosX(n);
    nuevo->setPosY(0);
    return nuevo;
}

Cabecera* matriz::crearY(int n){
    if(this->y == NULL){
        Cabecera* nuevo = new Cabecera(n);
        this->y = nuevo;
        nuevo->setPosY(n);
        nuevo->setPosX(0);
        return nuevo;
    }
    Cabecera* aux = this->y;
    if (n <= aux->getNumero()){
        Cabecera* nuevo = new Cabecera(n);
        nuevo->setPosY(n);
        nuevo->setPosX(0);
        nuevo->setAbajo(this->y);
        this->y->setArriba(nuevo);
        this->y = nuevo;
        return nuevo;
    }
    while (aux->getAbajo() != NULL){
        if(n > aux->getNumero() && n <= ((Cabecera*)aux->getAbajo())->getNumero()){
            Cabecera* nuevo = new Cabecera(n);
            Cabecera* tmp= (Cabecera*)aux->getAbajo();
            nuevo->setPosY(n);
            nuevo->setPosX(0);
            tmp->setArriba(nuevo);
            nuevo->setAbajo(tmp);
            aux->setAbajo(nuevo);
            nuevo->setArriba(aux);
            return nuevo;
        }
        aux = (Cabecera*)aux->getAbajo();
    }
    Cabecera* nuevo = new Cabecera(n);
    nuevo->setPosY(n);
    nuevo->setPosX(0);
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
        if (((NodoDM*)aux)->getPosX() <= numero && aux->getDerecha()->getPosX() >= numero){
            return aux;
        }
        aux = aux->getDerecha();
    }
    if(((NodoDM*)aux)->getPosX() <= numero){
        return aux;
    }
    return aux->getIzquierda();
}

NodoM* matriz::getUltimoY(Cabecera* cabecera,int numero){
    if (cabecera->getAbajo()==NULL){
        return cabecera;
    }
    NodoM* aux = cabecera->getAbajo();
    while (aux->getAbajo()!=NULL){

        if (((NodoDM*)aux)->getPosY() <= numero && aux->getAbajo()->getPosY() >= numero){
            return aux;
        }
        aux = aux->getAbajo();
    }
    if(((NodoDM*)aux)->getPosY() <= numero){
        return aux;
    }
    return aux->getArriba();    
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
    NodoM* izquierda = getUltimoX(y,n->getPosX());
    NodoM* arriba = getUltimoY(x,n->getPosY());
    if (izquierda->getDerecha()== NULL){
        izquierda->setDerecha(n);
        n->setIzquierda(izquierda);
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

void matriz::imprimir(int proyecto, int nivel){
    string ruta = "./Impresiones/Niveles";
    string nombre = ruta + "/" + "proyecto" + to_string(proyecto) + to_string(nivel) + ".dot";
    string salida = "proyecto" + to_string(proyecto) + to_string(nivel) + ".png";
    string entrada = "Impresiones/Niveles/proyecto" + to_string(proyecto) + to_string(nivel) +".dot";
    string cmd = "dot -Tpng " + entrada + " -O "+salida;
    ofstream archivo(nombre);
    archivo<<"digraph Sparce_Matrix {"<<endl;
    archivo<<"node [shape=box]"<<endl;
    archivo<<"Matriz[ label = \"raiz\", width = 1.5, style = filled, fillcolor = firebrick1, group = 1 ];"<<endl;
    archivo<<"orden0[ shape = point, width = 0 ];"<<endl;
    archivo<<"orden1[ shape = point, width = 0 ];"<<endl;
    horizontal(archivo,this->getPrimerX());
    vertical(archivo,this->getPrimerY());
    archivo<<"Matriz -> F1"<<endl;
    archivo<<"Matriz -> C1"<<endl;
    cuerpo(archivo,this->getPrimerX());
    escribirColumnas(archivo,this->getPrimerX(),true);
    escribirGrupos(archivo,this->getPrimerY());
    archivo<<"}"<<endl;
    archivo.close(); 
    system(cmd.c_str());
}
Cabecera* matriz::getPrimerX(){
    return this->x;
}
Cabecera* matriz::getPrimerY(){
    return this->y;
}


void matriz::horizontal(ofstream& file, Cabecera* matrix){
    Cabecera* c_actual = matrix;
    Cabecera* derecha = (Cabecera*)c_actual->getDerecha();
    int x1,x2;
    int actual =  c_actual->getPosX();
    if (derecha != NULL){
        x2 = derecha->getPosX();
        file<<"C"<<actual<<" [label = \""<<actual<<"\" width = 1.5 style = filled, fillcolor = bisque1, group = "<<actual+1<<" ];"<<endl;
        horizontal(file,(Cabecera*)c_actual->getDerecha());
        file<<"C"<<actual<<" -> C"<<x2<<endl;
        if (derecha != NULL){
            file<<"C"<<x2<<" -> C"<<actual<<endl;
        }
    }else{
        file<<"C"<<actual<<" [label = \""<<actual<<"\" width = 1.5 style = filled, fillcolor = bisque1, group = "<<actual+1<<" ];"<<endl;
    }
    return;

}
void matriz::vertical(ofstream& file, Cabecera* matrix){
    Cabecera* c_actual = matrix;
    Cabecera* abajo = (Cabecera*)c_actual->getAbajo();
    int y1,y2;
    int actual =  c_actual->getPosY();
    if (abajo != NULL){
        y2 = abajo->getPosY();
        file<<"F"<<actual<<" [label = \""<<actual<<"\" width = 1.5 style = filled, fillcolor = bisque1, group = 1 ];"<<endl;
        vertical(file,(Cabecera*)matrix->getAbajo());
        file<<"F"<<actual<<" -> F"<<y2<<endl;
        if (abajo != NULL){
            file<<"F"<<y2<<" -> F"<<actual<<endl;
        }
    }else{
        file<<"F"<<actual<<" [label = \""<<actual<<"\" width = 1.5 style = filled, fillcolor = bisque1, group = 1 ];"<<endl;
    }
    return;
}
void matriz::cuerpo(ofstream& file, Cabecera* nActual){
    NodoM* actual = nActual->getAbajo();
    int x_izq = actual->getIzquierda()->getPosX();
    int y_izq = actual->getIzquierda()->getPosY();
    int x_arriba = actual->getArriba()->getPosX();
    int y_arriba = actual->getArriba()->getPosY();
    int x_actual = actual->getPosX();
    int y_actual = actual->getPosY();

    file<<"N"<<x_actual+y_actual<<"_"<<x_actual+1<<" [label = \""<<x_actual+y_actual<<"\" width = 1.5 style = filled, fillcolor = bisque1, group = "<<x_actual+1<<" ];"<<endl;

    if (x_izq == 0){
        file<<"N"<<x_actual+y_actual<<"_"<<x_actual+1<<" -> F"<<x_izq+y_izq<<endl;
        file<<"F"<<x_izq+y_izq<<" -> N"<<x_actual+y_actual<<"_"<<x_actual+1<<endl;
    }else{
        file<<"N"<<x_actual+y_actual<<"_"<<x_actual+1<<" -> N"<<x_izq+y_izq<<"_"<<x_izq+1<<endl;
        file<<"N"<<x_izq+y_izq<<"_"<<x_izq+1<<" -> N"<<x_actual+y_actual<<"_"<<x_actual+1<<endl;
    }
    if (y_arriba == 0){
        file<<"N"<<x_actual+y_actual<<"_"<<x_actual+1<<" -> C"<<x_arriba+y_arriba<<endl;
        file<<"C"<<x_arriba+y_arriba<<" -> N"<<x_actual+y_actual<<"_"<<x_actual+1<<endl;        
    }else{
        file<<"N"<<x_actual+y_actual<<"_"<<x_actual+1<<" -> N"<<x_arriba+y_arriba<<"_"<<x_actual<<endl;
        file<<"N"<<x_arriba+y_arriba<<"_"<<x_actual<<" -> N"<<x_actual+y_actual<<"_"<<x_actual+1<<endl;          
    }
    if (actual->getAbajo() != NULL){
        cuerpo2(file, actual);
    }    
    if( nActual->getDerecha()!= NULL){
        cuerpo(file, (Cabecera*)nActual->getDerecha());
    }
    return;
}
void matriz::cuerpo2(ofstream& file, NodoM* nActual){
    NodoM* actual = nActual->getAbajo();
    int x_izq = actual->getIzquierda()->getPosX();
    int y_izq = actual->getIzquierda()->getPosY();
    int x_arriba = actual->getArriba()->getPosX();
    int y_arriba = actual->getArriba()->getPosY();
    int x_actual = actual->getPosX();
    int y_actual = actual->getPosY();

    file<<"N"<<x_actual+y_actual<<"_"<<x_actual+1<<" [label = \""<<x_actual+y_actual<<"\" width = 1.5 style = filled, fillcolor = bisque1, group = "<<x_actual+1<<" ];"<<endl;
    if (x_izq == 0){
        file<<"N"<<x_actual+y_actual<<"_"<<x_actual+1<<" -> F"<<x_izq+y_izq<<endl;
        file<<"F"<<x_izq+y_izq<<" -> N"<<x_actual+y_actual<<"_"<<x_actual+1<<endl;
    }else{
        file<<"N"<<x_actual+y_actual<<"_"<<x_actual+1<<" -> N"<<x_izq+y_izq<<"_"<<x_izq+1<<endl;
        file<<"N"<<x_izq+y_izq<<"_"<<x_izq+1<<" -> N"<<x_actual+y_actual<<"_"<<x_actual+1<<endl;
    }
    if (y_arriba == 0){
        file<<"N"<<x_actual+y_actual<<"_"<<x_actual+1<<" -> C"<<x_arriba+y_arriba<<endl;
        file<<"C"<<x_arriba+y_arriba<<" -> N"<<x_actual+y_actual<<"_"<<x_actual+1<<endl;        
    }else{
        file<<"N"<<x_actual+y_actual<<"_"<<x_actual+1<<" -> N"<<x_arriba+y_arriba<<"_"<<x_actual+1<<endl;
        file<<"N"<<x_arriba+y_arriba<<"_"<<x_actual+1<<" -> N"<<x_actual+y_actual<<"_"<<x_actual+1<<endl;          
    }
    if (actual->getAbajo() != NULL){
        cuerpo2(file, actual);
    }
    return;
}
void matriz::escribirColumnas(ofstream& file, Cabecera* nActual, bool validar){
    int c_actual = nActual->getPosX();
    if (validar){
        file<<"{ rank = same; Matriz;";
    }
    file<<"C"<<c_actual<<";";
    if (nActual->getDerecha() != NULL){
        escribirColumnas(file, (Cabecera*)nActual->getDerecha(),false);
        return;
    }
    file<<"}"<<endl;
    return;
}
void matriz::escribirGrupos(ofstream& file, NodoM* nActual){
    int y_actual = nActual->getPosY();
    file<<"{ rank = same; F"<<y_actual<<";";
    if (nActual->getDerecha()!= NULL){
        escribirGrupos2(file, nActual->getDerecha());
    }
    file<<"}"<<endl;
    if (nActual->getAbajo()!=NULL){
        escribirGrupos(file, nActual->getAbajo());
    }
    return;
}
void matriz::escribirGrupos2(ofstream& file, NodoM* nActual){
    int y_actual = nActual->getPosY();
    int x_actual = nActual->getPosX();

    file<<" N"<<y_actual+x_actual<<"_"<<x_actual+1<<";";
        if (nActual->getDerecha()!=NULL){
                escribirGrupos2(file, nActual->getDerecha());
                return;
        }else{
            return;
        }
    return;
}

void matriz::destruirX(NodoM* cabeza){
    if (cabeza->getDerecha()){
        destruirX(cabeza->getDerecha());
    }
    if (cabeza->getAbajo()){
        destruirX(cabeza->getAbajo());
    }
    if (cabeza->getArriba()){
        cabeza->getArriba()->setAbajo(NULL);
    }
    if (cabeza->getIzquierda()){
        cabeza->getIzquierda()->setDerecha(NULL);
    }    
    delete cabeza;
    return;
}

void matriz::destruirY(NodoM* cabeza){
    if (cabeza->getAbajo()){
        destruirX(cabeza->getAbajo());
    }
    if (cabeza->getArriba()){
        cabeza->getArriba()->setAbajo(NULL);
    }
    delete cabeza;
    return;        
}