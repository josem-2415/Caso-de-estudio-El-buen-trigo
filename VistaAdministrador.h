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

    // Métodos heredados de la vista general anterior
    int obtenerOpcionMenu();
};

#endif // VISTA_ADMINISTRADOR_H
