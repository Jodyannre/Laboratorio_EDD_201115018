#include "ListaC.h"

    void add(ListaC* l,NodoC* nuevo){
    if(l->head==NULL){
        l->head=nuevo;
    }else if(nuevo->val<=l->head->val){
        nuevo->derecha=l->head;
        l->head->izquierda=nuevo;
        l->head=nuevo;
    }else{
        NodoC* aux=l->head;
        while(aux->derecha!=NULL){
            if(aux->val>nuevo->val){
                    NodoC* ant=aux->izquierda;
                    ant->derecha=nuevo;
                    nuevo->izquierda=ant;
                    nuevo->derecha=aux;
                    aux->izquierda=nuevo;
                    return;
                }else if(nuevo->val<=aux->derecha->val){
                    NodoC *siguiente=aux->derecha;
                    aux->derecha=nuevo;
                    nuevo->derecha=aux;
                    nuevo->derecha=siguiente;
                    siguiente->izquierda=nuevo;
                    return;
                }
            aux=aux->derecha;
        }
        aux->derecha=nuevo;
        nuevo->izquierda=aux;
    }
}

void Liberar(ListaC* l){
    NodoA* aux=l->head;
    NodoA* tmp;
    while(aux!=NULL){
        tmp=aux->derecha;
        free(aux);
        aux=tmp;
    }
}

void imprimir(ListaC* l){
    NodoA* aux=l->head;
    while(aux!=NULL){
        printf("El valor es %i \n",aux->val);
        aux=aux->derecha;
    }
}
ListaC* nuevaLista(){
    ListaC* nueva=(ListaC*) malloc(sizeof(ListaC));
    nueva->head=NULL;
    return nueva;
}
void generar(ListaC* l){
    FILE * fp;
    fp=fopen("./codigo.txt","w");
    if(fp==NULL){
        printf("Error");
        return;
    }
    char cad[1024];
    sprintf(cad,"digraph G{ \n edge[arrowhead=vee];\n node[shape=Mdiamond, color=green, style=filled];\n");
    fputs(cad,fp);
    NodoC* aux;
    aux=l->head;
    guardarRecursivo(aux,fp,cad);
    sprintf(cad,"}\n");
    fputs(cad,fp);
    fclose(fp);
}

void guardarRecursivo(NodoC* aux,FILE* fp,char c[]){
    if(aux==NULL){
        return;
    }else{
        if(aux->derecha!=NULL){
            
            sprintf(c,"node%p[label=\"%i\"]\n",&(*aux),aux->val);
            fputs(c,fp);
            guardarRecursivo(aux->derecha,fp,c);
            sprintf(c,"node%p->node%p;\n node%p->node%p;\n",&(*aux),&(*aux->derecha),&(*aux->derecha),&(*aux));
            fputs(c,fp);
        }else{
            sprintf(c,"node%p[label=\"%i\"]\n",&(*aux),aux->val);
            fputs(c,fp);
        }
    }
}

NodoC* getNodo(int posicion, ListaC* l){
    NodoC* aux = l->head;
    NodoC* error = newNodoC(-1000);
    int pos = 0;
    while (aux != NULL){
        if (pos == posicion){
            return aux;
        }
        else{
            pos += 1;
            aux = aux->derecha;
        }
    }
    return error;   
}

void eliminar(int posicion, ListaC* l){
    NodoC* actual = getNodo(posicion,l);
    NodoC* izq = actual->izquierda;
    NodoC* der = actual->derecha;

    if (actual->val != -1000){
        if (izq == NULL && der == NULL){  //Es el único
            free(actual);
        }
        else if (izq == NULL){   //Es head
            l->head = der;
            der->izquierda = NULL;
            free(actual);
        }
        else if (der == NULL){   //Es el último
            izq->derecha = NULL;
            free(actual);
        }
        else{
            izq->derecha = der;
            der->izquierda = izq;
            free(actual);
        }
    }else{
        printf("Posicion inexistente. \n");
    }


}
