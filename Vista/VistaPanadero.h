#ifndef VISTA_PANADERO_H
#define VISTA_PANADERO_H

#include <iostream>
using namespace std;

class VistaPanadero {
public:
    void mostrarMenuPanadero();
    string obtenerNombreReceta();
    void obtenerDatosRegistroReceta();
    int obtenerCantidadProduccion();
    void mostrarInventarioPanes();
    void mostrarInventarioRecetas();
    void mostrarAdvertenciasProduccion();
};

#endif
