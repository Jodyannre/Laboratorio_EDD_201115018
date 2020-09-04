
#include "../../AVL/proyecto.h"

class nProyecto
{
private:
    nProyecto* sig;
    nProyecto* ant;
    proyecto* dato;
    int valor;
public:
    nProyecto(proyecto* dato);
    ~nProyecto();
    nProyecto* getSig();
    nProyecto* getAnt();
    int getValor();
    void setSig(nProyecto* n);
    void setAnt(nProyecto* n);
    void setDato(proyecto* dato);
    void setValor(int v);
    proyecto* getDato();
};
