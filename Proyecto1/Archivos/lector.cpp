#include "lector.h"

lector::lector(arbol* abb_global, avl* avl_global)
{
    this->abb_global = abb_global;
    this->avl_global = avl_global;
}

lector::~lector()
{
}

void lector::cargarLibreria(json archivo, arbol* abb){
    string color,s_id,nombre,s_letra;
    char letra, stream_letra[1];
    int x,y,id;
    int cCoordenada = 0;
    int tamano = archivo["Libreria"].size();
    int tamano2;
    for (int i=0;i<=tamano-1;i++){
        color = archivo["Libreria"][i]["color"];
        //Obtener ID ---------------------------
        s_id = archivo["Libreria"][i]["identificador"];
        stringstream id_stream(s_id); //Conversión de string a int
        id_stream>>id;
        //Obtener letra ---------------------------
        s_letra = archivo["Libreria"][i]["letra"];
        strcpy(stream_letra,s_letra.c_str()); //Conversión de string a char
        letra = stream_letra[0];
        //Obtener nombre ---------------------------
        nombre = archivo["Libreria"][i]["nombre"];

        mueble* nuevo = new mueble(id, nombre, letra, color, 0); // Crear mueble

        //Obtener coordenadas ---------------------------
        tamano2 = archivo["Libreria"][i]["puntos"].size();

        for (int j=0;j<tamano2-1;j++){
            x = archivo["Libreria"][i]["puntos"]["x"];
            y = archivo["Libreria"][i]["puntos"]["y"];
            nuevo->agregarCoordenada(x,y,cCoordenada);
            cCoordenada++;
        }      
        cCoordenada = 0;
        abb->agregar(nuevo); //Agregar a la libreria global
    }
}

void lector::cargar(string ruta){
    this->ruta = ruta;
    ifstream reader(ruta);
    json archivo;
    reader>>archivo;
    reader.close();
    if (archivo["proyectos"]){

    }
    else if (archivo["niveles"]){

    }else if (archivo["Libreria"]){

    }
}

void lector::setRuta(string ruta){
    this->ruta = ruta;
}

