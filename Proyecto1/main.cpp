
#include <iostream>
#include <string>
#include <fstream>
#include <bits/stdc++.h>
#include <nlohmann/json.hpp>
#include "AVL/avl.h"
#include "libreria/coordenada.h"
#include "lista/lista.h"
#include "lista/nodoL.h"
#include "matriz/matriz.h"
#include "matriz/nodoM.h"
#include "matriz/NodoDM.h"
#include "matriz/Cabecera.h"
#include "libreria/mueble.h"
#include "ABB/arbol.h"
#include "AVL/proyecto.h"
#include "generico/listaGenerica.h"




using json=nlohmann::json;
using namespace std;

int menuPrincipal(){
    arbol* abbGlobal = new arbol();
    avl* avlGlobal = new avl();
    string ruta;
    int seleccion=10;
    while (seleccion != 7){
        system("cls");
        cout<<"******************************"<<endl;
        cout<<"*    1) Ver Proyectos        *"<<endl;
        cout<<"*    2) Editar Proyecto      *"<<endl;
        cout<<"*    3) Cargar Proyecto      *"<<endl;
        cout<<"*    4) Graficar Proyectos   *"<<endl;
        cout<<"*    5) Cargar Librerias     *"<<endl;
        cout<<"*    6) Guardar Proyectos    *"<<endl;
        cout<<"*    7) Salir                *"<<endl;
        cout<<"******************************"<<endl;
        cout<<""<<endl;
        cout<<"Ingrese una opcion para continuar"<<endl;;
            while (true){
                cin>>seleccion;
                if (cin.fail()){
                    cin.clear();
                    cin.ignore();
                    cout<<"Opcion no valida. Intentelo de nuevo"<<endl;
                }else if (seleccion > 7 or seleccion < 0){
                    cin.clear();
                    cin.ignore();
                    cout<<"Opcion no valida. Intentelo de nuevo"<<endl;
                }else{
                    break;
                }
            }
            switch(seleccion){
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    cout<<"Ingrese la ruta del archivo"<<endl;
                    cin>>ruta;

                    break;
                case 4:
                    break;
                case 5:
                    break;
                case 6:
                    break;
                defaul:
                    break;
            }
        system("cls");
    }

    return seleccion;
}

/*
avl* menuProyectos(avl* arbol){
    int contador = 1;
    return arbol;
}
*/


