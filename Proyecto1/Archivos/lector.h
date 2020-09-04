#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <iostream>
#include <string>
#include "libreria/coordenada.h"
#include "lista/lista.h"
#include "lista/nodoL.h"
#include "matriz/matriz.h"
#include "matriz/nodoM.h"
#include "matriz/NodoDM.h"
#include "matriz/Cabecera.h"
#include "libreria/mueble.h"
#include "ABB/arbol.h"
#include "AVL/avl.h"
#include "AVL/proyecto.h"
#include <sstream>

using namespace std;
using json=nlohmann::json;

class lector
{
private:
    string ruta;
    arbol* abb_global;
    avl* avl_global;
public:
    lector(arbol* abb_global, avl* avl_global);
    ~lector();
    void cargarLibreria(json archivo, arbol* abb);
    void cargarNivel(string ruta);
    void cargarProyecto(string ruta);
    void setRuta(string ruta);
    void cargar(string ruta);
};
