#include <stdio.h>
#include <string.h>
#include <iostream>
#include <conio.h>
#include <cctype>
#include <limits>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int main(){

    int eleccion;
    int prueba;
    //Menu inicial--caratula
    cout<<"***************************************"<<endl;
    cout<<"*USAC                                 *"<<endl;
    cout<<"*Estructura de datos                  *"<<endl;
    cout<<"*Seccion A                            *"<<endl;
    cout<<"*Joel Estuardo Rodriguez Santos       *"<<endl;
    cout<<"*201115018                            *"<<endl;
    cout<<"***************************************"<<endl;
    _getch(); //Espera de una tecla para continuar

     //Menu opciones
     while(true){
        system("cls");
        cout<<"***************************************"<<endl;
        cout<<"*Ver proyectos                        *"<<endl;
        cout<<"*Editar proyectos                     *"<<endl;
        cout<<"*Cargar proyectos                     *"<<endl;
        cout<<"*Graficar proyectos                   *"<<endl;
        cout<<"*Guardar proyectos                    *"<<endl;
        cout<<"*Cargar librerias                     *"<<endl;
        cout<<"*Salir                                *"<<endl;
        cout<<"***************************************"<<endl;
        cout<<"Ingrese una opcion para continuar\n";
        cin>>eleccion;
        if(cin.fail()) { 
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        switch(eleccion){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                return 0;
                break;
            default:
                system("cls");
                cout<<"Opcion no disponible, ingrese una opcion disponible para continuar\n";
                _getch();
                break;
        }
     }
    return 0;
}