int main(){
    /*arbol* tree = new arbol();
    tree->agregar(1, "Primero", 'A', "Rojo", 0);
    tree->agregar(2, "Primero", 'A', "Rojo", 0);
    tree->agregar(3, "Primero", 'A', "Rojo", 0);
    tree->agregar(4, "Primero", 'A', "Rojo", 0);
    tree->agregar(5, "Primero", 'A', "Rojo", 0);
    tree->preOrden(tree->getRaiz());
    tree->destruir(tree->getRaiz());
    delete tree;


    avl* t = new avl();
    t->insertar("primero",1);
    t->insertar("primero",2);
    t->insertar("primero",3);
    t->insertar("primero",4);
    t->insertar("primero",5);
    t->preOrden(t->getRaiz());
    t->borrar(t->getRaiz());
    delete t;
    */

   /*
   coordenada* uno = new coordenada(1,1);
   coordenada* dos = new coordenada(2,2);
   coordenada* tres = new coordenada(3,3);
   nodoL* nUno = new nodoL(uno);
   nodoL* nDos = new nodoL(dos);
   nodoL* nTres = new nodoL(tres);
   lista *l = new lista();
   l->add(nUno);
   l->add(nDos);
   l->add(nTres);
   l->imprimir(l->getPrimero());
   l->destruir(l->getPrimero());
   delete l;
   matriz* m = new matriz();
   mueble* mUno = new mueble(1, "uno", 'A', "primero", 0);
   mueble* mDos = new mueble(2, "dos", 'B', "segundo", 0);
   mueble* mTres = new mueble(3, "tres", 'C', "tercero", 0);
   mUno->agregarCoordenada(1,1);
   mUno->agregarCoordenada(2,2);
   mDos->agregarCoordenada(1,1);
   mDos->agregarCoordenada(2,2);
   mTres->agregarCoordenada(1,1);
   mTres->agregarCoordenada(2,2);
   mUno->getCoordenadas()->imprimir(mUno->getCoordenadas()->getPrimero());
   delete m;
   delete mUno;
   delete mDos;
   delete mTres;
   */

  /*
   string cadena = "hola mundo como estan 10";
   int n = cadena.length();
   int sumatoria = 0;
   char char_array[n+1];
   strcpy(char_array,cadena.c_str());
   for (int i=0;i<n;i++){
       cout<<char_array[i]<<endl;
       if (int(char_array[i])!=32){
           sumatoria = sumatoria+int(char_array[i]);
       }
   }
   cout<<"El nombre es: "<<sumatoria<<endl;
   */

  //Impresión de la matriz dispersa
    /*
    mueble* mUno = new mueble(1, "uno", 'A', "primero", 0);
    mueble* mDos = new mueble(2, "dos", 'B', "segundo", 0);
    mueble* mTres = new mueble(3, "tres", 'C', "tercero", 0);
    mueble* m4 = new mueble(4, "tres", 'C', "tercero", 0);
    mueble* m5 = new mueble(5, "tres", 'C', "tercero", 0);
    mueble* m6 = new mueble(6, "tres", 'C', "tercero", 0);
    NodoDM* dmUno = new NodoDM(mUno);
    NodoDM* dmDos = new NodoDM(mDos);
    NodoDM* dmTres = new NodoDM(mTres);
    NodoDM* dm4 = new NodoDM(m4);
    NodoDM* dm5 = new NodoDM(m5);
    NodoDM* dm6 = new NodoDM(m6);
    NodoDM* dm7 = new NodoDM(m6);
    NodoDM* dm8 = new NodoDM(m6);
    NodoDM* dm9 = new NodoDM(m6);
    dmUno->setPosX(1);
    dmUno->setPosY(1);
    dmDos->setPosX(2);
    dmDos->setPosY(2);
    dmTres->setPosX(3);
    dmTres->setPosY(3);
    dm4->setPosX(1);
    dm4->setPosY(2);
    dm5->setPosX(2);
    dm5->setPosY(3);
    dm6->setPosX(5);
    dm6->setPosY(3);
    dm7->setPosX(5);
    dm7->setPosY(1);
    dm8->setPosX(2);
    dm8->setPosY(6);
    dm9->setPosX(4);
    dm9->setPosY(3);
    matriz* matrix = new matriz();
    matrix->add(dmUno);
    matrix->add(dmDos);
    matrix->add(dmTres);
    matrix->add(dm4);
    matrix->add(dm5);
    matrix->add(dm6);
    matrix->add(dm7);
    matrix->add(dm8);
    matrix->add(dm9);
    matrix->imprimir(1,1);
    */
    //Impresión de árbol AVL
    /*
    proyecto* p1 = new proyecto("proyecto1");
    proyecto* p2 = new proyecto("proyecto2");
    proyecto* p3 = new proyecto("proyecto3");
    proyecto* p4 = new proyecto("proyecto4");
    proyecto* p5 = new proyecto("proyecto5");
    proyecto* p6 = new proyecto("proyecto6");
    proyecto* p7 = new proyecto("proyecto7");
    avl* lista = new avl();
    lista->insertar(p1->getNombre(),p1->getId());
    lista->insertar(p2->getNombre(),p2->getId());
    lista->insertar(p3->getNombre(),p3->getId());
    lista->insertar(p4->getNombre(),p4->getId());
    lista->insertar(p5->getNombre(),p5->getId());
    lista->insertar(p6->getNombre(),p6->getId());
    lista->insertar(p7->getNombre(),p7->getId());
    listaGenerica<nProyecto>* nl = new listaGenerica<nProyecto>();
    nl = lista->getCopia();
    nl->imprimirCopia(nl->getPrimero());
    cout<<"Copias"<<endl;
    */


   //Impresión de arbol ABB
    /*
   mueble* m1 = new mueble(1, "mueble1",'a',"abc", 0);
   mueble* m2 = new mueble(2, "mueble2",'b',"abd", 0);
   mueble* m3 = new mueble(3, "mueble3",'c',"abe", 0);
   mueble* m4 = new mueble(4, "mueble4",'d',"abf", 0);
   mueble* m5 = new mueble(5, "mueble5",'e',"abg", 0);
   mueble* m6 = new mueble(6, "mueble6",'f',"abh", 0);
   mueble* m7 = new mueble(7, "mueble7",'g',"abi", 0);
   mueble* m8 = new mueble(8, "mueble8",'h',"abj", 0);
   mueble* m9 = new mueble(9, "mueble9",'i',"abk", 0);
   arbol* abb = new arbol();
   abb->agregar(m8);
   abb->agregar(m2);
   abb->agregar(m6);
   abb->agregar(m4);
   abb->agregar(m5);
   abb->agregar(m3);
   abb->agregar(m7);
   abb->agregar(m1);
   abb->agregar(m9);
   abb->imprimir(1,1);
   abb->destruir(abb->getRaiz());
   delete abb;
   */
    string ruta = "./Archivos/Librerias.json";
    ifstream entrada(ruta);
    json archivo;
    entrada>>archivo;
    cout<<archivo["Libreria"][0]["color"]<<endl;
    //int seleccion = menuPrincipal();
    //cout<<seleccion<<endl;
    return 0;
}






