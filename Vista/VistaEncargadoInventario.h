#ifndef VISTA_INVENTARIO_H
#define VISTA_INVENTARIO_H

#include <iostream>
using namespace std;

class VistaInventario {
public:
    void mostrarMenuInventario();
    void mostrarInventarioIngredientes();
    void mostrarAlertasReposicion();
    bool advertenciaEliminacionIngrediente();
    void stockNegativo();
};

#endif
