#ifndef VISTA_PANADERO_H
#define VISTA_PANADERO_H

#include <iostream>
#include <string>
#include <map>
#include "Ingredientes.h"
#include "Recetario.h"

class VistaPanadero {
private:
    Recetario recetas;
public:
    void mostrarMenuPanadero();
    int obtenerOpcionMenu();
    std::string obtenerNombreReceta();
    int obtenerCantidadIngredientes();
    std::map<Ingredientes, double> obtenerIngredientesReceta();
    void obtenerDatosRegistroReceta();
    int obtenerCantidadProduccion();
    void mostrarInventarioRecetas();
    void mostrarAdvertenciasProduccion();
};

#endif // VISTA_PANADERO_H 
