#include "listaSimple.h"
#include <iostream> 
#include <string> 

using namespace std;

int main(){
    string nombre;
    int eleccion,carnet = 0;
    listaSimple* lista = new listaSimple(); 
    nodo* l = new nodo("joel",1);    
    lista->push(l);
    nodo* m = new nodo("manuel",2);    
    lista->push(m); 
    nodo* o = new nodo("marta",3);    
    lista->push(o);  

    while (eleccion != 4){
        cout<<"---------------------- \n";
        cout<<"|         Menu       |"<<endl;
        cout<<"|1) Ingresar alumno  | \n";
        cout<<"|2) Buscar alumno    | \n";
        cout<<"|3) Eliminar alumno  | \n";
        cout<<"|4) Salir            | \n";
        cout<<"---------------------- \n";
        
        cout<<"Ingrese una opcion \n";
        cin>>eleccion;
        switch(eleccion){
            case 1:
            {
                cout<<"Ingrese el nombre del alumno: \n";
                cin.ignore();
                getline(cin,nombre);
                cout<<"Ingrese el carnet del alumno: \n";
                cin>>carnet;  
                nodo* n = new nodo(nombre,carnet);    
                lista->push(n);            
            }
            break;

            case 2:
            {
                cout<<"Ingrese el carnet del alumno: \n";
                cin>>carnet; 
                lista->show(carnet);
            }

                break;
            case 3:
            {
                cout<<"Ingrese el carnet del alumno: \n";
                cin>>carnet; 
                lista->pop(carnet);
            }

                break;
            case 4:
            {
                
            }
                break;
            default:
            {
                
            }
                break;
        }
    }
    return 0;
}