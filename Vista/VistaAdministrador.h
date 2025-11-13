#ifndef VISTA_ADMINISTRADOR_H
#define VISTA_ADMINISTRADOR_H

#include <iostream>
using namespace std;

class VistaAdministrador {
public:
    // Menú principal del administrador
    void mostrarMenuAdministrador();

    // Métodos visuales del administrador
    void mostrarReporteInventario();
    void mostrarReporteStock();
    void advertenciaExportacion();

    // Métodos heredados de la vista general anterior
    int obtenerOpcionMenu();
    void mostrarResumenGeneral();
    void mostrarReporteGeneral();
};

#endif
