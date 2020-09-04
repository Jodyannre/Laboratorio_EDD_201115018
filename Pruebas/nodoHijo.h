#include "nodoGenerico.h"

class nodoHijo: public nodoGenerico
{
private:
    int dato;
public:
    nodoHijo(int dato);
    int getDato();
    ~nodoHijo();
};
