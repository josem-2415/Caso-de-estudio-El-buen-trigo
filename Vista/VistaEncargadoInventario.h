#ifndef VISTA_ENCARGADO_INVENTARIO_H
#define VISTA_ENCARGADO_INVENTARIO_H

#include <iostream>

class VistaEncargadoInventario {
public:
    void mostrarMenuEncargadoInventario();
    void mostrarInventarioIngredientes();
    void mostrarAlertasReposicion();
    bool advertenciaEliminacionIngrediente();
    void ingredienteNegativo();
};

#endif // VISTA_ENCARGADO_INVENTARIO_H
