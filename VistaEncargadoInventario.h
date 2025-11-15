#ifndef VISTA_ENCARGADO_INVENTARIO_H
#define VISTA_ENCARGADO_INVENTARIO_H

#include <iostream>
#include <map>
#include "Ingredientes.h"

class VistaEncargadoInventario {
public:
    void mostrarMenuEncargadoInventario();
    void mostrarInventarioIngredientes(const std::map<Ingredientes, double>& inventario);
    void mostrarAlertasReposicion();
    bool advertenciaEliminacionIngrediente();
    void ingredienteNegativo();
    int obtenerOpcionMenu();
};

#endif // VISTA_ENCARGADO_INVENTARIO_H
