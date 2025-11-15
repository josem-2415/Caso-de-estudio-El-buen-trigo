#ifndef VISTA_ADMINISTRADOR_H
#define VISTA_ADMINISTRADOR_H

#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include "Panes.h"
#include "Ingredientes.h"

class VistaAdministrador {
public:
    // Menú principal del administrador
    void mostrarMenuAdministrador();

    // Métodos visuales del administrador
    void mostrarReporteInventario(const std::map<Ingredientes, double>& inventario) const;
    void mostrarReporteStock(const std::vector<Panes>& stock);
    void escribirReporteStock(const std::vector<Panes>& stock);

    // Métodos heredados de la vista general anterior
    int obtenerOpcionMenu();
    void mostrarReporteGeneral();
};

#endif // VISTA_ADMINISTRADOR_H
